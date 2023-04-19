# $FreeBSD$

PORTNAME=	smartctl-exporter
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmekic@axcient.com
COMMENT=	Prometheus SMART exporter

RUN_DEPENDS=	smartctl:sysutils/smartmontools \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.7.0:net-mgmt/py-prometheus-client@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils

GH_PROJECT=	py-smartctl-exporter

USE_RC_SUBR=	smartctl_exporter

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

.include <bsd.port.mk>
