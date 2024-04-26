PORTNAME=	pxeweb
PORTVERSION=	0.1.0.20240426
CATEGORIES=	axcient
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jsollvander@axcient.com
COMMENT=	Python/Flask web app for configuring DHCP IP reservations

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=3.0.0:www/py-flask@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils

.include <bsd.port.options.mk>

NO_ARCH=	yes

GH_PROJECT=	pxeweb
GH_TAGNAME=	c7530b55bfee5d51ec8cb4ddf347a65513ff8a9a

.include <bsd.port.mk>
