--- salt/states/cron.py.orig	2021-10-04 20:29:18 UTC
+++ salt/states/cron.py
@@ -360,6 +360,9 @@ def present(
         return ret
 
     if special is None:
+        antidata = __salt__["cron.rm_special"](
+            user, name, special=special, identifier=identifier
+        )
         data = __salt__["cron.set_job"](
             user=user,
             minute=minute,
@@ -373,6 +376,7 @@ def present(
             identifier=identifier,
         )
     else:
+        antidata = __salt__["cron.rm_job"](user, name, identifier=identifier)
         data = __salt__["cron.set_special"](
             user=user,
             special=special,
@@ -381,20 +385,27 @@ def present(
             commented=commented,
             identifier=identifier,
         )
-    if data == "present":
-        ret["comment"] = "Cron {0} already present".format(name)
+    if data == "present" and antidata == "removed":
+        ret["comment"] = "Duplicate Cron {} removed".format(name)
         return ret
 
-    if data == "new":
-        ret["comment"] = "Cron {0} added to {1}'s crontab".format(name, user)
+    if data == "present" and antidata == "absent":
+        ret["comment"] = "Cron {} already present".format(name)
+        return ret
+
+    if data == "new" and antidata == "absent":
+        ret["comment"] = "Cron {} added to {}'s crontab".format(name, user)
         ret["changes"] = {user: name}
         return ret
 
+    if data == "new" and antidata == "removed":
+        ret["comment"] = "Cron {} time specification changed".format(name)
+
     if data == "updated":
-        ret["comment"] = "Cron {0} updated".format(name)
+        ret["comment"] = "Cron {} updated".format(name)
         ret["changes"] = {user: name}
         return ret
-    ret["comment"] = "Cron {0} for user {1} failed to commit with error \n{2}".format(
+    ret["comment"] = "Cron {} for user {} failed to commit with error \n{}".format(
         name, user, data
     )
     ret["result"] = False
