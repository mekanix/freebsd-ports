# $FreeBSD$

PORTNAME=	smart-recovery
DISTVERSION?=	1.2.0
PORTREVISION?=	0
CATEGORIES=	axcient sysutils
MASTER_SITES=	GH

MAINTAINER=	kgermanov@axcient.com
COMMENT?=	Replibit smart recovery tool

USES=		axcient fuse cmake pkgconfig
GH_PROJECT=	smart-recovery
GH_TAGNAME?=	1.2.0

BUILD_DEPENDS=	boost-libs>=1.72:devel/boost-libs

PLIST_FILES=	bin/smart_recovery

CONFLICTS_INSTALL?=      smart-recovery-stg

CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE=ON -DUSE_CHECKS=OFF

do-install:
	${INSTALL} ${WRKDIR}/.build/smart_recovery/smart_recovery ${STAGEDIR}${PREFIX}/bin/smart_recovery

.include <bsd.port.mk>
