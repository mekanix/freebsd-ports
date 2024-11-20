PORTNAME=	migration-tools
PORTVERSION=	0.1.0.20231116
CATEGORIES=	axcient
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jsollvander@axcient.com
COMMENT=	ZFS dataset migrator code

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libzfs>=0:filesystems/py-libzfs@${PY_FLAVOR} \

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils

.include <bsd.port.options.mk>

NO_ARCH=	yes

GH_PROJECT=	migration-tools
GH_TAGNAME=	65a59fe369373c297d61976ecdac0b8b88113fc6


do-test:
	cd ${WRKSRC} && pytest


.include <bsd.port.mk>
