--- salt/states/user.py.orig	2023-07-26 09:01:14 UTC
+++ salt/states/user.py
@@ -40,13 +40,30 @@ def _group_changes(cur, wanted, remove=False):
     """
     Determine if the groups need to be changed
     """
-    old = set(cur)
-    new = set(wanted)
-    if (remove and old != new) or (not remove and not new.issubset(old)):
-        return True
-    return False
+    cur = set(cur)
+    wanted = set(wanted)
 
+    if cur == wanted or (not remove and wanted.issubset(cur)):
+        return False
 
+    all_grps = {name: __salt__["group.info"](name) for name in cur.union(wanted)}
+
+    if remove:
+        diff = wanted.symmetric_difference(cur)
+    else:
+        diff = wanted.difference(cur)
+
+    remain = list(diff)
+    for diff_grp in diff:
+        for grp, info in all_grps.items():
+            if grp == diff_grp:
+                continue
+            if all_grps[diff_grp]["gid"] == info["gid"]:
+                # dupe detected
+                remain.remove(diff_grp)
+
+    return bool(remain)
+
 def _changes(
     name,
     uid=None,
@@ -100,7 +117,16 @@ def _changes(
 
     change = {}
     wanted_groups = sorted(set((groups or []) + (optional_groups or [])))
-    if not remove_groups:
+    lusr_groups_gids = [
+        __salt__["file.group_to_gid"](gname) for gname in lusr["groups"]
+    ]
+    dupe_groups = {}
+    for idx, _gid in enumerate(lusr_groups_gids):
+        if lusr_groups_gids.count(_gid) > 1:
+            if _gid not in dupe_groups:
+                dupe_groups[_gid] = []
+            dupe_groups[_gid].append(lusr["groups"][idx])
+    if not remove_groups or groups is None and not optional_groups:
         wanted_groups = sorted(set(wanted_groups + lusr["groups"]))
     if uid and lusr["uid"] != uid:
         change["uid"] = uid
@@ -109,8 +135,21 @@ def _changes(
     default_grp = __salt__["file.gid_to_group"](gid if gid is not None else lusr["gid"])
     old_default_grp = __salt__["file.gid_to_group"](lusr["gid"])
     # Remove the default group from the list for comparison purposes.
-    if default_grp in lusr["groups"]:
-        lusr["groups"].remove(default_grp)
+    # Remove default group from wanted_groups, as this requirement is
+    # already met
+    if default_grp in lusr["groups"] or default_grp in wanted_groups:
+        if default_grp in salt.utils.data.flatten(dupe_groups.values()):
+            dupe_gid = __salt__["file.group_to_gid"](default_grp)
+            for gname in dupe_groups[dupe_gid]:
+                if gname in lusr["groups"]:
+                    lusr["groups"].remove(gname)
+                if gname in wanted_groups:
+                    wanted_groups.remove(gname)
+        else:
+            if default_grp in lusr["groups"]:
+                lusr["groups"].remove(default_grp)
+            if default_grp in wanted_groups:
+                wanted_groups.remove(default_grp)
     # If the group is being changed, make sure that the old primary group is
     # also removed from the list. Otherwise, if a user's gid is being changed
     # and their old primary group is reassigned as an additional group, Salt
@@ -120,13 +159,15 @@ def _changes(
     # If there's a group by the same name as the user, remove it from the list
     # for comparison purposes.
     if name in lusr["groups"] and name not in wanted_groups:
-        lusr["groups"].remove(name)
-    # Remove default group from wanted_groups, as this requirement is
-    # already met
-    if default_grp in wanted_groups:
-        wanted_groups.remove(default_grp)
+        if name in salt.utils.data.flatten(dupe_groups.values()):
+            dupe_gid = __salt__["file.group_to_gid"](name)
+            for gname in dupe_groups[dupe_gid]:
+                lusr["groups"].remove(gname)
+        else:
+            lusr["groups"].remove(name)
     if _group_changes(lusr["groups"], wanted_groups, remove_groups):
-        change["groups"] = wanted_groups
+        if wanted_groups or remove_groups:
+            change["groups"] = wanted_groups
     if home and lusr["home"] != home:
         change["home"] = home
     if createhome:
