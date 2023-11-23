# $FreeBSD$

PORTVERSION=	2.15.0.${DATECODE}
PORTREVISION=	0
PKGNAMESUFFIX=	2-dev

DATECODE!=	date -u "+%Y%m%d%H"

COMMENT=	Hourly build of cloudservers's develop branch

GH_TAGNAME=	develop

LIB_DEPENDS= libszs-op.so:axcient/szs-dev
CONFLICTS_INSTALL=	cloudserver2 \
			cloudserver2-stg \
			cloudserver \
			cloudserver-stg

MASTERDIR=	${.CURDIR}/../cloudserver2

GO_BUILDFLAGS=	-ldflags "-X=main.version=${PORTVERSION}"
GO_TARGET=      cloudserver ./cmd/integritycheck

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rsyslog.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/cloudserver
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/newsyslog.conf.d/cloudserver.conf ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-pkg/usr/local/etc/rc.d/cloudserver ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/rsyslog.d/cloudserver.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/cloudserver/cloudserver.conf.example  ${STAGEDIR}${ETCDIR}/cloudserver.conf.sample

# Disable checksum verification because this port builds from the tip of a
# branch.
checksum:

pre-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} GOPATH=/tmp ${GO_CMD} mod vendor

.include "${MASTERDIR}/Makefile"
