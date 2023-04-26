post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/cron.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rsyslog.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/szs
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/cron.d
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${MV} ${STAGEDIR}${PREFIX}/bin/api ${STAGEDIR}${PREFIX}/bin/szs-op
	${MV} ${STAGEDIR}${PREFIX}/bin/jobs ${STAGEDIR}${PREFIX}/bin/szs-op-jobs
	${MV} ${STAGEDIR}${PREFIX}/bin/safetyarchivecleanup ${STAGEDIR}${PREFIX}/bin/szs-op-safety-archive-cleanup
	${MV} ${STAGEDIR}${PREFIX}/bin/cleanupclones ${STAGEDIR}${PREFIX}/bin/szs-op-cleanup-clones
	${MV} ${STAGEDIR}${PREFIX}/bin/statistics ${STAGEDIR}${PREFIX}/bin/szs-op-statistics
	${MV} ${STAGEDIR}${PREFIX}/bin/snapshotscleanup ${STAGEDIR}${PREFIX}/bin/szs-op-snapshots-cleanup
	${MV} ${STAGEDIR}${PREFIX}/bin/clonesnapshots ${STAGEDIR}${PREFIX}/bin/szs-op-clone-snapshots
	${INSTALL_LIB} ${WRKDIR}/lib/libszs-op.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/lib/libszs-op.h ${STAGEDIR}${PREFIX}/include/szs-op.h
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/cron.d/safety_archive_cleanup ${STAGEDIR}${EXAMPLESDIR}/cron.d/
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/cron.d/cleanup_clones ${STAGEDIR}${EXAMPLESDIR}/cron.d/
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/cron.d/statistics ${STAGEDIR}${EXAMPLESDIR}/cron.d/
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/cron.d/snapshots_cleanup ${STAGEDIR}${EXAMPLESDIR}/cron.d/
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/cron.d/clone_snapshots ${STAGEDIR}${EXAMPLESDIR}/cron.d/
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/newsyslog.conf.d/szs.conf ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d/
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/newsyslog.conf.d/szs_jobs.conf ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d/
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-pkg/usr/local/etc/rc.d/szs ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-pkg/usr/local/etc/rc.d/szs_jobs ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/rsyslog.d/szs.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d/
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/rsyslog.d/szs_jobs.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d/
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/rsyslog.d/cleanup_clones.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d/
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/rsyslog.d/safety_archive_cleanup.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d/
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/rsyslog.d/snapshots_cleanup.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d/
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/rsyslog.d/clone_snapshots.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d/
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/rsyslog.d/statistics.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d/
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/szs/config.yml.example ${STAGEDIR}${PREFIX}/etc/szs/config.yml.sample

