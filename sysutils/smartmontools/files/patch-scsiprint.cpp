--- scsiprint.cpp.orig	2023-08-17 14:09:17 UTC
+++ scsiprint.cpp
@@ -525,12 +525,20 @@ scsiGetStartStopData(scsi_device * device)
         switch (pc) {
         case 1:
             if (10 == extra) {
-                jout("Manufactured in week %.2s of year %.4s\n", ucp + 8,
-                     ucp + 4);
-                snprintf(b, sizeof(b), "%.4s", ucp + 4);
-                jglb[jname]["year_of_manufacture"] = b;
-                snprintf(b, sizeof(b), "%.2s", ucp + 8);
-                jglb[jname]["week_of_manufacture"] = b;
+                unsigned char *week = ucp + 8;
+                if (*week > 127 || *(week + 1) > 127) {
+                    jout("Manufactured in week -1 of year -1\n");
+                    jglb[jname]["year_of_manufacture"] = "-1";
+                    jglb[jname]["week_of_manufacture"] = "-1";
+                } else {
+                    unsigned char *year = ucp + 4;
+                    jout("Manufactured in week %.2s of year %.4s\n", week,
+                         year);
+                    snprintf(b, sizeof(b), "%.4s", year);
+                    jglb[jname]["year_of_manufacture"] = b;
+                    snprintf(b, sizeof(b), "%.2s", week);
+                    jglb[jname]["week_of_manufacture"] = b;
+                }
             }
             break;
         case 2:
