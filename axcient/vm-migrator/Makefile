# $FreeBSD$

PORTNAME=	vm-migrator
PORTVERSION=	0.1.1.20241213
CATEGORIES=	axcient
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jsollvander@axcient.com
COMMENT=	VM and VM storage migration tool

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libvirt>=0:devel/py-libvirt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}migration-tools>=0.1.0.20231116:axcient/migration-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}axcient-helpers>=0:axcient/py-axcient-helpers@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

GH_PROJECT=	vm-migrator
GH_TAGNAME=	9beb96d2d72cdab7a0f04c3dffff34008d26129b

.include <bsd.port.mk>
