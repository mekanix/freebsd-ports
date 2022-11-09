--- salt/grains/extra.py.orig	2022-11-09 22:07:16 UTC
+++ salt/grains/extra.py
@@ -81,14 +81,23 @@ def __secure_boot(efivars_dir):
 
 def uefi():
     """Populate UEFI grains."""
-    efivars_dir = next(
-        filter(os.path.exists, ["/sys/firmware/efi/efivars", "/sys/firmware/efi/vars"]),
-        None,
-    )
-    grains = {
-        "efi": bool(efivars_dir),
-        "efi-secure-boot": __secure_boot(efivars_dir) if efivars_dir else False,
-    }
+    if salt.utils.platform.is_freebsd():
+        grains = {
+            "efi": os.path.exists("/dev/efi"),
+            # Needs a contributor with a secure boot system to implement this
+            # part.
+            "efi-secure-boot": False
+        }
+    else:
+        # Works on Linux and Apple ?
+        efivars_dir = next(
+            filter(os.path.exists, ["/sys/firmware/efi/efivars", "/sys/firmware/efi/vars"]),
+            None,
+        )
+        grains = {
+            "efi": bool(efivars_dir),
+            "efi-secure-boot": __secure_boot(efivars_dir) if efivars_dir else False,
+        }
 
     return grains
 
