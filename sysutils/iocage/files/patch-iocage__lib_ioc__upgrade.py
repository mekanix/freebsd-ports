--- iocage_lib/ioc_upgrade.py.orig	2024-09-20 06:45:27 UTC
+++ iocage_lib/ioc_upgrade.py
@@ -104,19 +104,25 @@ class IOCUpgrade:
         self.__upgrade_check_conf__()
 
         f_rel = f'{self.new_release.rsplit("-RELEASE")[0]}'
-        f = 'https://raw.githubusercontent.com/freebsd/freebsd-src' \
-            f'/releng/{f_rel}/usr.sbin/freebsd-update/freebsd-update.sh'
 
         tmp = None
         try:
-            tmp = tempfile.NamedTemporaryFile(delete=False)
-            with urllib.request.urlopen(f) as fbsd_update:
-                tmp.write(fbsd_update.read())
-            tmp.close()
-            os.chmod(tmp.name, 0o755)
+            fetched_update = f"{self.iocroot}/releases/{self.new_release}" \
+                    f"/root/usr/sbin/freebsd-update"
+            if os.path.isfile(fetched_update):
+                fbsd_update = fetched_update
+            else:
+                f = 'https://raw.githubusercontent.com/freebsd/freebsd-src' \
+                    f'/releng/{f_rel}/usr.sbin/freebsd-update/freebsd-update.sh'
+                tmp = tempfile.NamedTemporaryFile(delete=False)
+                with urllib.request.urlopen(f) as http:
+                    tmp.write(http.read())
+                tmp.close()
+                os.chmod(tmp.name, 0o755)
+                fbsd_update = tmp.name
 
             fetch_cmd = [
-                tmp.name, "-b", self.path, "-d",
+                fbsd_update, "-b", self.path, "-d",
                 f"{self.path}/var/db/freebsd-update/", "-f",
                 f"{self.path}/etc/freebsd-update.conf",
                 "--not-running-from-cron", "--currently-running",
@@ -159,7 +165,7 @@ class IOCUpgrade:
 
             for _ in range(50): # up to 50 invocations to prevent runaway
                 if os.path.islink(self.freebsd_install_link):
-                    self.__upgrade_install__(tmp.name)
+                    self.__upgrade_install__(fbsd_update)
                 else:
                     break
 
