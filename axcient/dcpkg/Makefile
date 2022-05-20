# $FreeBSD$

PORTNAME=	dcpkg
PORTVERSION?=	1.0.5

CATEGORIES=	axcient
MASTER_SITES=	GH

MAINTAINER=	ipankov@axcient.com
COMMENT=	Datacenter scripts for direct BRC offsiting

RUN_DEPENDS=	rsync:net/rsync

USES=		axcient gmake
GH_PROJECT=	ax-dcpkg
GH_TAGNAME?=	${PORTVERSION}

CONFLICTS_INSTALL?=	dcpkg-stg

AXUSER=		axsvcid

do-install:
	echo "Installing"
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/axcient
	${INSTALL_SCRIPT} ${WRKSRC}/rsync.stage2 ${STAGEDIR}${PREFIX}/libexec/axcient/rsync.stage2
	${INSTALL_SCRIPT} ${WRKSRC}/rsync ${STAGEDIR}${PREFIX}/libexec/axcient/rsync
	${INSTALL_SCRIPT} ${WRKSRC}/service_tool.sh ${STAGEDIR}${PREFIX}/libexec/axcient/service_tool.sh
	${INSTALL_SCRIPT} ${WRKSRC}/check_offsite_allowability ${STAGEDIR}${PREFIX}/libexec/axcient/check_offsite_allowability
	${INSTALL_PROGRAM} ${WRKSRC}/ax-mount-tools/axl/axl ${STAGEDIR}${PREFIX}/libexec/axcient/axl
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/axcient
	${CP} ${WRKSRC}/ax.conf ${STAGEDIR}${PREFIX}/etc/axcient/ax.conf.sample
	${MKDIR} ${STAGEDIR}/${PREFIX}/etc/sudoers.d
	${ECHO_CMD} "${AXUSER} ALL=NOPASSWD: ${PREFIX}/libexec/axcient/service_tool.sh" > ${STAGEDIR}/${PREFIX}/etc/sudoers.d/dcpkg

.include <bsd.port.mk>
