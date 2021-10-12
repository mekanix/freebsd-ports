# $FreeBSD$

PORTVERSION=	2.7.0.${DATECODE}
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

# Disable checksum verification because this port builds from the tip of a
# branch.
checksum:

pre-build:
	cd ${WRKSRC}; GOPATH=/tmp go mod vendor

.include "${MASTERDIR}/Makefile"
