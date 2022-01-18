# $FreeBSD$

PORTNAME=	vdisk-fuse
DISTVERSION?=	1.0.4.5
PORTREVISION?=	0
CATEGORIES=	axcient sysutils
MASTER_SITES=	GH

MAINTAINER=	abuluy@axcient.com
COMMENT?=	Vdisk-fuse is utility to wrap blockdevice to disk images format.

RUN_DEPENDS=	fusefs-libs:sysutils/fusefs-libs

USES=		axcient fuse cmake pkgconfig
GH_PROJECT=	vdisk-fuse
GH_TAGNAME?=	${PORTVERSION}

CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE=ON -DUSE_FAST_SPARSE=OFF

do-install:
	echo "Installing"
	${INSTALL} ${WRKDIR}/vdisk-fuse/vdisk-fuse ${STAGEDIR}${PREFIX}/bin/vdisk-fuse
	${INSTALL} ${WRKDIR}/src/libvdisk.so ${STAGEDIR}${PREFIX}/lib/libvdisk.so

.include <bsd.port.mk>

