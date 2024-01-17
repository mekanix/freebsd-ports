--- eeschema/eeschema_jobs_handler.cpp.orig	2024-01-18 17:08:46 UTC
+++ eeschema/eeschema_jobs_handler.cpp
@@ -108,7 +108,7 @@ int EESCHEMA_JOBS_HANDLER::JobExportPlot( JOB* aJob )
 
 int EESCHEMA_JOBS_HANDLER::JobExportPlot( JOB* aJob )
 {
-    JOB_EXPORT_SCH_PLOT* aPlotJob = dynamic_cast<JOB_EXPORT_SCH_PLOT*>( aJob );
+    JOB_EXPORT_SCH_PLOT* aPlotJob = static_cast<JOB_EXPORT_SCH_PLOT*>( aJob );
 
     if( !aPlotJob )
         return CLI::EXIT_CODES::ERR_UNKNOWN;
@@ -134,7 +134,7 @@ int EESCHEMA_JOBS_HANDLER::JobExportNetlist( JOB* aJob
 
 int EESCHEMA_JOBS_HANDLER::JobExportNetlist( JOB* aJob )
 {
-    JOB_EXPORT_SCH_NETLIST* aNetJob = dynamic_cast<JOB_EXPORT_SCH_NETLIST*>( aJob );
+    JOB_EXPORT_SCH_NETLIST* aNetJob = static_cast<JOB_EXPORT_SCH_NETLIST*>( aJob );
 
     if( !aNetJob )
         return CLI::EXIT_CODES::ERR_UNKNOWN;
@@ -238,7 +238,7 @@ int EESCHEMA_JOBS_HANDLER::JobExportPythonBom( JOB* aJ
 
 int EESCHEMA_JOBS_HANDLER::JobExportPythonBom( JOB* aJob )
 {
-    JOB_EXPORT_SCH_PYTHONBOM* aNetJob = dynamic_cast<JOB_EXPORT_SCH_PYTHONBOM*>( aJob );
+    JOB_EXPORT_SCH_PYTHONBOM* aNetJob = static_cast<JOB_EXPORT_SCH_PYTHONBOM*>( aJob );
 
     SCHEMATIC* sch = EESCHEMA_HELPERS::LoadSchematic( aNetJob->m_filename, SCH_IO_MGR::SCH_KICAD );
 
@@ -416,7 +416,7 @@ int EESCHEMA_JOBS_HANDLER::JobSymExportSvg( JOB* aJob 
 
 int EESCHEMA_JOBS_HANDLER::JobSymExportSvg( JOB* aJob )
 {
-    JOB_SYM_EXPORT_SVG* svgJob = dynamic_cast<JOB_SYM_EXPORT_SVG*>( aJob );
+    JOB_SYM_EXPORT_SVG* svgJob = static_cast<JOB_SYM_EXPORT_SVG*>( aJob );
 
     wxFileName fn( svgJob->m_libraryPath );
     fn.MakeAbsolute();
@@ -483,7 +483,7 @@ int EESCHEMA_JOBS_HANDLER::JobSymUpgrade( JOB* aJob )
 
 int EESCHEMA_JOBS_HANDLER::JobSymUpgrade( JOB* aJob )
 {
-    JOB_SYM_UPGRADE* upgradeJob = dynamic_cast<JOB_SYM_UPGRADE*>( aJob );
+    JOB_SYM_UPGRADE* upgradeJob = static_cast<JOB_SYM_UPGRADE*>( aJob );
 
     wxFileName fn( upgradeJob->m_libraryPath );
     fn.MakeAbsolute();
