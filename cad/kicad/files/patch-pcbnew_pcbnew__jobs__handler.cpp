--- pcbnew/pcbnew_jobs_handler.cpp.orig	2024-01-18 17:02:26 UTC
+++ pcbnew/pcbnew_jobs_handler.cpp
@@ -76,7 +76,7 @@ int PCBNEW_JOBS_HANDLER::JobExportStep( JOB* aJob )
 
 int PCBNEW_JOBS_HANDLER::JobExportStep( JOB* aJob )
 {
-    JOB_EXPORT_PCB_STEP* aStepJob = dynamic_cast<JOB_EXPORT_PCB_STEP*>( aJob );
+    JOB_EXPORT_PCB_STEP* aStepJob = static_cast<JOB_EXPORT_PCB_STEP*>( aJob );
 
     if( aStepJob == nullptr )
         return CLI::EXIT_CODES::ERR_UNKNOWN;
@@ -119,7 +119,7 @@ int PCBNEW_JOBS_HANDLER::JobExportSvg( JOB* aJob )
 
 int PCBNEW_JOBS_HANDLER::JobExportSvg( JOB* aJob )
 {
-    JOB_EXPORT_PCB_SVG* aSvgJob = dynamic_cast<JOB_EXPORT_PCB_SVG*>( aJob );
+    JOB_EXPORT_PCB_SVG* aSvgJob = static_cast<JOB_EXPORT_PCB_SVG*>( aJob );
 
     if( aSvgJob == nullptr )
         return CLI::EXIT_CODES::ERR_UNKNOWN;
@@ -154,7 +154,7 @@ int PCBNEW_JOBS_HANDLER::JobExportDxf( JOB* aJob )
 
 int PCBNEW_JOBS_HANDLER::JobExportDxf( JOB* aJob )
 {
-    JOB_EXPORT_PCB_DXF* aDxfJob = dynamic_cast<JOB_EXPORT_PCB_DXF*>( aJob );
+    JOB_EXPORT_PCB_DXF* aDxfJob = static_cast<JOB_EXPORT_PCB_DXF*>( aJob );
 
     if( aDxfJob == nullptr )
         return CLI::EXIT_CODES::ERR_UNKNOWN;
@@ -209,7 +209,7 @@ int PCBNEW_JOBS_HANDLER::JobExportPdf( JOB* aJob )
 
 int PCBNEW_JOBS_HANDLER::JobExportPdf( JOB* aJob )
 {
-    JOB_EXPORT_PCB_PDF* aPdfJob = dynamic_cast<JOB_EXPORT_PCB_PDF*>( aJob );
+    JOB_EXPORT_PCB_PDF* aPdfJob = static_cast<JOB_EXPORT_PCB_PDF*>( aJob );
 
     if( aPdfJob == nullptr )
         return CLI::EXIT_CODES::ERR_UNKNOWN;
@@ -278,7 +278,7 @@ int PCBNEW_JOBS_HANDLER::JobExportGerbers( JOB* aJob )
 int PCBNEW_JOBS_HANDLER::JobExportGerbers( JOB* aJob )
 {
     int                     exitCode = CLI::EXIT_CODES::OK;
-    JOB_EXPORT_PCB_GERBERS* aGerberJob = dynamic_cast<JOB_EXPORT_PCB_GERBERS*>( aJob );
+    JOB_EXPORT_PCB_GERBERS* aGerberJob = static_cast<JOB_EXPORT_PCB_GERBERS*>( aJob );
 
     if( aGerberJob == nullptr )
         return CLI::EXIT_CODES::ERR_UNKNOWN;
@@ -400,7 +400,7 @@ int PCBNEW_JOBS_HANDLER::JobExportGerber( JOB* aJob )
 int PCBNEW_JOBS_HANDLER::JobExportGerber( JOB* aJob )
 {
     int                    exitCode = CLI::EXIT_CODES::OK;
-    JOB_EXPORT_PCB_GERBER* aGerberJob = dynamic_cast<JOB_EXPORT_PCB_GERBER*>( aJob );
+    JOB_EXPORT_PCB_GERBER* aGerberJob = static_cast<JOB_EXPORT_PCB_GERBER*>( aJob );
 
     if( aGerberJob == nullptr )
         return CLI::EXIT_CODES::ERR_UNKNOWN;
@@ -451,7 +451,7 @@ int PCBNEW_JOBS_HANDLER::JobExportDrill( JOB* aJob )
 
 int PCBNEW_JOBS_HANDLER::JobExportDrill( JOB* aJob )
 {
-    JOB_EXPORT_PCB_DRILL* aDrillJob = dynamic_cast<JOB_EXPORT_PCB_DRILL*>( aJob );
+    JOB_EXPORT_PCB_DRILL* aDrillJob = static_cast<JOB_EXPORT_PCB_DRILL*>( aJob );
 
     if( aDrillJob == nullptr )
         return CLI::EXIT_CODES::ERR_UNKNOWN;
@@ -518,7 +518,7 @@ int PCBNEW_JOBS_HANDLER::JobExportDrill( JOB* aJob )
         else
             precision = precisionListForMetric;
 
-        EXCELLON_WRITER* excellonWriter = dynamic_cast<EXCELLON_WRITER*>( drillWriter.get() );
+        EXCELLON_WRITER* excellonWriter = static_cast<EXCELLON_WRITER*>( drillWriter.get() );
 
         if( excellonWriter == nullptr )
             return CLI::EXIT_CODES::ERR_UNKNOWN;
@@ -540,7 +540,7 @@ int PCBNEW_JOBS_HANDLER::JobExportDrill( JOB* aJob )
     }
     else if( aDrillJob->m_format == JOB_EXPORT_PCB_DRILL::DRILL_FORMAT::GERBER )
     {
-        GERBER_WRITER* gerberWriter = dynamic_cast<GERBER_WRITER*>( drillWriter.get() );
+        GERBER_WRITER* gerberWriter = static_cast<GERBER_WRITER*>( drillWriter.get() );
 
         if( gerberWriter == nullptr )
             return CLI::EXIT_CODES::ERR_UNKNOWN;
@@ -565,7 +565,7 @@ int PCBNEW_JOBS_HANDLER::JobExportPos( JOB* aJob )
 
 int PCBNEW_JOBS_HANDLER::JobExportPos( JOB* aJob )
 {
-    JOB_EXPORT_PCB_POS* aPosJob = dynamic_cast<JOB_EXPORT_PCB_POS*>( aJob );
+    JOB_EXPORT_PCB_POS* aPosJob = static_cast<JOB_EXPORT_PCB_POS*>( aJob );
 
     if( aPosJob == nullptr )
         return CLI::EXIT_CODES::ERR_UNKNOWN;
@@ -640,7 +640,7 @@ int PCBNEW_JOBS_HANDLER::JobExportFpUpgrade( JOB* aJob
 
 int PCBNEW_JOBS_HANDLER::JobExportFpUpgrade( JOB* aJob )
 {
-    JOB_FP_UPGRADE* upgradeJob = dynamic_cast<JOB_FP_UPGRADE*>( aJob );
+    JOB_FP_UPGRADE* upgradeJob = static_cast<JOB_FP_UPGRADE*>( aJob );
 
     if( upgradeJob == nullptr )
         return CLI::EXIT_CODES::ERR_UNKNOWN;
@@ -711,7 +711,7 @@ int PCBNEW_JOBS_HANDLER::JobExportFpSvg( JOB* aJob )
 
 int PCBNEW_JOBS_HANDLER::JobExportFpSvg( JOB* aJob )
 {
-    JOB_FP_EXPORT_SVG* svgJob = dynamic_cast<JOB_FP_EXPORT_SVG*>( aJob );
+    JOB_FP_EXPORT_SVG* svgJob = static_cast<JOB_FP_EXPORT_SVG*>( aJob );
 
     if( svgJob == nullptr )
         return CLI::EXIT_CODES::ERR_UNKNOWN;
@@ -779,7 +779,7 @@ int PCBNEW_JOBS_HANDLER::doFpExportSvg( JOB_FP_EXPORT_
     std::unique_ptr<BOARD> brd;
     brd.reset( CreateEmptyBoard() );
 
-    FOOTPRINT* fp = dynamic_cast<FOOTPRINT*>( aFootprint->Clone() );
+    FOOTPRINT* fp = static_cast<FOOTPRINT*>( aFootprint->Clone() );
 
     if( fp == nullptr )
         return CLI::EXIT_CODES::ERR_UNKNOWN;
