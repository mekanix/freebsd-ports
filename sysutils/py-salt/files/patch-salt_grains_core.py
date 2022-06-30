--- salt/grains/core.py.orig	2022-06-30 17:23:34 UTC
+++ salt/grains/core.py
@@ -407,7 +407,8 @@ def _bsd_cpudata(osdata):
     if osdata["kernel"] == "FreeBSD" and os.path.isfile("/var/run/dmesg.boot"):
         grains["cpu_flags"] = []
         # TODO: at least it needs to be tested for BSD other then FreeBSD
-        with salt.utils.files.fopen("/var/run/dmesg.boot", "r") as _fp:
+        with salt.utils.files.fopen("/var/run/dmesg.boot", "r", encoding="utf8",
+                errors='ignore') as _fp:
             cpu_here = False
             for line in _fp:
                 if line.startswith("CPU: "):
