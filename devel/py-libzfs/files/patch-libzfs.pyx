--- libzfs.pyx.orig	2022-02-02 17:12:49 UTC
+++ libzfs.pyx
@@ -29,7 +29,18 @@ include "config.pxi"
 include "nvpair.pxi"
 include "converter.pxi"
 
+currently_sending_snapshot = ""
 
+def py_send_filter(zcname):
+    global currently_sending_snapshot
+    currently_sending_snapshot = zcname
+    return True
+
+cdef boolean_t send_filter(zfs_handle_t *handle, void *cb_arg) nogil:
+    with gil:
+        func = <object>cb_arg;
+        return bool(func(zfs_get_name(handle)))
+
 class DatasetType(enum.IntEnum):
     FILESYSTEM = zfs.ZFS_TYPE_FILESYSTEM
     VOLUME = zfs.ZFS_TYPE_VOLUME
@@ -2369,23 +2380,28 @@ cdef class ZPoolScrub(object):
     property bytes_scanned:
         def __get__(self):
             if self.stats != NULL:
-                return self.stats.pss_issued
+                return self.stats.pss_examined
 
     property total_secs_left:
         def __get__(self):
             if self.state != ScanState.SCANNING:
                 return
 
-            examined = self.bytes_scanned
             total = self.bytes_to_scan
+            issued = self.bytes_issued
             elapsed = ((int(time.time()) - self.stats.pss_pass_start) - self.stats.pss_pass_scrub_spent_paused) or 1
             pass_issued = self.stats.pss_pass_issued or 1
             issue_rate = pass_issued / elapsed
-            return int((total - examined) / issue_rate)
+            return int((total - issued) / issue_rate)
 
     property bytes_issued:
         def __get__(self):
             if self.stats != NULL:
+                return self.stats.pss_issued
+
+    property bytes_issued_per_pass:
+        def __get__(self):
+            if self.stats != NULL:
                 return self.stats.pss_pass_issued
 
     property pause:
@@ -3883,8 +3899,10 @@ cdef class ZFSDataset(ZFSResource):
         if flags:
             convert_sendflags(flags, &cflags)
 
+        cb_arg = <void*>py_send_filter
         with nogil:
-            err = libzfs.zfs_send(self.handle, cfromname, ctoname, &cflags, cfd, NULL, NULL, NULL)
+            err = libzfs.zfs_send(self.handle, cfromname, ctoname, &cflags, cfd, send_filter, cb_arg, NULL)
+        currently_sending_snapshot = ""
 
         if err != 0:
             raise self.root.get_error()
@@ -4139,6 +4157,7 @@ cdef class ZFSSnapshot(ZFSResource):
             return result
 
     def get_send_progress(self, fd):
+        global currently_sending_snapshot
         IF HAVE_ZFS_IOCTL_HEADER:
             cdef zfs.zfs_cmd_t cmd
             memset(&cmd, 0, cython.sizeof(zfs.zfs_cmd_t))
@@ -4146,7 +4165,10 @@ cdef class ZFSSnapshot(ZFSResource):
             cdef int ret
 
             cmd.zc_cookie = fd
-            strncpy(cmd.zc_name, self.name, zfs.MAXPATHLEN)
+            if currently_sending_snapshot == "":
+                strncpy(cmd.zc_name, self.name, zfs.MAXPATHLEN)
+            else:
+                strncpy(cmd.zc_name, currently_sending_snapshot, zfs.MAXPATHLEN)
 
             with nogil:
                 ret = libzfs.zfs_ioctl(self.root.handle, zfs.ZFS_IOC_SEND_PROGRESS, &cmd)
