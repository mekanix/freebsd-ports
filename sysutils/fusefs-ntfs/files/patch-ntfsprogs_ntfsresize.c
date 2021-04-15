--- ntfsprogs/ntfsresize.c.orig	2017-03-23 09:42:44 UTC
+++ ntfsprogs/ntfsresize.c
@@ -59,6 +59,7 @@
 #include <fcntl.h>
 #endif
 
+#include "param.h"
 #include "debug.h"
 #include "types.h"
 #include "support.h"
@@ -243,8 +244,6 @@ static s64 max_free_cluster_range = 0;
 #define DIRTY_INODE		(1)
 #define DIRTY_ATTRIB		(2)
 
-#define NTFS_MAX_CLUSTER_SIZE	(65536)
-
 static s64 rounded_up_division(s64 numer, s64 denom)
 {
 	return (numer + (denom - 1)) / denom;
@@ -1849,9 +1848,13 @@ static void lseek_to_cluster(ntfs_volume *vol, s64 lcn
 static void copy_clusters(ntfs_resize_t *resize, s64 dest, s64 src, s64 len)
 {
 	s64 i;
-	char buff[NTFS_MAX_CLUSTER_SIZE]; /* overflow checked at mount time */
+	char *buff;
 	ntfs_volume *vol = resize->vol;
 
+	buff = (char*)ntfs_malloc(vol->cluster_size);
+	if (!buff)
+		perr_exit("ntfs_malloc");
+
 	for (i = 0; i < len; i++) {
 
 		lseek_to_cluster(vol, src + i);
@@ -1875,6 +1878,7 @@ static void copy_clusters(ntfs_resize_t *resize, s64 d
 		resize->relocations++;
 		progress_update(&resize->progress, resize->relocations);
 	}
+	free(buff);
 }
 
 static void relocate_clusters(ntfs_resize_t *r, runlist *dest_rl, s64 src_lcn)
