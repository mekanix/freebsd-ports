# $FreeBSD$

PORTNAME=	vm-migrator
PORTVERSION=	0.1.1.20220728
CATEGORIES=	axcient
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jsollvander@axcient.com
COMMENT=	VM and VM storage migration tool

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libvirt>=0:devel/py-libvirt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}migration-tools>=0:axcient/migration-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}axcient-helpers>=0:axcient/py-axcient-helpers@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

GH_PROJECT=	vm-migrator
GH_TAGNAME=	94c300800f396095d662c7a53b9415076132ae3e

.include <bsd.port.mk>
