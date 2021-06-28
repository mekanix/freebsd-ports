# Created by: Max Khon

PORTNAME=	ntfs
PORTVERSION=	2017.3.23
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://tuxera.com/opensource/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	${PORTNAME}-3g_ntfsprogs-${PORTVERSION}

MAINTAINER=	freebsd@dussan.org
COMMENT=	Mount NTFS partitions (read/write) and disk images

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

CONFLICTS_BUILD=	bonobo-1.*
CONFLICTS_INSTALL=	ntfsprogs-*

USES=		fuse pkgconfig iconv libtool localbase:ldflags tar:tgz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} --disable-mount-helper \
		--disable-mtab --with-fuse=external --disable-ldconfig
CPPFLAGS+=	-I${WRKSRC}/include/ntfs-3g/

OPTIONS_DEFINE=	LOCK UBLIO DOCS DEVOFFSET
OPTIONS_DEFAULT=LOCK UBLIO DEVOFFSET
LOCK_DESC=	Lock the device when mounting (avoids access)
LOCK_CFLAGS=	-DUSE_LOCK
UBLIO_DESC=	Enable user space cache for improved speed
UBLIO_EXTRA_PATCHES=	${FILESDIR}/extra-patch-ublio
UBLIO_LIB_DEPENDS=	libublio.so:devel/libublio
UBLIO_CFLAGS=	-DUSE_UBLIO

DEVOFFSET_DESC=	Enable mount option dev_offset
EXTRA_PATCHES += ${FILESDIR}/extra-patch-libntfs-3g__unix_io.c \
		${FILESDIR}/extra-patch-libntfs-3g__device.c
DEVOFFSET_EXTRA_PATCHES= ${FILESDIR}/extra-patch-dev_offset

SUB_FILES=	pkg-message
DOCSDIR=	${PREFIX}/share/doc/ntfs-3g

post-patch:
	@${REINPLACE_CMD} -e 's|ENODATA|ENOATTR|' \
		${WRKSRC}/libntfs-3g/object_id.c \
		${WRKSRC}/libntfs-3g/reparse.c \
		${WRKSRC}/libntfs-3g/security.c
	@${REINPLACE_CMD} -e 's|\($$(AM_CFLAGS)\) \(-I$$(top_srcdir)/include/ntfs-3g\)|\2 \1|; \
		/install-exec-hook:/,/^$$/ s|^@.*||' ${WRKSRC}/libntfs-3g/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libntfs-3g.so

post-install-DOCS-on:
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
