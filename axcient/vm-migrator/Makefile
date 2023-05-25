# $FreeBSD$

PORTNAME=	vm-migrator
PORTVERSION=	0.1.1.20230525
CATEGORIES=	axcient
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jsollvander@axcient.com
COMMENT=	VM and VM storage migration tool

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libvirt>=0:devel/py-libvirt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}migration-tools>=0.1.0.20230525:axcient/migration-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}axcient-helpers>=0:axcient/py-axcient-helpers@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

GH_PROJECT=	vm-migrator
GH_TAGNAME=	259ac8c119f569ce5fc9dd3e5b6485b2014c4cc7

.include <bsd.port.mk>
