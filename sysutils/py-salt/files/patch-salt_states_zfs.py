--- salt/states/zfs.py.orig	2021-03-23 17:07:44 UTC
+++ salt/states/zfs.py
@@ -397,8 +397,10 @@ def _dataset_present(
         volume_size = __utils__["zfs.from_size"](volume_size)
     if properties:
         properties = __utils__["zfs.from_auto_dict"](properties)
+        propnames = ",".join(properties.keys())
     elif properties is None:
         properties = {}
+        propnames = ""
 
     ## log configuration
     log.debug(
@@ -434,7 +436,12 @@ def _dataset_present(
     if __salt__["zfs.exists"](name, **{"type": dataset_type}):
         ## NOTE: fetch current volume properties
         properties_current = __salt__["zfs.get"](
-            name, type=dataset_type, fields="value", depth=0, parsable=True,
+            name,
+            properties=propnames,
+            type=dataset_type,
+            fields="value",
+            depth=0,
+            parsable=True,
         ).get(name, OrderedDict())
 
         ## NOTE: add volsize to properties
