--- libntfs-3g/volume.c.orig	2017-03-23 09:42:44 UTC
+++ libntfs-3g/volume.c
@@ -959,7 +959,8 @@ ntfs_volume *ntfs_device_mount(struct ntfs_device *dev
 		vol->mftmirr_size = l;
 	}
 	ntfs_log_debug("Comparing $MFTMirr to $MFT...\n");
-	for (i = 0; i < vol->mftmirr_size; ++i) {
+		/* Windows 10 does not update the full $MFTMirr any more */
+	for (i = 0; (i < vol->mftmirr_size) && (i < FILE_first_user); ++i) {
 		MFT_RECORD *mrec, *mrec2;
 		const char *ESTR[12] = { "$MFT", "$MFTMirr", "$LogFile",
 			"$Volume", "$AttrDef", "root directory", "$Bitmap",
