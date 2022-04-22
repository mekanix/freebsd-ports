post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/newsyslog.conf.d/dralserver.conf ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d
	${INSTALL_SCRIPT} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/rc.d/dralserver ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/rsyslog.d/dralserver.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/dralserver/dralserver.yml.example  ${STAGEDIR}${ETCDIR}/dralserver.yml.sample
