PORTNAME=	szs-migrator
PORTVERSION=	0.1.0
CATEGORIES=	axcient
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	asomers@axcient.com
COMMENT=	Replibit dataset migrator

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=5.0.0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libzfs>=0:devel/py-libzfs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=0:net/urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils
WRKSRC_SUBDIR=	szs/maintenance-tool

NO_ARCH=	yes

GH_PROJECT=	replibit-tools
GH_TAGNAME=	szs-migrator-0.1.0

do-test:
	cd ${WRKSRC} && pytest

.include <bsd.port.mk>
