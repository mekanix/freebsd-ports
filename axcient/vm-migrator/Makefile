# $FreeBSD$

PORTNAME=	vm-migrator
PORTVERSION=	0.1.0.20220228
CATEGORIES=	axcient
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jsollvander@axcient.com
COMMENT=	VM and VM storage migration tool

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libvirt>=0:devel/py-libvirt@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

GH_PROJECT=	vm-migrator
GH_TAGNAME=	52615ee94eed87111e842c989000e5cab19731a1

.include <bsd.port.mk>
