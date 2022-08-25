PORTNAME=	szs-migrator
PORTVERSION=	0.1.0.20220825
CATEGORIES=	axcient
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	asomers@axcient.com
COMMENT=	Replibit dataset migrator

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=5.0.0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.11.0_2:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libzfs>=0:devel/py-libzfs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}atomicwrites>=0:devel/py-atomicwrites@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parse>=0:textproc/py-parse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR}
PROMETHEUS_RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}libzfs_core>=0:devel/py-libzfs_core@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		axcient python
USE_PYTHON=	autoplist distutils
WRKSRC_SUBDIR=	szs/maintenance-tool
SUB_FILES=	900.szs-audit 900.szs-migrator-audit
# Don't set USERS and GROUPS because we already created the rebalancer user via
# AD, with IDs that are outside of the usual range for daemon users.

OPTIONS_DEFINE=		PROMETHEUS
OPTIONS_DEFAULT=	PROMETHEUS
PROMETHEUS_DESC=	Export migration status with Prometheus

.include <bsd.port.options.mk>

NO_ARCH=	yes

GH_PROJECT=	replibit-tools
GH_TAGNAME=	0826b1440475a76ebe2c4f0cf54644ae04625728

USE_RC_SUBR=	szs_rebalancer

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PLIST_FILES+=	etc/periodic/weekly/900.szs-audit \
		etc/periodic/daily/900.szs-migrator-audit \
		etc/rsyslog.d/szs_rebalancer.conf

do-test:
	cd ${WRKSRC} && pytest

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/weekly
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/rsyslog.d
	${INSTALL_SCRIPT} ${FILESDIR}/szs_rebalancer.conf ${STAGEDIR}${PREFIX}/etc/rsyslog.d
	${INSTALL_SCRIPT} ${WRKDIR}/900.szs-audit ${STAGEDIR}${PREFIX}/etc/periodic/weekly
	${INSTALL_SCRIPT} ${WRKDIR}/900.szs-migrator-audit ${STAGEDIR}${PREFIX}/etc/periodic/daily

.include <bsd.port.mk>
