--- salt/states/zfs.py.orig	2021-03-23 17:07:44 UTC
+++ salt/states/zfs.py
@@ -346,10 +346,10 @@ def hold_present(name, snapshot, recursive=False):
 def _dataset_present(
     dataset_type,
     name,
+    properties,
     volume_size=None,
     sparse=False,
     create_parent=False,
-    properties=None,
     cloned_from=None,
 ):
     """
@@ -393,12 +393,14 @@ def _dataset_present(
         dataset_type = "filesystem"
 
     ## ensure properties are zfs values
+    if properties is None:
+        properties = {}
+    properties = __utils__["zfs.from_auto_dict"](properties)
     if volume_size:
+        ## NOTE: add volsize to properties
         volume_size = __utils__["zfs.from_size"](volume_size)
-    if properties:
-        properties = __utils__["zfs.from_auto_dict"](properties)
-    elif properties is None:
-        properties = {}
+        properties.update({"volsize": volume_size})
+    propnames = ",".join(properties.keys())
 
     ## log configuration
     log.debug(
@@ -431,16 +433,20 @@ def _dataset_present(
 
     ## ensure dataset is in correct state
     ## NOTE: update the dataset
-    if __salt__["zfs.exists"](name, **{"type": dataset_type}):
+    exists = __salt__["zfs.exists"](name, **{"type": dataset_type})
+    if exists and len(properties) == 0:
+        ret["comment"] = "{} {} is uptodate".format(dataset_type, name)
+    elif exists and len(properties) > 0:
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
 
-        ## NOTE: add volsize to properties
-        if volume_size:
-            properties["volsize"] = volume_size
-
         ## NOTE: build list of properties to update
         properties_update = []
         for prop in properties:
@@ -484,7 +490,7 @@ def _dataset_present(
             ret["comment"] = "{} {} failed to be updated".format(dataset_type, name)
 
     ## NOTE: create or clone the dataset
-    else:
+    elif not exists:
         mod_res_action = "cloned" if cloned_from else "created"
         if __opts__["test"]:
             ## NOTE: pretend to create/clone
@@ -554,8 +560,8 @@ def filesystem_present(name, create_parent=False, prop
     return _dataset_present(
         "filesystem",
         name,
+        properties,
         create_parent=create_parent,
-        properties=properties,
         cloned_from=cloned_from,
     )
 
@@ -603,10 +609,10 @@ def volume_present(
     return _dataset_present(
         "volume",
         name,
+        properties,
         volume_size,
         sparse=sparse,
         create_parent=create_parent,
-        properties=properties,
         cloned_from=cloned_from,
     )
 
