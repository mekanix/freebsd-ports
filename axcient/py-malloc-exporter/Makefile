# $FreeBSD$

PORTNAME=	malloc-exporter
PORTVERSION=	0.2.0.20240724
CATEGORIES=	axcient
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jsollvander@axcient.com
COMMENT= 	Prometheus exporter that exports "vmstat -m" information

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.14.0:net-mgmt/py-prometheus-client@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils
USERS=		prometheus
GROUPS=		prometheus

GH_PROJECT=	py-malloc-exporter
GH_TAGNAME=	v0.2.0

USE_RC_SUBR=	malloc_exporter

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

.include <bsd.port.mk>

