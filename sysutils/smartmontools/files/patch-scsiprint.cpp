--- scsiprint.cpp.orig	2022-02-27 07:53:55 UTC
+++ scsiprint.cpp
@@ -457,6 +457,7 @@ scsiGetStartStopData(scsi_device * device)
     unsigned char * ucp;
     char b[32];
     const char * q;
+    std::string s;
     static const char * jname = "scsi_start_stop_cycle_counter";
 
     if ((err = scsiLogSense(device, STARTSTOP_CYCLE_COUNTER_LPAGE, 0, gBuf,
@@ -503,28 +504,28 @@ scsiGetStartStopData(scsi_device * device)
             if ((extra > 7) && (! is_all_ffs)) {
                 q = "Specified cycle count over device lifetime";
                 jout("%s:  %u\n", q, u);
-                jglb[jname][q] = u;
+                jglb[jname][json::str2key(q)] = u;
             }
             break;
         case 4:
             if ((extra > 7) && (! is_all_ffs)) {
                 q = "Accumulated start-stop cycles";
                 jout("%s:  %u\n", q, u);
-                jglb[jname][q] = u;
+                jglb[jname][json::str2key(q)] = u;
             }
             break;
         case 5:
             if ((extra > 7) && (! is_all_ffs)) {
                 q = "Specified load-unload count over device lifetime";
                 jout("%s:  %u\n", q, u);
-                jglb[jname][q] = u;
+                jglb[jname][json::str2key(q)] = u;
             }
             break;
         case 6:
             if ((extra > 7) && (! is_all_ffs)) {
                 q = "Accumulated load-unload cycles";
                 jout("%s:  %u\n", q, u);
-                jglb[jname][q] = u;
+                jglb[jname][json::str2key(q)] = u;
             }
             break;
         default:
@@ -567,7 +568,9 @@ scsiPrintPendingDefectsLPage(scsi_device * device)
     while (num > 3) {
         int pc = sg_get_unaligned_be16(bp + 0);
         int pl = bp[3] + 4;
-        uint32_t count;
+        uint32_t count, poh;
+        uint64_t lba;
+
         switch (pc) {
         case 0x0:
             jout("  Pending defect count:");
@@ -595,11 +598,15 @@ scsiPrintPendingDefectsLPage(scsi_device * device)
                 print_off();
                 return;
             }
-            jout("  %4d:  0x%-16" PRIx64 ",  %5u\n", pc,
-                 sg_get_unaligned_be64(bp + 8), sg_get_unaligned_be32(bp + 4));
-            jglb[jname][pc]["LBA"] = sg_get_unaligned_be64(bp + 8);
-            jglb[jname][pc]["accum_power_on_hours"] =
-                   sg_get_unaligned_be32(bp + 4);
+            poh = sg_get_unaligned_be32(bp + 4);
+            lba = sg_get_unaligned_be64(bp + 8);
+            jout("  %4d:  0x%-16" PRIx64 ",  %5u\n", pc, lba, poh);
+            {
+                json::ref jref = jglb[jname]["table"][pc];
+
+                jref["lba"] = lba;
+                jref["accum_power_on_hours"] = poh;
+            }
             break;
         }
         num -= pl;
@@ -1450,7 +1457,7 @@ scsiPrintSSMedia(scsi_device * device)
             }
             q = "Percentage used endurance indicator";
             jout("%s: %d%%\n", q, ucp[7]);
-            jglb[std::string("scsi_") + q] = ucp[7];
+            jglb[std::string("scsi_") + json::str2key(q)] = ucp[7];
         default:        /* ignore other parameter codes */
             break;
         }
@@ -1511,73 +1518,73 @@ scsiPrintZBDeviceStats(scsi_device * device)
             q = "Maximum open zones";
             u = sg_get_unaligned_be32(ucp + 8);
             jout("    %s: %u\n", q, u);
-            jglb[jname][q] = u;
+            jglb[jname][json::str2key(q)] = u;
             break;
         case 1:
             q = "Maximum explicitly open zones";
             u = sg_get_unaligned_be32(ucp + 8);
             jout("    %s: %u\n", q, u);
-            jglb[jname][q] = u;
+            jglb[jname][json::str2key(q)] = u;
             break;
         case 2:
             q = "Maximum implicitly open zones";
             u = sg_get_unaligned_be32(ucp + 8);
             jout("    %s: %u\n", q, u);
-            jglb[jname][q] = u;
+            jglb[jname][json::str2key(q)] = u;
             break;
         case 3:
             q = "Minimum empty zones";
             u = sg_get_unaligned_be32(ucp + 8);
             jout("    %s: %u\n", q, u);
-            jglb[jname][q] = u;
+            jglb[jname][json::str2key(q)] = u;
             break;
         case 4:
             q = "Maximum nonseq zones";
             u = sg_get_unaligned_be32(ucp + 8);
             jout("    %s: %u\n", q, u);
-            jglb[jname][q] = u;
+            jglb[jname][json::str2key(q)] = u;
             break;
         case 5:
             q = "Zones emptied";
             u = sg_get_unaligned_be32(ucp + 8);
             jout("    %s: %u\n", q, u);
-            jglb[jname][q] = u;
+            jglb[jname][json::str2key(q)] = u;
             break;
         case 6:
             q = "Suboptimal write commands";
             u = sg_get_unaligned_be32(ucp + 8);
             jout("    %s: %u\n", q, u);
-            jglb[jname][q] = u;
+            jglb[jname][json::str2key(q)] = u;
             break;
         case 7:
             q = "Commands exceeding optinmal limit";
             u = sg_get_unaligned_be32(ucp + 8);
             jout("    %s: %u\n", q, u);
-            jglb[jname][q] = u;
+            jglb[jname][json::str2key(q)] = u;
             break;
         case 8:
             q = "Failed explicit opens";
             u = sg_get_unaligned_be32(ucp + 8);
             jout("    %s: %u\n", q, u);
-            jglb[jname][q] = u;
+            jglb[jname][json::str2key(q)] = u;
             break;
         case 9:
             q = "Read rule violations";
             u = sg_get_unaligned_be32(ucp + 8);
             jout("    %s: %u\n", q, u);
-            jglb[jname][q] = u;
+            jglb[jname][json::str2key(q)] = u;
             break;
         case 0xa:
             q = "Write rule violations";
             u = sg_get_unaligned_be32(ucp + 8);
             jout("    %s: %u\n", q, u);
-            jglb[jname][q] = u;
+            jglb[jname][json::str2key(q)] = u;
             break;
         case 0xb:
             q = "Maximum implicitly open sequential or before required zones";
             u = sg_get_unaligned_be32(ucp + 8);
             jout("    %s: %u\n", q, u);
-            jglb[jname][q] = u;
+            jglb[jname][json::str2key(q)] = u;
             break;
         default:        /* ignore other parameter codes */
             break;
@@ -1632,223 +1639,226 @@ scsiPrintTapeDeviceStats(scsi_device * device)
         int pc = sg_get_unaligned_be16(ucp + 0);
         // pcb = ucp[2];
         int pl = ucp[3] + 4;
+        std::string s;
+
         switch (pc) {
         case 0:
             q = "Lifetime volume loads";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 1:
             q = "Lifetime cleaning operations";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 2:
             q = "Lifetime power on hours";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 3:
             q = "Lifetime medium motion hours";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 4:
             q = "Lifetime meters of tape processed";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 5:
             q = "Lifetime medium motion hours at last incompatible volume "
                 "load";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 6:
             q = "Lifetime power on hours at last temperature condition "
                 "occurrence";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 7:
             q = "Lifetime power on hours at last power consumption condition "
                 "occurrence";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 8:
             q = "Medium motion hours since last successful cleaning "
                 "operation";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 9:
             q = "Medium motion hours since second to last successful "
                 "cleaning operation";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0xa:
             q = "Medium motion hours since third to last successful "
                 "cleaning operation";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0xb:
             q = "Lifetime power on hours at last operator initiated forced "
                 "reset and/or emergency eject occurrence";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0xc:
             q = "Lifetime power cycles";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0xd:
             q = "Volume loads since last parameter reset";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0xe:
             q = "Hard write errors";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0xf:
             q = "Hard read errors";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0x10:
             q = "Duty cycle sample time";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0x11:
             q = "Read duty cycle";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0x12:
             q = "Write duty cycle";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0x13:
             q = "Activity duty cycle";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0x14:
             q = "Volume not present duty cycle";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0x15:
             q = "Ready duty cycle";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0x16:
             q = "Megabytes transferred from application client in duty cycle"
                 "sample time";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0x17:
             q = "Megabytes transferred to application client in duty cycle"
                 "sample time";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0x40:
             {
-                std::string s((const char *)(ucp + 4), ucp[3]);
+                std::string v((const char *)(ucp + 4), ucp[3]);
                 q = "Drive manufacturer's serial number";
-                jout("    %s: %s\n", q, s.c_str());
-                jglb[jname][q] = s;
+                jout("    %s: %s\n", q, v.c_str());
+                jglb[jname][json::str2key(q)] = v;
             }
             break;
         case 0x41:
             {
-                std::string s((const char *)(ucp + 4), ucp[3]);
+                std::string v((const char *)(ucp + 4), ucp[3]);
                 q = "Drive serial number";
-                jout("    %s: %s\n", q, s.c_str());
-                jglb[jname][q] = s;
+                jout("    %s: %s\n", q, v.c_str());
+                jglb[jname][json::str2key(q)] = v;
             }
             break;
         case 0x42:
             {
-                std::string s((const char *)(ucp + 4), ucp[3]);
+                std::string v((const char *)(ucp + 4), ucp[3]);
                 q = "Manufacturing date year,month,day";
-                jout("    %s: %s\n", q, s.c_str());
-                jglb[jname][q] = s;
+                jout("    %s: %s\n", q, v.c_str());
+                jglb[jname][json::str2key(q)] = v;
             }
             break;
         case 0x43:
             {
-                std::string s((const char *)(ucp + 4), ucp[3]);
+                std::string v((const char *)(ucp + 4), ucp[3]);
                 q = "Manufacturing date year,week";
-                jout("    %s: %s\n", q, s.c_str());
-                jglb[jname][q] = s;
+                jout("    %s: %s\n", q, v.c_str());
+                jglb[jname][json::str2key(q)] = v;
             }
             break;
         case 0x44:
             {
-                std::string s((const char *)(ucp + 4), ucp[3]);
+                std::string v((const char *)(ucp + 4), ucp[3]);
                 q = "Manufacturing date year,week";
-                jout("    %s: %s\n", q, s.c_str());
-                jglb[jname][q] = s;
+                jout("    %s: %s\n", q, v.c_str());
+                jglb[jname][json::str2key(q)] = v;
             }
             break;
         case 0x80:
             q = "Medium removal prevented";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0x81:
             q = "Maximum recommended mechanism temperature exceeded";
             ull = variableLengthIntegerParam(ucp);
             jout("    %s: %" PRIu64 "\n", q, ull);
-            jglb[jname][q] = ull;
+            jglb[jname][json::str2key(q)] = ull;
             break;
         case 0x1000:
             q = "Medium motion hours for each medium type";
+            s = json::str2key(q);
             n = ucp[3] / 8;
             jout("    %s, number of element: %u\n", q, n);
             for (k = 0; k < n; ++k, ucp += 8) {
                 u = sg_get_unaligned_be32(ucp + 8);
                 jout("      [%d] density code: %u, density code: %u, hours: "
                      "%u\n", k + 1, ucp[6], ucp[7], u);
-                jglb[jname][q][k]["density code"] = ucp[6];
-                jglb[jname][q][k]["medium type"] = ucp[7];
-                jglb[jname][q][k]["medium motion hours"] = u;
+                jglb[jname][s][k]["density_code"] = ucp[6];
+                jglb[jname][s][k]["medium_type"] = ucp[7];
+                jglb[jname][s][k]["medium_motion_hours"] = u;
             }
             break;
         default:        /* ignore other parameter codes */
@@ -2470,16 +2480,16 @@ static int
 scsiGetDriveInfo(scsi_device * device, uint8_t * peripheral_type,
                  bool & have_zbc, bool all)
 {
-    struct scsi_iec_mode_page iec;
-    int err, iec_err, len, req_len, avail_len;
     bool ok;
     bool is_tape = false;
+    int err, iec_err, len, req_len, avail_len;
     int peri_dt = 0;
     int transport = -1;
     int form_factor = 0;
     int haw_zbc = 0;
     int protect = 0;
     const char * q;
+    struct scsi_iec_mode_page iec;
 
     memset(gBuf, 0, 96);
     have_zbc = false;
@@ -2717,12 +2727,12 @@ scsiGetDriveInfo(scsi_device * device, uint8_t * perip
             have_zbc = true;
             q = "Host aware zoned block capable";
             jout("%s\n", q);
-            jglb[std::string("scsi_") + q] = true;
+            jglb[std::string("scsi_") + json::str2key(q)] = true;
         } else if (haw_zbc == 2) {
             have_zbc = true;
             q = "Device managed zoned block capable";
             jout("%s\n", q);
-            jglb[std::string("scsi_") + q] = true;
+            jglb[std::string("scsi_") + json::str2key(q)] = true;
         } else {
             supported_vpd_pages * s_vpd_pp = supported_vpd_pages_p;
 
@@ -3009,6 +3019,7 @@ scsiPrintEnviroReporting(scsi_device * device)
         int pc = sg_get_unaligned_be16(ucp + 0);
         int pl = ucp[3] + 4;
         char pc_s[32];
+        std::string s;
 
         if ((pc < 0x100) && (pl == 12)) {
             snprintf(pc_s, sizeof(pc_s), "temperature_%d", ++temp_num);
@@ -3017,67 +3028,74 @@ scsiPrintEnviroReporting(scsi_device * device)
 
             jglb[jname][pc_s]["parameter_code"] = pc;
             q = "Current";
+            s = json::str2key(q);
             if (ucp[5] == 0x80) {
                 jout("%s %s = %s\n", q, temp_n, unkn_n);
-                jglb[jname][pc_s][q] = unkn_n;
+                jglb[jname][pc_s][s] = unkn_n;
             } else {
                 jout("%s %s = %d\n", q, temp_n, temp);
-                jglb[jname][pc_s][q] = temp;
+                jglb[jname][pc_s][s] = temp;
             }
             temp = (int)(int8_t)ucp[6];
             q = "Lifetime maximum";
+            s = json::str2key(q);
             if (ucp[6] == 0x80) {
                 jout("%s %s = %s\n", q, temp_n, unkn_n);
-                jglb[jname][pc_s][q] = unkn_n;
+                jglb[jname][pc_s][s] = unkn_n;
             } else {
                 jout("%s %s = %d\n", q, temp_n, temp);
-                jglb[jname][pc_s][q] = temp;
+                jglb[jname][pc_s][s] = temp;
             }
             temp = (int)(int8_t)ucp[7];
             q = "Lifetime minimum";
+            s = json::str2key(q);
             if (ucp[7] == 0x80) {
                 jout("%s %s = %s\n", q, temp_n, unkn_n);
-                jglb[jname][pc_s][q] = unkn_n;
+                jglb[jname][pc_s][s] = unkn_n;
             } else {
                 jout("%s %s = %d\n", q, temp_n, temp);
-                jglb[jname][pc_s][q] = temp;
+                jglb[jname][pc_s][s] = temp;
             }
             temp = (int)(int8_t)ucp[8];
             q = "Maximum since power on";
+            s = json::str2key(q);
             if (ucp[8] == 0x80) {
                 jout("Maximum %s %s = %s\n", temp_n, sop_n, unkn_n);
-                jglb[jname][pc_s][q] = unkn_n;
+                jglb[jname][pc_s][s] = unkn_n;
             } else {
                 jout("Maximum %s %s = %d\n", temp_n, sop_n, temp);
-                jglb[jname][pc_s][q] = temp;
+                jglb[jname][pc_s][s] = temp;
             }
             temp = (int)(int8_t)ucp[9];
             q = "Minimum since power on";
+            s = json::str2key(q);
             if (ucp[9] == 0x80) {
                 jout("Minimum %s %s = %s\n", temp_n, sop_n, unkn_n);
-                jglb[jname][pc_s][q] = unkn_n;
+                jglb[jname][pc_s][s] = unkn_n;
             } else {
                 jout("Minimum %s %s = %d\n", temp_n, sop_n, temp);
-                jglb[jname][pc_s][q] = temp;
+                jglb[jname][pc_s][s] = temp;
             }
             if ((ucp[4] & 0x3) == 1) {  /* OTV field set to 1 */
                 temp = (int)(int8_t)ucp[10];
                 q = "Maximum other";
+                s = json::str2key(q);
                 if (ucp[10] == 0x80) {
                     jout("%s %s = %s\n", q, temp_n, unkn_n);
-                    jglb[jname][pc_s][q] = unkn_n;
+                    jglb[jname][pc_s][s] = unkn_n;
                 } else {
                     jout("%s %s = %d\n", q, temp_n, temp);
-                    jglb[jname][pc_s][q] = temp;
+                    jglb[jname][pc_s][s] = temp;
                 }
                 temp = (int)(int8_t)ucp[11];
                 q = "Minimum other";
+                s = json::str2key(q);
                 if (ucp[11] == 0x80) {
                     jout("%s %s = %s\n", q, temp_n, unkn_n);
-                    jglb[jname][pc_s][q] = unkn_n;
+                    jglb[jname][pc_s][s] = unkn_n;
                 } else {
                     jout("%s %s = %d\n", q, temp_n, temp);
-                    jglb[jname][pc_s][q] = temp;
+                    jglb[jname][pc_s][s] = temp;
                 }
             }
         } else if ((pc < 0x200) && (pl == 12)) {
@@ -3086,22 +3104,26 @@ scsiPrintEnviroReporting(scsi_device * device)
             jout("Relative humidity = %u\n", ucp[5]);
             jglb[jname][pc_s]["current"] = ucp[5];
             q = "Lifetime maximum";
+            s = json::str2key(q);
             jout("%s %s = %d\n", q, rh_n, ucp[6]);
-            jglb[jname][pc_s][q] = ucp[6];
+            jglb[jname][pc_s][s] = ucp[6];
             q = "Lifetime minimum";
+            s = json::str2key(q);
             jout("%s %s = %d\n", q, rh_n, ucp[7]);
-            jglb[jname][pc_s][q] = ucp[7];
+            jglb[jname][pc_s][s] = ucp[7];
             jout("Maximum %s %s = %d\n", rh_n, sop_n, ucp[8]);
             jglb[jname][pc_s]["maximum_since_power_on"] = ucp[8];
             jout("Minimum %s %s = %d\n", rh_n, sop_n, ucp[9]);
             jglb[jname][pc_s]["minimum_since_power_on"] = ucp[9];
             if ((ucp[4] & 0x3) == 1) {  /* ORHV field set to 1 */
                 q = "Maximum other";
+                s = json::str2key(q);
                 jout("%s %s = %d\n", q, rh_n, ucp[10]);
-                jglb[jname][pc_s][q] = ucp[10];
+                jglb[jname][pc_s][s] = ucp[10];
                 q = "Minimum other";
+                s = json::str2key(q);
                 jout("%s %s = %d\n", q, rh_n, ucp[11]);
-                jglb[jname][pc_s][q] = ucp[11];
+                jglb[jname][pc_s][s] = ucp[11];
             }
         } else {
             if (scsi_debugmode > 0) {
@@ -3428,7 +3450,8 @@ scsiPrintMain(scsi_device * device, const scsi_print_o
             res = scsiPrintSelfTest(device);
         else {
             pout("Device does not support Self Test logging\n");
-            failuretest(OPTIONAL_CMD, returnval|=FAILSMART);
+            if (! is_tape)
+                failuretest(OPTIONAL_CMD, returnval|=FAILSMART);
         }
         if (0 != res)
             failuretest(OPTIONAL_CMD, returnval|=res);
