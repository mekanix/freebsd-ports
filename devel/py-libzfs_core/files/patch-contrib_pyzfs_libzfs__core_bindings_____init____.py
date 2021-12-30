--- contrib/pyzfs/libzfs_core/bindings/__init__.py.orig	2021-06-17 17:06:34 UTC
+++ contrib/pyzfs/libzfs_core/bindings/__init__.py
@@ -47,6 +47,11 @@ def _setup_cffi():
     MODULES = ["libnvpair", "libzfs_core"]
     ffi = FFI()
 
+    # Fix underlinking in libzfs_core.  Until OpenZFS commit
+    # 514498fef6977e4d1d6dc676710567384d6f6b39 libzfs_core depended on libzfs
+    # yet was not linked to it at compile-time.
+    ffi.dlopen("zfs")
+
     for module_name in MODULES:
         module = importlib.import_module("." + module_name, __name__)
         ffi.cdef(module.CDEF)
