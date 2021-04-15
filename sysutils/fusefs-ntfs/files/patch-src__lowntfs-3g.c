--- src/lowntfs-3g.c.orig	2017-03-23 09:42:44 UTC
+++ src/lowntfs-3g.c
@@ -3010,10 +3010,14 @@ close_inode:
 	if (ntfs_inode_close(ni))
 		set_fuse_error(&ret);
 done :
+#ifndef __FreeBSD__
 	if (ret < 0)
 		fuse_reply_err(req, -ret);
 	else
 		fuse_reply_bmap(req, lidx);
+#else
+	;
+#endif
 }
 
 #ifdef HAVE_SETXATTR
