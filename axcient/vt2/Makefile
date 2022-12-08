# $FreeBSD$

PORTNAME=	vt2
PORTVERSION?=	1.1.6
PORTREVISION?=	0
CATEGORIES=	axcient
MASTER_SITES=	GH

MAINTAINER=	dprokopchenkov@axcient.com
COMMENT?=	Vault Transfer 2

SZS_LIB_DEPENDS?= libszs-op.so:axcient/szs
LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd \
		libgnutls.so:security/gnutls \
		libunistring.so:devel/libunistring \
		libtasn1.so:security/libtasn1 \
		libnettle.so:security/nettle \
		libhogweed.so:security/nettle \
		libgmp.so:math/gmp \
		libidn2.so:dns/libidn2 \
		${SZS_LIB_DEPENDS}

# I'm skeptical that ca_root_nss is really needed, but it was specified as a
# dependency in the prior version of the package at
# https://raw.githubusercontent.com/Axcient/vaulttransfer2/6d5d3224796695bf163b9e6d37fe089f2b4109af/freebsd-pkg/%2BMANIFEST?token=AAA7VONVI376NMBQPJLHG6K6T4YLG
RUN_DEPENDS+=	ca_root_nss>0:security/ca_root_nss

USES+=		axcient gmake
GH_PROJECT=	vaulttransfer2
GH_TAGNAME?=     1.1.6

CONFLICTS_INSTALL?=	vt2-stg

MAKE_JOBS_UNSAFE=yes
ALL_TARGET=	server
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES?=   bin/vaulttransferserver2 \
	       "@sample ${EXAMPLESDIR}/newsyslog.conf etc/newsyslog.conf.d/vt2.conf" \
	       etc/rc.d/vt2 \
	       "@sample ${EXAMPLESDIR}/rsyslog.conf etc/rsyslog.d/vt2.conf" \
	       "@dir etc/rsyslog.d"

EXTRA_PATCHES?= ${PATCHDIR}/extra-patch-Makefile

.  if !target(do-install)
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rsyslog.d
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/vaulttransferserver2 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/newsyslog.conf.d/vt2.conf ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-pkg/usr/local/etc/rc.d/vt2 ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/rsyslog.d/vt2.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.conf
.  endif

.include <bsd.port.mk>
