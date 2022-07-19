--- libzfs.pyx.orig	2022-06-09 20:38:25 UTC
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
@@ -2874,14 +2885,14 @@ cdef class ZFSPool(object):
     IF HAVE_LZC_SYNC:
         def sync(self, force=False):
             cdef int ret
-            cdef const char *c_name = self.name
+            cdef const char *c_name = libzfs.zpool_get_name(self.handle)
             cdef NVList innvl = NVList()
 
             innvl["force"] = force
             with nogil:
                 ret = libzfs.lzc_sync(c_name, innvl.handle, NULL)
             if ret != 0:
-                raise self.root.get_error()
+                raise OSError(ret, os.strerror(ret))
 
     cdef NVList get_raw_config(self):
         cdef uintptr_t nvl = <uintptr_t>libzfs.zpool_get_config(self.handle, NULL)
@@ -3939,8 +3950,10 @@ cdef class ZFSDataset(ZFSResource):
         if flags:
             convert_sendflags(flags, &cflags)
 
+        cb_arg = <void*>py_send_filter
         with nogil:
-            err = libzfs.zfs_send(self.handle, cfromname, ctoname, &cflags, cfd, NULL, NULL, NULL)
+            err = libzfs.zfs_send(self.handle, cfromname, ctoname, &cflags, cfd, send_filter, cb_arg, NULL)
+        currently_sending_snapshot = ""
 
         if err != 0:
             raise self.root.get_error()
@@ -4195,6 +4208,7 @@ cdef class ZFSSnapshot(ZFSResource):
             return result
 
     def get_send_progress(self, fd):
+        global currently_sending_snapshot
         IF HAVE_ZFS_IOCTL_HEADER:
             cdef zfs.zfs_cmd_t cmd
             memset(&cmd, 0, cython.sizeof(zfs.zfs_cmd_t))
@@ -4202,7 +4216,10 @@ cdef class ZFSSnapshot(ZFSResource):
             cdef int ret
 
             cmd.zc_cookie = fd
-            strncpy(cmd.zc_name, self.name, zfs.MAXPATHLEN)
+            if currently_sending_snapshot == "":
+                strncpy(cmd.zc_name, self.name, zfs.MAXPATHLEN)
+            else:
+                strncpy(cmd.zc_name, currently_sending_snapshot, zfs.MAXPATHLEN)
 
             with nogil:
                 ret = libzfs.zfs_ioctl(self.root.handle, zfs.ZFS_IOC_SEND_PROGRESS, &cmd)
