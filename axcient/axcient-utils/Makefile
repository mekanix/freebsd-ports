# $FreeBSD$

PORTNAME=	axcient-utils
PORTVERSION=	1.0.0.20240917
CATEGORIES=	axcient sysutils
MASTER_SITES=	GH

MAINTAINER=	asomers@axcient.com
COMMENT=	Miscellaneous utilities for Axcient FreeBSD servers

LICENSE=	AXCIENT
LICENSE_NAME=	AXCIENT
LICENSE_TEXT=	"Copyright Axcient, inc.  All Rights Reserved"
LICENSE_PERMS=	pkg-mirror  # Not really, only since our pkg server is private

RUN_DEPENDS=	bash:shells/bash \
		salt-call:sysutils/py-salt \
		${PYTHON_PKGNAMEPREFIX}libzfs>=0:devel/py-libzfs@${PY_FLAVOR}

NO_ARCH=	yes
NO_BUILD=	yes
USES=		axcient python:3.8+,run shebangfix
GH_PROJECT=	freebsd-utils
GH_TAGNAME=	c850020258809040f87bb2e947ca0ce344236c74

SUB_FILES=	399.explorer
USE_RC_SUBR=	automultipath geli_salt zfs_crypto_salt

SHEBANG_FILES=	jbod-support/jbod-util

PLIST_FILES=	sbin/geli-util
PLIST_FILES+=	sbin/jbod-util
PLIST_FILES+=	sbin/jbod-devd
PLIST_FILES+=	sbin/jailinit
PLIST_FILES+=	sbin/jailcreate
PLIST_FILES+=	sbin/jaildestroy
PLIST_FILES+=	sbin/jailupdate
PLIST_FILES+=	sbin/jailupgrade
PLIST_FILES+=	etc/periodic/weekly/399.explorer
PLIST_FILES+=	etc/devd/automultipath.conf
PLIST_FILES+=	sbin/gentle-destroy
PLIST_FILES+=	sbin/hbaerrs

PLIST_DIRS=	/var/explorer

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/geli/geli-util ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/jbod-support/jbod-util ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/jbod-support/jbod-devd.sh ${STAGEDIR}${PREFIX}/sbin/jbod-devd
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} ${WRKSRC}/jbod-support/automultipath.conf ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_SCRIPT} ${WRKSRC}/hbaerrs.sh ${STAGEDIR}${PREFIX}/sbin/hbaerrs
	${INSTALL_SCRIPT} ${WRKSRC}/gentle-destroy.sh ${STAGEDIR}${PREFIX}/sbin/gentle-destroy
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/weekly
	@${MKDIR} ${STAGEDIR}/var/explorer
	${INSTALL_SCRIPT} ${WRKDIR}/399.explorer ${STAGEDIR}${PREFIX}/etc/periodic/weekly
	${INSTALL_SCRIPT} ${WRKSRC}/jail/jailinit ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/jail/jailcreate ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/jail/jaildestroy ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/jail/jailupdate ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/jail/jailupgrade ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
