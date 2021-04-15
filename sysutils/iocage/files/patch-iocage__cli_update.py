--- iocage_cli/update.py.orig	2021-02-26 01:20:44 UTC
+++ iocage_cli/update.py
@@ -38,8 +38,16 @@ __rootcmd__ = True
     help='Decide whether or not to update the pkg repositories and '
          'all installed packages in jail( this has no effect for plugins ).'
 )
+@click.option(
+    "--server", "-s", default="download.freebsd.org",
+    help="Server to fetch from."
+)
+@click.option(
+    "--verify/--noverify", "-V/-NV", default=True,
+    help="Enable or disable verifying SSL cert for HTTP fetching."
+)
 @click.argument('jail', required=True)
-def cli(jail, pkgs):
+def cli(jail, **kwargs):
     """Update the supplied jail to the latest patchset"""
     skip_jails = bool(jail != 'ALL')
-    ioc.IOCage(jail=jail, skip_jails=skip_jails).update(pkgs=pkgs)
+    ioc.IOCage(jail=jail, skip_jails=skip_jails).update(**kwargs)
