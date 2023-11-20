post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rsyslog.d
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${MV} ${STAGEDIR}${PREFIX}/bin/proxy ${STAGEDIR}${PREFIX}/bin/rsync-proxy
	${INSTALL_DATA} ${WRKSRC}/build/freebsd/usr/local/etc/newsyslog.conf.d/rsync-proxy.conf ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d
	${INSTALL_SCRIPT} ${WRKSRC}/build/freebsd/usr/local/etc/rc.d/rsync_proxy ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/build/freebsd/usr/local/etc/rsyslog.d/rsync-proxy.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${INSTALL_DATA} ${WRKSRC}/build/freebsd/usr/local/etc/rsync-proxy/rsync-proxy.yml.example  ${STAGEDIR}${ETCDIR}/rsync-proxy.yml.sample
