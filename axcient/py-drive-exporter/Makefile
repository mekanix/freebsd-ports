# $FreeBSD$

PORTNAME=	drive-exporter
PORTVERSION=	0.1.0.20201214
CATEGORIES=	axcient
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	apinchuk@axcient.com
COMMENT=	Prometheus drive stats exporter using iostat

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.7.0:net-mgmt/py-prometheus-client@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils
USERS=		prometheus
GROUPS=		prometheus

GH_PROJECT=	py-drive-exporter
GH_TAGNAME=	9e777b2a9b53e02356222113c62131365e0c7ba0

USE_RC_SUBR=	drive_exporter

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

.include <bsd.port.mk>
