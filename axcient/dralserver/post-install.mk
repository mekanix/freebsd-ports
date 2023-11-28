post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rsyslog.d
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${MV} ${STAGEDIR}${PREFIX}/bin/cleanupdralclones ${STAGEDIR}${PREFIX}/bin/dralserver-cleanup-clones
	${INSTALL_SCRIPT} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/rc.d/dralserver ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/rsyslog.d/dralserver.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/rsyslog.d/dralserver-cleanup-clones.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/dralserver/dralserver.yml.example  ${STAGEDIR}${ETCDIR}/dralserver.yml.sample

