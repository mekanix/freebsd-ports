--- libntfs-3g/device.c.orig	2017-03-23 09:42:44 UTC
+++ libntfs-3g/device.c
@@ -71,6 +71,9 @@
 #ifdef ENABLE_HD
 #include <hd.h>
 #endif
+#ifdef __FreeBSD__
+#include <sys/disk.h>
+#endif
 
 #include "types.h"
 #include "mst.h"
@@ -596,6 +599,17 @@ s64 ntfs_device_size_get(struct ntfs_device *dev, int 
 		}
 	}
 #endif
+#ifdef DIOCGMEDIASIZE 
+	{       off_t size;
+
+		if (dev->d_ops->ioctl(dev, DIOCGMEDIASIZE, &size) >= 0) {
+			ntfs_log_debug("DIOCGMEDIASIZE nr bytes = %llu (0x%llx)\n",
+					(unsigned long long)size,
+					(unsigned long long)size);
+			return (s64)size / block_size;
+		}
+	}
+#endif
 	/*
 	 * We couldn't figure it out by using a specialized ioctl,
 	 * so do binary search to find the size of the device.
@@ -881,6 +895,23 @@ int ntfs_device_sector_size_get(struct ntfs_device *de
 		if (!dev->d_ops->ioctl(dev, DKIOCGETBLOCKSIZE, &sect_size)) {
 			ntfs_log_debug("DKIOCGETBLOCKSIZE sector size = %d bytes\n",
 					(int) sect_size);
+			return sect_size;
+		}
+	}
+#elif defined(DIOCGSECTORSIZE)
+	/*
+	 * XXX On FreeBSD (where we have DIOCGSECTORSIZE) the low-level I/O
+	 * system already knows the sector size, and doing an ioctl is needless.
+	 * However, I don't know how to extract that information cleanly,
+	 * without letting a bunch of platform specific #ifdef-s to sneak in.
+	 * So now I rather just re-do the ioctl...
+	 */
+	{
+		size_t sect_size = 0;
+
+		if (!dev->d_ops->ioctl(dev, DIOCGSECTORSIZE, &sect_size)) {
+			ntfs_log_debug("DIOCGSECTORSIZE sector size = %d bytes\n",
+				(int)sect_size);
 			return sect_size;
 		}
 	}
