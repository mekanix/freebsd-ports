--- ntfsprogs/ntfsclone.c.orig	2017-03-23 09:42:44 UTC
+++ ntfsprogs/ntfsclone.c
@@ -71,6 +71,7 @@
  */
 #define NTFS_DO_NOT_CHECK_ENDIANS
 
+#include "param.h"
 #include "debug.h"
 #include "types.h"
 #include "support.h"
@@ -270,7 +271,6 @@ static int compare_bitmaps(struct bitmap *a, BOOL copy
 
 #define LAST_METADATA_INODE	11
 
-#define NTFS_MAX_CLUSTER_SIZE	65536
 #define NTFS_SECTOR_SIZE	  512
 
 #define rounded_up_division(a, b) (((a) + (b - 1)) / (b))
@@ -756,7 +756,7 @@ static void read_rescue(void *fd, char *buff, u32 csiz
 
 static void copy_cluster(int rescue, u64 rescue_lcn, u64 lcn)
 {
-	char buff[NTFS_MAX_CLUSTER_SIZE]; /* overflow checked at mount time */
+	char *buff;
 	/* vol is NULL if opt.restore_image is set */
 	s32 csize = le32_to_cpu(image_hdr.cluster_size);
 	BOOL backup_bootsector;
@@ -783,6 +783,10 @@ static void copy_cluster(int rescue, u64 rescue_lcn, u
 		}
 	}
 
+	buff = (char*)ntfs_malloc(csize);
+	if (!buff)
+		err_exit("Not enough memory");
+
 // need reading when not about to write ?
 	if (read_all(fd, buff, csize) == -1) {
 
@@ -858,6 +862,7 @@ static void copy_cluster(int rescue, u64 rescue_lcn, u
 		perr_printf("Write failed");
 #endif
 	}
+	free(buff);
 }
 
 static s64 lseek_out(int fd, s64 pos, int mode)
@@ -995,8 +1000,12 @@ static void write_empty_clusters(s32 csize, s64 count,
 				 struct progress_bar *progress, u64 *p_counter)
 {
 	s64 i;
-	char buff[NTFS_MAX_CLUSTER_SIZE];
+	char *buff;
 
+	buff = (char*)ntfs_malloc(csize);
+	if (!buff)
+		err_exit("Not enough memory");
+
 	memset(buff, 0, csize);
 
 	for (i = 0; i < count; i++) {
@@ -1004,6 +1013,7 @@ static void write_empty_clusters(s32 csize, s64 count,
 			perr_exit("write_all");
 		progress_update(progress, ++(*p_counter));
 	}
+	free(buff);
 }
 
 static void restore_image(void)
@@ -1492,7 +1502,7 @@ static void write_set(char *buff, u32 csize, s64 *curr
 
 static void copy_wipe_mft(ntfs_walk_clusters_ctx *image, runlist *rl)
 {
-	char buff[NTFS_MAX_CLUSTER_SIZE]; /* overflow checked at mount time */
+	char *buff;
 	void *fd;
 	s64 mft_no;
 	u32 mft_record_size;
@@ -1522,6 +1532,10 @@ static void copy_wipe_mft(ntfs_walk_clusters_ctx *imag
 		clusters_per_set = mft_record_size/csize;
 		records_per_set = 1;
 	}
+	buff = (char*)ntfs_malloc(mft_record_size);
+	if (!buff)
+		err_exit("Not enough memory");
+
 	mft_no = 0;
 	ri = rj = 0;
 	wi = wj = 0;
@@ -1554,6 +1568,7 @@ static void copy_wipe_mft(ntfs_walk_clusters_ctx *imag
 		}
 	}
 	image->current_lcn = current_lcn;
+	free(buff);
 }
 
 /*
@@ -1566,7 +1581,7 @@ static void copy_wipe_mft(ntfs_walk_clusters_ctx *imag
 
 static void copy_wipe_i30(ntfs_walk_clusters_ctx *image, runlist *rl)
 {
-	char buff[NTFS_MAX_CLUSTER_SIZE]; /* overflow checked at mount time */
+	char *buff;
 	void *fd;
 	u32 indx_record_size;
 	u32 csize;
@@ -1595,6 +1610,10 @@ static void copy_wipe_i30(ntfs_walk_clusters_ctx *imag
 		clusters_per_set = indx_record_size/csize;
 		records_per_set = 1;
 	}
+	buff = (char*)ntfs_malloc(indx_record_size);
+	if (!buff)
+		err_exit("Not enough memory");
+
 	ri = rj = 0;
 	wi = wj = 0;
 	if (rl[ri].length)
@@ -1627,6 +1646,7 @@ static void copy_wipe_i30(ntfs_walk_clusters_ctx *imag
 		}
 	}
 	image->current_lcn = current_lcn;
+	free(buff);
 }
 
 static void dump_clusters(ntfs_walk_clusters_ctx *image, runlist *rl)
