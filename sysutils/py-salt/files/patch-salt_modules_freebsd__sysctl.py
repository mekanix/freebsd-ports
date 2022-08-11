--- salt/modules/freebsd_sysctl.py.orig	2022-06-01 16:25:56 UTC
+++ salt/modules/freebsd_sysctl.py
@@ -167,7 +167,12 @@ def persist(name, value, config="/etc/sysctl.conf"):
                     rest_v = rest.split()[0]
                     rest = rest[len(rest_v) :]
                 if rest_v == value:
-                    return "Already set"
+                    # If it is correct in the config file, check in memory
+                    if str(get(name)) != value:
+                        assign(name, value)
+                        return "Updated"
+                    else:
+                        return "Already set"
                 new_line = _formatfor(key, value, config, rest)
                 nlines.append(new_line)
                 edited = True
