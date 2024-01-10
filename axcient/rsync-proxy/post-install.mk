post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MV} ${STAGEDIR}${PREFIX}/bin/proxy ${STAGEDIR}${PREFIX}/bin/rsync-proxy
	${INSTALL_SCRIPT} ${WRKSRC}/build/freebsd/usr/local/etc/rc.d/rsync_proxy ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/build/freebsd/usr/local/etc/rsync-proxy/rsync-proxy.yml.example  ${STAGEDIR}${ETCDIR}/rsync-proxy.yml.sample
