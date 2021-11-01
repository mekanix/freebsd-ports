PORTNAME=	szs-migrator
PORTVERSION=	0.1.0.20211025
PORTREVISION=	1
CATEGORIES=	axcient
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	asomers@axcient.com
COMMENT=	Replibit dataset migrator

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=5.0.0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libzfs>=0:devel/py-libzfs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils
WRKSRC_SUBDIR=	szs/maintenance-tool
SUB_FILES=	900.szs-audit

NO_ARCH=	yes

GH_PROJECT=	replibit-tools
GH_TAGNAME=	b20cd122f783ab6fb1607ce72b399a0e4b49ffd3

PLIST_FILES+=	etc/periodic/weekly/900.szs-audit

do-test:
	cd ${WRKSRC} && pytest

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/weekly
	${INSTALL_SCRIPT} ${WRKDIR}/900.szs-audit ${STAGEDIR}${PREFIX}/etc/periodic/weekly

.include <bsd.port.mk>
