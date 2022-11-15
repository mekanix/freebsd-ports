# $FreeBSD$

PORTNAME=	filestore-clone
PORTVERSION=	0.4.5
PORTREVISION=	2
CATEGORIES=	axcient sysutils
MASTER_SITES=	GH
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	asomers@axcient.com
COMMENT=	Replicates a local file system to a cloud destination

LICENSE=	AXCIENT
LICENSE_NAME=	AXCIENT
LICENSE_TEXT=	"Copyright Axcient, inc.  All Rights Reserved"
LICENSE_PERMS=	pkg-mirror  # Not really, only since our pkg server is private

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fusepy>0:devel/py-fusepy@${PY_FLAVOR}

NO_ARCH=	yes
NO_BUILD=	yes
USES=		axcient python:3.8+
USE_PYTHON=	autoplist distutils

GH_TAGNAME=	v${PORTVERSION}

PLIST_FILES=	${PREFIX}/libexec/${PORTNAME}/cron-clone-anchor-filestore.sh \
		${PREFIX}/libexec/${PORTNAME}/cron-clone-anchor-all.sh
PLIST_DIRS=	/var/db/${PORTNAME} \
		/var/log/${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/cron-clone-anchor-all.sh ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/cron-clone-anchor-filestore.sh ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/

.include <bsd.port.mk>
