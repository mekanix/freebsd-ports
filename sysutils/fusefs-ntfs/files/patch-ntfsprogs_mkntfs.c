--- ntfsprogs/mkntfs.c.orig	2020-10-06 22:23:53 UTC
+++ ntfsprogs/mkntfs.c
@@ -119,6 +119,7 @@
 #	endif
 #endif
 
+#include "param.h"
 #include "security.h"
 #include "types.h"
 #include "attrib.h"
@@ -3489,6 +3490,7 @@ static BOOL mkntfs_open_partition(ntfs_volume *vol)
 		goto done;
 	}
 
+#ifndef __FreeBSD__
 	if (!S_ISBLK(sbuf.st_mode)) {
 		ntfs_log_error("%s is not a block device.\n", vol->dev->d_name);
 		if (!opts.force) {
@@ -3527,6 +3529,7 @@ static BOOL mkntfs_open_partition(ntfs_volume *vol)
 		ntfs_log_warning("mkntfs forced anyway.\n");
 #endif
 	}
+#endif
 	/* Make sure the file system is not mounted. */
 	if (ntfs_check_if_mounted(vol->dev->d_name, &mnt_flags)) {
 		ntfs_log_perror("Failed to determine whether %s is mounted", vol->dev->d_name);
@@ -3719,11 +3722,11 @@ static BOOL mkntfs_override_vol_params(ntfs_volume *vo
 		/*
 		 * For huge volumes, grow the cluster size until the number of
 		 * clusters fits into 32 bits or the cluster size exceeds the
-		 * maximum limit of 64kiB.
+		 * maximum limit of NTFS_MAX_CLUSTER_SIZE.
 		 */
 		while (volume_size >> (ffs(vol->cluster_size) - 1 + 32)) {
 			vol->cluster_size <<= 1;
-			if (vol->cluster_size > 65535) {
+			if (vol->cluster_size >= NTFS_MAX_CLUSTER_SIZE) {
 				ntfs_log_error("Device is too large to hold an "
 						"NTFS volume (maximum size is "
 						"256TiB).\n");
@@ -3744,15 +3747,18 @@ static BOOL mkntfs_override_vol_params(ntfs_volume *vo
 				"to, or larger than, the sector size.\n");
 		return FALSE;
 	}
-	if (vol->cluster_size > 128 * (u32)opts.sector_size) {
+		/* Before Windows 10 Creators, the limit was 128 */
+	if (vol->cluster_size > 4096 * (u32)opts.sector_size) {
 		ntfs_log_error("The cluster size is invalid.  It cannot be "
-				"more that 128 times the size of the sector "
+				"more that 4096 times the size of the sector "
 				"size.\n");
 		return FALSE;
 	}
-	if (vol->cluster_size > 65536) {
+	if (vol->cluster_size > NTFS_MAX_CLUSTER_SIZE) {
 		ntfs_log_error("The cluster size is invalid.  The maximum "
-			"cluster size is 65536 bytes (64kiB).\n");
+			"cluster size is %lu bytes (%lukiB).\n",
+			(unsigned long)NTFS_MAX_CLUSTER_SIZE,
+			(unsigned long)(NTFS_MAX_CLUSTER_SIZE >> 10));
 		return FALSE;
 	}
 	vol->cluster_size_bits = ffs(vol->cluster_size) - 1;
@@ -4387,6 +4393,7 @@ static BOOL mkntfs_create_root_structures(void)
 	u8 *sd;
 	FILE_ATTR_FLAGS extend_flags;
 	VOLUME_FLAGS volume_flags = const_cpu_to_le16(0);
+	int sectors_per_cluster;
 	int nr_sysfiles;
 	int buf_sds_first_size;
 	char *buf_sds;
@@ -4639,8 +4646,11 @@ static BOOL mkntfs_create_root_structures(void)
 	 * already inserted, so no need to worry about these things.
 	 */
 	bs->bpb.bytes_per_sector = cpu_to_le16(opts.sector_size);
-	bs->bpb.sectors_per_cluster = (u8)(g_vol->cluster_size /
-			opts.sector_size);
+	sectors_per_cluster = g_vol->cluster_size / opts.sector_size;
+	if (sectors_per_cluster > 128)
+		bs->bpb.sectors_per_cluster = 257 - ffs(sectors_per_cluster);
+	else
+		bs->bpb.sectors_per_cluster = sectors_per_cluster;
 	bs->bpb.media_type = 0xf8; /* hard disk */
 	bs->bpb.sectors_per_track = cpu_to_le16(opts.sectors_per_track);
 	ntfs_log_debug("sectors per track = %ld (0x%lx)\n",
