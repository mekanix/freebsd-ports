--- iocage_lib/iocage.py.orig	2021-02-26 01:20:38 UTC
+++ iocage_lib/iocage.py
@@ -1941,7 +1941,7 @@ class IOCage(ioc_json.IOCZFS):
             self.jail = jail
             self.update(pkgs)
 
-    def update(self, pkgs=False):
+    def update(self, pkgs=False, server=None, verify=True):
         """Updates a jail to the latest patchset."""
         if self._all:
             self.update_all(pkgs)
@@ -2063,6 +2063,8 @@ class IOCage(ioc_json.IOCZFS):
             params = [] if is_basejail else [True, uuid]
             ioc_fetch.IOCFetch(
                 release,
+                server,
+                verify=verify,
                 callback=self.callback
             ).fetch_update(*params)
 
