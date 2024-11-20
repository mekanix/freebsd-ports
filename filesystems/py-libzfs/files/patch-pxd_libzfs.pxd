--- pxd/libzfs.pxd.orig	2022-01-14 17:22:12 UTC
+++ pxd/libzfs.pxd
@@ -476,7 +476,7 @@ cdef extern from "libzfs.h" nogil:
 
         extern int zfs_rename(zfs_handle_t *, const char *, boolean_t, boolean_t)
 
-    ctypedef int (*snapfilter_cb_t)(zfs_handle_t *, void *)
+    ctypedef boolean_t (*snapfilter_cb_t)(zfs_handle_t *, void *)
 
     extern int zfs_send(zfs_handle_t *, const char *, const char *,
         sendflags_t *, int, snapfilter_cb_t, void *, nvpair.nvlist_t **) nogil
