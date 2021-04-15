--- salt/states/pkg.py.orig	2020-06-17 18:05:55 UTC
+++ salt/states/pkg.py
@@ -227,6 +227,10 @@ def _fulfills_version_string(
         the repository without enforcing a re-installation of the package.
         (Only applicable if only one strict version condition is specified E.G. version: 2.0.6~ubuntu3)
     """
+        # stripping "with_origin" dict wrapper
+    if salt.utils.platform.is_freebsd():
+        if isinstance(installed_versions, dict) and 'version' in installed_versions:
+            installed_versions = installed_versions['version']
     version_conditions = _parse_version_string(version_conditions_string)
     for installed_version in installed_versions:
         fullfills_all = True
@@ -754,7 +758,7 @@ def _find_install_targets(
         for key in resolved_latest:
             if not resolved_latest[key]:
                 if key in cur_pkgs:
-                    resolved_latest[key] = cur_pkgs[key][-1]
+                    resolved_latest[key] = cur_pkgs[key]['version'][-1]
                 else:
                     resolved_latest[key] = None
         # Update the desired versions with the ones we resolved
