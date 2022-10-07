--- salt/minion.py.orig	2022-08-25 15:07:52 UTC
+++ salt/minion.py
@@ -1361,6 +1361,9 @@ class Minion(MinionBase):
             self.opts, self.timeout, self.safe, failed
         )
 
+        # Create a single ipc channel that will aggregate job completion results
+        self.ipc_job_completion_channel = self._create_job_completion_channel()
+
         # a long-running req channel
         self.req_channel = salt.transport.client.AsyncReqChannel.factory(
             self.opts, io_loop=self.io_loop
@@ -1380,6 +1383,14 @@ class Minion(MinionBase):
         yield reply_func(payload)
         self.payload_ack.notify()
 
+    @salt.ext.tornado.gen.coroutine
+    def handle_job_completion_payload(self, payload, reply_func):
+        yield self.req_channel.send(
+            payload,
+            timeout=60,  # this is the hard-coded timeout used throughout this file
+            tries=self.opts["return_retry_tries"],
+        )
+
     # TODO: better name...
     @salt.ext.tornado.gen.coroutine
     def _post_master_init(self, master):
@@ -1497,6 +1508,49 @@ class Minion(MinionBase):
             )
             self.schedule.delete_job(master_event(type="failback"), persist=True)
 
+    def _get_job_completion_ipc_path(self):
+        """
+        Get IPC path (TCP port or UXD socket) for IPC channel used to forward minion job completion results from spawned
+        minion job processes to the parent process
+        :return:
+        """
+        if self.opts["ipc_mode"] == "tcp":
+            # try to find the port and fallback to something if not configured
+            uxd_path_or_tcp_port = int(
+                self.opts.get("tcp_job_completion_port", self.opts["tcp_pub_port"] + 1)
+            )
+        else:
+            uxd_path_or_tcp_port = os.path.join(
+                self.opts["sock_dir"],
+                "job_completion_minion-{}.ipc".format(self.opts["id"]),
+            )
+
+        return uxd_path_or_tcp_port
+
+    def _create_job_completion_channel(self):
+        """
+        Channel that will forward/proxy results from spawned minion processes to the parent process that will,
+        in turn, use the long-running req channel
+        :return:
+        """
+        job_completion_ipc_path = self._get_job_completion_ipc_path()
+        log.trace(
+            "Job completion IPCMessageServer will listen on [%s]",
+            job_completion_ipc_path,
+        )
+
+        # Create a single ipc channel that will aggregate job completion results
+        ipc_job_completion_channel = salt.transport.ipc.IPCMessageServer(
+            job_completion_ipc_path,
+            io_loop=self.io_loop,
+            payload_handler=self.handle_job_completion_payload,
+        )
+
+        with salt.utils.files.set_umask(0o177):
+            ipc_job_completion_channel.start()
+
+        return ipc_job_completion_channel
+
     def _prep_mod_opts(self):
         """
         Returns a copy of the opts with key bits stripped out
@@ -1594,6 +1648,7 @@ class Minion(MinionBase):
         return functions, returners, errors, executors
 
     def _send_req_sync(self, load, timeout):
+
         if self.opts["minion_sign_messages"]:
             log.trace("Signing event to be published onto the bus.")
             minion_privkey_path = os.path.join(self.opts["pki_dir"], "minion.pem")
@@ -1602,12 +1657,17 @@ class Minion(MinionBase):
             )
             load["sig"] = sig
 
-        with salt.utils.event.get_event(
-            "minion", opts=self.opts, listen=False
-        ) as event:
-            return event.fire_event(
-                load, "__master_req_channel_payload", timeout=timeout
+        with salt.channel.client.PushChannel.factory(
+            self._get_job_completion_ipc_path(),
+            io_loop=self.io_loop,
+        ) as channel:
+            channel.connect()
+            # TODO: IPC implementation does not support timeout/retries count.
+            # DW: we do not really need retries/timeout here because IPC is reliable enough
+            res = channel.send(
+                load, timeout=timeout, tries=self.opts["return_retry_tries"]
             )
+            return res
 
     @salt.ext.tornado.gen.coroutine
     def _send_req_async(self, load, timeout):
@@ -1619,13 +1679,15 @@ class Minion(MinionBase):
             )
             load["sig"] = sig
 
-        with salt.utils.event.get_event(
-            "minion", opts=self.opts, listen=False
-        ) as event:
-            ret = yield event.fire_event_async(
-                load, "__master_req_channel_payload", timeout=timeout
+        with salt.channel.client.AsyncPushChannel.factory(
+            self._get_job_completion_ipc_path(),
+            io_loop=self.io_loop,
+        ) as channel:
+            # TODO: IPC does not support timeout/retries count
+            ret = yield channel.send(
+                load, timeout=timeout, tries=self.opts["return_retry_tries"]
             )
-            raise salt.ext.tornado.gen.Return(ret)
+        raise salt.ext.tornado.gen.Return(ret)
 
     def _fire_master(
         self,
@@ -2695,7 +2757,7 @@ class Minion(MinionBase):
         elif tag.startswith("__master_req_channel_payload"):
             yield self.req_channel.send(
                 data,
-                timeout=self._return_retry_timer(),
+                timeout=60,  # this is the hard-coded timeout used throughout this file
                 tries=self.opts["return_retry_tries"],
             )
         elif tag.startswith("pillar_refresh"):
