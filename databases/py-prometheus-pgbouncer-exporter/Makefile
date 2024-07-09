PORTNAME=	prometheus-pgbouncer-exporter
PORTVERSION=	2.1.1
PORTREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=   https://patch-diff.githubusercontent.com/raw/spreaker/prometheus-pgbouncer-exporter/pull/
PATCHFILES+=	33.diff:-p1

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Prometheus exporter for pgbouncer

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.8:net-mgmt/py-prometheus-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-json-logger>=0.111:devel/py-python-json-logger@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.8.5:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3.1:devel/py-pyyaml@${PY_FLAVOR}

TEST_DEPENDS=	pip:devel/py-pip@${PY_FLAVOR} \
		pycodestyle:devel/py-pycodestyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.6+
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	pgbouncer_exporter

PGBOUNCER_EXPORTER_USER?=	nobody
PGBOUNCER_EXPORTER_GROUP?=	nogroup
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}
SUB_LIST+=	PGBOUNCER_EXPORTER_USER=${PGBOUNCER_EXPORTER_USER}
SUB_LIST+=	PGBOUNCER_EXPORTER_GROUP=${PGBOUNCER_EXPORTER_GROUP}

PLIST_DIRS=	${ETCDIR}

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}

test:
	cd ${WRKSRC} && \
	    python${PYTHON_VER} setup.py test

.include <bsd.port.mk>
