# $FreeBSD$

PORTNAME=	zfs-exporter
PORTVERSION=	0.3.1
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	asomers@axcient.com
COMMENT=	Prometheus ZFS exporter using libzfs

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libzfs>=1.0.2:devel/py-libzfs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.7.0:net-mgmt/py-prometheus-client@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils
USERS=		prometheus
GROUPS=		prometheus

GH_PROJECT=	py-zfs-exporter
GH_TAGNAME=	v${PORTVERSION}

USE_RC_SUBR=	zfs_exporter

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

.include <bsd.port.mk>
