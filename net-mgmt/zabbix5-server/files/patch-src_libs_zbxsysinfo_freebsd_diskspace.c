--- src/libs/zbxsysinfo/freebsd/diskspace.c.orig	2021-05-07 22:57:00 UTC
+++ src/libs/zbxsysinfo/freebsd/diskspace.c
@@ -202,7 +202,7 @@ int	VFS_FS_DISCOVERY(AGENT_REQUEST *request, AGENT_RES
 	struct statfs	*mntbuf;
 	struct zbx_json	j;
 
-	if (0 == (rc = getmntinfo(&mntbuf, MNT_WAIT)))
+	if (0 == (rc = getmntinfo(&mntbuf, MNT_NOWAIT)))
 	{
 		SET_MSG_RESULT(result, zbx_dsprintf(NULL, "Cannot obtain system information: %s", zbx_strerror(errno)));
 		return SYSINFO_RET_FAIL;
@@ -242,7 +242,7 @@ static int	vfs_fs_get(AGENT_REQUEST *request, AGENT_RE
 	int			ret = SYSINFO_RET_FAIL;
 	char 			*mpoint;
 
-	if (0 == (rc = getmntinfo(&mntbuf, MNT_WAIT)))
+	if (0 == (rc = getmntinfo(&mntbuf, MNT_NOWAIT)))
 	{
 		SET_MSG_RESULT(result, zbx_dsprintf(NULL, "Cannot obtain system information: %s", zbx_strerror(errno)));
 		return SYSINFO_RET_FAIL;
@@ -282,7 +282,7 @@ static int	vfs_fs_get(AGENT_REQUEST *request, AGENT_RE
 		zbx_vector_ptr_append(&mntpoints, mntpoint);
 	}
 
-	if (0 == (rc = getmntinfo(&mntbuf, MNT_WAIT)))
+	if (0 == (rc = getmntinfo(&mntbuf, MNT_NOWAIT)))
 	{
 		SET_MSG_RESULT(result, zbx_dsprintf(NULL, "Cannot obtain system information: %s", zbx_strerror(errno)));
 		goto out;
