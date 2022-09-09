--- salt/states/zfs.py.orig	2022-09-09 13:52:33 UTC
+++ salt/states/zfs.py
@@ -462,6 +462,7 @@ def _dataset_present(
             fields="value",
             depth=0,
             parsable=True,
+            source="default,inherited,local,none,received",
         ).get(name, OrderedDict())
 
         ## NOTE: build list of properties to update
