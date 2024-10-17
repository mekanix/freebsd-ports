--- daemon/pruner/pruner.go.orig	2024-10-17 09:49:23 UTC
+++ daemon/pruner/pruner.go
@@ -17,6 +17,7 @@ import (
 	"github.com/zrepl/zrepl/pruning"
 	"github.com/zrepl/zrepl/replication/logic/pdu"
 	"github.com/zrepl/zrepl/util/envconst"
+	"github.com/zrepl/zrepl/zfs"
 )
 
 // The sender in the replication setup.
@@ -563,7 +564,10 @@ func doOneAttemptExec(a *args, u updater, pfs *fs) {
 			err = fmt.Errorf("missing destroy-result for %s", reqDestroy.RelName())
 			break
 		} else if res.Error != "" {
-			destroyFails = append(destroyFails, res)
+			holds, err := zfs.ZFSHolds(a.ctx, req.Filesystem, reqDestroy.Name)
+			if !(err == nil && len(holds) > 0) {
+				destroyFails = append(destroyFails, res)
+			}
 		}
 	}
 	if err == nil && len(destroyFails) > 0 {
