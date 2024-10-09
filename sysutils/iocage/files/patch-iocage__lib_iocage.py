--- iocage_lib/iocage.py.orig	2024-09-20 06:45:27 UTC
+++ iocage_lib/iocage.py
@@ -1865,7 +1865,7 @@ class IOCage:
             self.jail = jail
             self.update(pkgs)
 
-    def update(self, pkgs=False):
+    def update(self, pkgs=False, server=None, verify=True):
         """Updates a jail to the latest patchset."""
         if self._all:
             self.update_all(pkgs)
@@ -1988,6 +1988,8 @@ class IOCage:
             try:
                 ioc_fetch.IOCFetch(
                     release,
+                    server,
+                    verify=verify,
                     callback=self.callback
                 ).fetch_update(*params)
             finally:
