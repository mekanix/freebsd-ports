# $FreeBSD$

PORTNAME=	axcient-utils
PORTVERSION=	1.0.0.20220504
CATEGORIES=	axcient sysutils
MASTER_SITES=	GH

MAINTAINER=	asomers@axcient.com
COMMENT=	Miscellaneous utilities for Axcient FreeBSD servers

LICENSE=	AXCIENT
LICENSE_NAME=	AXCIENT
LICENSE_TEXT=	"Copyright Axcient, inc.  All Rights Reserved"
LICENSE_PERMS=	pkg-mirror  # Not really, only since our pkg server is private

RUN_DEPENDS=	bash:shells/bash \
		salt-call:sysutils/py-salt

NO_ARCH=	yes
NO_BUILD=	yes
USES=		axcient python:3.8+,run shebangfix
GH_PROJECT=	freebsd-utils
GH_TAGNAME=	f73a604f0af902e97d78b8ca883338d0b37aa3f4

SUB_FILES=	399.explorer
USE_RC_SUBR=	geli_salt zfs_crypto_salt

SHEBANG_FILES=	jbod-support/jbod-util

PLIST_FILES=	sbin/geli-util
PLIST_FILES+=	sbin/jbod-util
PLIST_FILES+=	etc/periodic/weekly/399.explorer
PLIST_FILES+=	sbin/gentle-destroy
PLIST_FILES+=	sbin/hbaerrs

PLIST_DIRS=	/var/explorer

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/geli/geli-util ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/jbod-support/jbod-util ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/hbaerrs.sh ${STAGEDIR}${PREFIX}/sbin/hbaerrs
	${INSTALL_SCRIPT} ${WRKSRC}/gentle-destroy.sh ${STAGEDIR}${PREFIX}/sbin/gentle-destroy
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/weekly
	@${MKDIR} ${STAGEDIR}/var/explorer
	${INSTALL_SCRIPT} ${WRKDIR}/399.explorer ${STAGEDIR}${PREFIX}/etc/periodic/weekly

.include <bsd.port.mk>
