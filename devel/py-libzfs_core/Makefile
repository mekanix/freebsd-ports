# $FreeBSD$

PORTNAME=	libzfs_core
# The real library version is defined by SRC_BASE
PORTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	# empty
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Python libzfs_core bindings

LICENSE=	APACHE20

GNU_CONFIGURE=	yes
USES=		autoreconf:build libtool python
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

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=	requires kernel source files in ${SRC_BASE}
.endif

do-extract:
	@${CP} -a ${SRC_BASE}/sys/contrib/openzfs ${WRKSRC}

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.post.mk>
