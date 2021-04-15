--- iocage_lib/ioc_upgrade.py.orig	2019-09-26 07:23:24 UTC
+++ iocage_lib/ioc_upgrade.py
@@ -111,19 +111,25 @@ class IOCUpgrade(iocage_lib.ioc_json.IOCZFS):
         self.__upgrade_check_conf__()
 
         f_rel = f'{self.new_release.rsplit("-RELEASE")[0]}.0'
-        f = 'https://raw.githubusercontent.com/freebsd/freebsd' \
-            f'/release/{f_rel}/usr.sbin/freebsd-update/freebsd-update.sh'
 
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
+                f = 'https://raw.githubusercontent.com/freebsd/freebsd' \
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
                 "--not-running-from-cron", "--currently-running "
@@ -166,7 +172,7 @@ class IOCUpgrade(iocage_lib.ioc_json.IOCZFS):
 
             for _ in range(50): # up to 50 invocations to prevent runaway
                 if os.path.islink(self.freebsd_install_link):
-                    self.__upgrade_install__(tmp.name)
+                    self.__upgrade_install__(fbsd_update)
                 else:
                     break
 
