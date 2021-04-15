# $FreeBSD$

PORTNAME=	spxops-vmagent
PORTVERSION=	1.0.0.20210104
CATEGORIES=	axcient sysutils
MASTER_SITES=	GH

MAINTAINER=	asomers@axcient.com
COMMENT=	Storage-side helpers for SPXOps

LICENSE=	AXCIENT
LICENSE_NAME=	AXCIENT
LICENSE_TEXT=	"Copyright Axcient, inc.  All Rights Reserved"
LICENSE_PERMS=	pkg-mirror  # Not really, only since our pkg server is private

RUN_DEPENDS=	bash:shells/bash

NO_ARCH=	yes
NO_BUILD=	yes
USES=		axcient
GH_TAGNAME=	633d4c9eb69775b817772a23f0cdc3dbfde7a16c

PLIST_FILES=	sbin/efs-vm-create ${DATADIR}/efs-common.sh /opt/efs/bin/efs-vm-create
PLIST_DIRS=	${ETCDIR} /opt/efs/bin /opt/efs /opt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/efs-vm-create ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/efs-common.sh ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}/opt/efs/bin
	${LN} -s ${PREFIX}/sbin/efs-vm-create ${STAGEDIR}/opt/efs/bin/efs-vm-create
	${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
