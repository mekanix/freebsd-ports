--- salt/minion.py.orig	2022-10-19 14:39:01 UTC
+++ salt/minion.py
@@ -2917,7 +2917,7 @@ class Minion(MinionBase):
                             1
                         ],
                     )
-            self._return_pub(data, ret_cmd="_return", sync=False)
+            self._fire_master(data, tag, sync=False)
         elif tag.startswith("_salt_error"):
             if self.connected:
                 log.debug("Forwarding salt error event tag=%s", tag)
