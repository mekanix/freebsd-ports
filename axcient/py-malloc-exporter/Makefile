# $FreeBSD$

PORTNAME=	malloc-exporter
PORTVERSION=	0.1.0.20221115
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
GH_TAGNAME=	0be65eab55236e7d02453ea2c84eb2f4aed8e7f6

USE_RC_SUBR=	malloc_exporter

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

.include <bsd.port.mk>

