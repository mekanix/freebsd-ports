--- libzfs.pyx.orig	2024-12-17 11:37:37 UTC
+++ libzfs.pyx
@@ -29,7 +29,18 @@ include "converter.pxi"
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
@@ -2555,6 +2566,11 @@ cdef class ZPoolScrub(object):
             if self.stats != NULL:
                 return self.stats.pss_pass_issued
 
+    property bytes_skipped:
+        def __get__(self):
+            if self.stats != NULL:
+                return self.stats.pss_skipped
+
     property pause:
         def __get__(self):
             if self.state == ScanState.SCANNING and self.stats.pss_pass_scrub_pause != 0:
@@ -2573,7 +2589,7 @@ cdef class ZPoolScrub(object):
             if not self.bytes_to_scan:
                 return 0
 
-            return (<float>self.bytes_issued / <float>self.bytes_to_scan) * 100
+            return (<float>self.bytes_issued / (<float>self.bytes_to_scan - <float>self.bytes_skipped)) * 100
 
     def __getstate__(self):
         return {
@@ -2996,7 +3012,7 @@ cdef class ZFSPool(object):
     IF HAVE_LZC_SYNC:
         def sync(self, force=False):
             cdef int ret
-            cdef const char *c_name = self.name
+            cdef const char *c_name = libzfs.zpool_get_name(self.handle)
             cdef NVList innvl = NVList()
 
             innvl["force"] = force
@@ -4080,8 +4096,10 @@ cdef class ZFSDataset(ZFSResource):
         if flags:
             convert_sendflags(flags, &cflags)
 
+        cb_arg = <void*>py_send_filter
         with nogil:
-            err = libzfs.zfs_send(self.handle, cfromname, ctoname, &cflags, cfd, NULL, NULL, NULL)
+            err = libzfs.zfs_send(self.handle, cfromname, ctoname, &cflags, cfd, send_filter, cb_arg, NULL)
+        currently_sending_snapshot = ""
 
         if err != 0:
             raise self.root.get_error()
@@ -4336,6 +4354,7 @@ cdef class ZFSSnapshot(ZFSResource):
             return result
 
     def get_send_progress(self, fd):
+        global currently_sending_snapshot
         IF HAVE_ZFS_IOCTL_HEADER:
             cdef zfs.zfs_cmd_t cmd
             memset(&cmd, 0, cython.sizeof(zfs.zfs_cmd_t))
@@ -4343,7 +4362,10 @@ cdef class ZFSSnapshot(ZFSResource):
             cdef int ret
 
             cmd.zc_cookie = fd
-            strncpy(cmd.zc_name, self.name, zfs.MAXPATHLEN)
+            if currently_sending_snapshot == "":
+                strncpy(cmd.zc_name, self.name, zfs.MAXPATHLEN)
+            else:
+                strncpy(cmd.zc_name, currently_sending_snapshot, zfs.MAXPATHLEN)
 
             with nogil:
                 ret = libzfs.zfs_ioctl(self.root.handle, zfs.ZFS_IOC_SEND_PROGRESS, &cmd)
