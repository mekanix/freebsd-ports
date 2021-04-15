--- libntfs-3g/bootsect.c.orig	2017-03-23 09:42:44 UTC
+++ libntfs-3g/bootsect.c
@@ -38,6 +38,7 @@
 #include <errno.h>
 #endif
 
+#include "param.h"
 #include "compat.h"
 #include "bootsect.h"
 #include "debug.h"
@@ -61,6 +62,7 @@ BOOL ntfs_boot_sector_is_ntfs(NTFS_BOOT_SECTOR *b)
 {
 	u32 i;
 	BOOL ret = FALSE;
+	u16 sectors_per_cluster;
 
 	ntfs_log_debug("Beginning bootsector check.\n");
 
@@ -83,15 +85,27 @@ BOOL ntfs_boot_sector_is_ntfs(NTFS_BOOT_SECTOR *b)
 	case 1: case 2: case 4: case 8: case 16: case 32: case 64: case 128:
 		break;
 	default:
-		ntfs_log_error("Unexpected sectors per cluster value (%d).\n",
-			       b->bpb.sectors_per_cluster);
-		goto not_ntfs;
+		if ((b->bpb.sectors_per_cluster < 240)
+		    || (b->bpb.sectors_per_cluster > 249)) {
+			if (b->bpb.sectors_per_cluster > 128)
+				ntfs_log_error("Unexpected sectors"
+					" per cluster value (code 0x%x)\n",
+					b->bpb.sectors_per_cluster);
+			else
+				ntfs_log_error("Unexpected sectors"
+					" per cluster value (%d).\n",
+					b->bpb.sectors_per_cluster);
+			goto not_ntfs;
+		}
 	}
 
 	ntfs_log_debug("Checking cluster size.\n");
-	i = (u32)le16_to_cpu(b->bpb.bytes_per_sector) * 
-		b->bpb.sectors_per_cluster;
-	if (i > 65536) {
+	if (b->bpb.sectors_per_cluster > 128)
+		sectors_per_cluster = 1 << (256 - b->bpb.sectors_per_cluster);
+	else
+		sectors_per_cluster = b->bpb.sectors_per_cluster;
+	i = (u32)le16_to_cpu(b->bpb.bytes_per_sector) * sectors_per_cluster;
+	if (i > NTFS_MAX_CLUSTER_SIZE) {
 		ntfs_log_error("Unexpected cluster size (%d).\n", i);
 		goto not_ntfs;
 	}
@@ -171,7 +185,7 @@ static const char *last_sector_error =
 int ntfs_boot_sector_parse(ntfs_volume *vol, const NTFS_BOOT_SECTOR *bs)
 {
 	s64 sectors;
-	u8  sectors_per_cluster;
+	u16  sectors_per_cluster;
 	s8  c;
 
 	/* We return -1 with errno = EINVAL on error. */
@@ -186,7 +200,10 @@ int ntfs_boot_sector_parse(ntfs_volume *vol, const NTF
 	 * below or equal the number_of_clusters) really belong in the
 	 * ntfs_boot_sector_is_ntfs but in this way we can just do this once.
 	 */
-	sectors_per_cluster = bs->bpb.sectors_per_cluster;
+	if (bs->bpb.sectors_per_cluster > 128)
+		sectors_per_cluster = 1 << (256 - bs->bpb.sectors_per_cluster);
+	else
+		sectors_per_cluster = bs->bpb.sectors_per_cluster;
 	ntfs_log_debug("SectorsPerCluster = 0x%x\n", sectors_per_cluster);
 	if (sectors_per_cluster & (sectors_per_cluster - 1)) {
 		ntfs_log_error("sectors_per_cluster (%d) is not a power of 2."
