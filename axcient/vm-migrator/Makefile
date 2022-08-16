# $FreeBSD$

PORTNAME=	vm-migrator
PORTVERSION=	0.1.1.20220816
CATEGORIES=	axcient
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jsollvander@axcient.com
COMMENT=	VM and VM storage migration tool

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libvirt>=0:devel/py-libvirt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}migration-tools>=0.1.0.20220803:axcient/migration-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}axcient-helpers>=0:axcient/py-axcient-helpers@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

GH_PROJECT=	vm-migrator
GH_TAGNAME=	826238cba0223a664f22f6359eb2a4e2444f025b

.include <bsd.port.mk>
