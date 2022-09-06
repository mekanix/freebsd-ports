# $FreeBSD$

PORTNAME=	network-interface-exporter
PORTVERSION=	0.0.1
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmekic@axcient.com
COMMENT=	Prometheus network interface exporter

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.7.0:net-mgmt/py-prometheus-client@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils
USERS=		prometheus
GROUPS=		prometheus

GH_PROJECT=	py-network-interface-exporter
GH_TAGNAME=	0.0.1

USE_RC_SUBR=	network_interface_exporter

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

.include <bsd.port.mk>
