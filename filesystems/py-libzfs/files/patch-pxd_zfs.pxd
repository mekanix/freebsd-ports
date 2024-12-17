--- pxd/zfs.pxd.orig	2024-12-17 11:36:11 UTC
+++ pxd/zfs.pxd
@@ -522,6 +522,7 @@ cdef extern from "sys/fs/zfs.h" nogil:
         uint64_t    pss_end_time # scan end time
         uint64_t    pss_to_examine # total bytes to scan
         uint64_t    pss_examined # total bytes located by scanner
+        uint64_t    pss_skipped # total bytes skipped by scanner
         uint64_t    pss_to_process # total bytes to process
         uint64_t    pss_processed # total processed bytes
         uint64_t    pss_errors # scan errors
