# $FreeBSD$

PORTNAME=	libzfs_core
# The real Python library version is defined by SRC_BASE.
# The port version is not related, unfortunately.
PORTVERSION=	1.0.0
CATEGORIES=	filesystems python
MASTER_SITES=	# empty
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Python libzfs_core bindings

LICENSE=	APACHE20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	MAKE=gmake --prefix=${PREFIX} --with-config="user"
CONFIGURE_ARGS+=	--with-python=${PYTHON_VER}
USES=		autoreconf:build libtool python gmake
USE_PYTHON=	autoplist distutils

# openzfs also installs py-libzfs_core bindings
CONFLICTS=	openzfs

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sysctl>0:devel/py-sysctl@${PY_FLAVOR}

BUILD_WRKSRC=	${WRKSRC}/contrib/pyzfs
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1300000
IGNORE=	needs FreeBSD 13 with OpenZFS
.endif

.if ${OSVERSION} < 1400000
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-contrib_pyzfs_libzfs__core_bindings_____init____.py
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=	requires kernel source files in ${SRC_BASE}
.endif

do-extract:
	@${CP} -a ${SRC_BASE}/sys/contrib/openzfs ${WRKSRC}

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.if ${OSVERSION} > 1400000
pre-build:
	cd ${WRKSRC} && gmake pyzfs-all-local
.endif
.include <bsd.port.post.mk>
