# $FreeBSD$

PORTNAME=	vdisk-fuse
DISTVERSION=	1.1.0
PORTREVISION?=	1
CATEGORIES=	axcient sysutils
MASTER_SITES=	GH

MAINTAINER=	abuluy@axcient.com
COMMENT=	Vdisk-fuse is utility to wrap blockdevice to disk images format.

USES=		axcient fuse cmake pkgconfig
GH_PROJECT=	vdisk-fuse
GH_TAGNAME?=	vdisk_fuse-${DISTVERSION}

CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE=ON
PLIST_FILES=    bin/vdisk-fuse \
		lib/libvdisk.so \
		lib/liblibfsntfs.so \
		lib/liblibbfio.so

CONFLICTS_INSTALL?=	vdisk-fuse-stg

do-install:
	echo "Installing to ${PREFIX}"
	${INSTALL} ${WRKDIR}/.build/vdisk-fuse/vdisk-fuse ${STAGEDIR}${PREFIX}/bin/vdisk-fuse
	${INSTALL} ${WRKDIR}/.build/src/libvdisk.so ${STAGEDIR}${PREFIX}/lib/libvdisk.so
	${INSTALL} ${WRKDIR}/.build/src/libvdisk.so ${STAGEDIR}${PREFIX}/lib/libvdisk.so
	${INSTALL} ${WRKDIR}/.build/3rdparty/fs/liblibfsntfs.so ${STAGEDIR}${PREFIX}/lib/liblibfsntfs.so
	${INSTALL} ${WRKDIR}/.build/3rdparty/fs/liblibbfio.so ${STAGEDIR}${PREFIX}/lib/liblibbfio.so

.include <bsd.port.mk>
