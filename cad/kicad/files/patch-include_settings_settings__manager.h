--- include/settings/settings_manager.h.orig	2024-01-22 14:47:33 UTC
+++ include/settings/settings_manager.h
@@ -102,7 +102,7 @@ class SETTINGS_MANAGER (public)
         size_t typeHash = typeid( T ).hash_code();
 
          if( m_app_settings_cache.count( typeHash ) )
-            ret = dynamic_cast<T*>( m_app_settings_cache.at( typeHash ) );
+            ret = static_cast<T*>( m_app_settings_cache.at( typeHash ) );
 
         if( ret )
             return ret;
@@ -110,12 +110,12 @@ class SETTINGS_MANAGER (public)
         auto it = std::find_if( m_settings.begin(), m_settings.end(),
                                 []( const std::unique_ptr<JSON_SETTINGS>& aSettings )
                                 {
-                                    return dynamic_cast<T*>( aSettings.get() );
+                                    return static_cast<T*>( aSettings.get() );
                                 } );
 
         if( it != m_settings.end() )
         {
-            ret = dynamic_cast<T*>( it->get() );
+            ret = static_cast<T*>( it->get() );
         }
         else
         {
