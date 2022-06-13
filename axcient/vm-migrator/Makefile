# $FreeBSD$

PORTNAME=	vm-migrator
PORTVERSION=	0.1.1.20220601
PORTREVISION= 	1
CATEGORIES=	axcient
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jsollvander@axcient.com
COMMENT=	VM and VM storage migration tool

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libvirt>=0:devel/py-libvirt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}axcient>=0:axcient/py-axcient@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

GH_PROJECT=	vm-migrator
GH_TAGNAME=	693d9ec40636a0c33f5461d6f4ccbcd55abc4c49

.include <bsd.port.mk>
