--- include/ntfs-3g/param.h.orig	2017-03-23 09:42:44 UTC
+++ include/ntfs-3g/param.h
@@ -40,6 +40,13 @@ enum {
 };
 
 /*
+ *		Parameters for formatting
+ */
+
+		/* Up to Windows 10, the cluster size was limited to 64K */
+#define NTFS_MAX_CLUSTER_SIZE 2097152 /* Windows 10 Creators allows 2MB */
+
+/*
  *		Parameters for compression
  */
 
