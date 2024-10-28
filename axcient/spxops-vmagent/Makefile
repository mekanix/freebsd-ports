# $FreeBSD$

PORTNAME=	spxops-vmagent
PORTVERSION=	1.0.0.20241028
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
USES=		axcient python:3.9+,run shebangfix
SUB_FILES=	501.spxops

SHEBANG_FILES=	bin/spxops-audit

GH_TAGNAME=	b09660c2199c905209c6aea98a8c68689c6d7719

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PLIST_FILES=	sbin/efs-vm-create \
		${DATADIR}/efs-common.sh \
		/opt/efs/bin/efs-vm-create \
		sbin/spxops-audit \
		etc/periodic/weekly/501.spxops

PLIST_DIRS=	${ETCDIR} /opt/efs/bin /opt/efs /opt

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/weekly
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/efs-vm-create ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/spxops-audit ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/501.spxops ${STAGEDIR}${PREFIX}/etc/periodic/weekly
	${INSTALL_DATA} ${WRKSRC}/lib/efs-common.sh ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}/opt/efs/bin
	${LN} -s ${PREFIX}/sbin/efs-vm-create ${STAGEDIR}/opt/efs/bin/efs-vm-create
	${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
