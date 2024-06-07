PORTNAME=	ses-exporter
PORTVERSION=	0.0.2
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gmekic@axcient.com
COMMENT=	Prometheus SES exporter

LICENSE=	AXCIENT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.7.0:net-mgmt/py-prometheus-client@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils

GH_PROJECT=	py-ses-exporter

USE_RC_SUBR=	ses_exporter

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

.include <bsd.port.mk>
