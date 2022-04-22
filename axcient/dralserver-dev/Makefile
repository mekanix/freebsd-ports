# $FreeBSD$

PORTVERSION=	1.6.0.${DATECODE}
PORTREVISION=	0
PKGNAMESUFFIX=	-dev

DATECODE!=	date -u "+%Y%m%d%H"

COMMENT=	Hourly build of dralserver's develop branch

GH_TAGNAME=	develop

LIB_DEPENDS= libszs-op.so:axcient/szs-dev
CONFLICTS_INSTALL=	dralserver \
			dralserver-stg

MASTERDIR=	${.CURDIR}/../dralserver

GO_TARGET=	./cmd/dralserver ./cmd/cleanupdralclones

# Disable checksum verification because this port builds from the tip of a
# branch.
checksum:

pre-build:
	cd ${WRKSRC}; GOPATH=/tmp go mod vendor

.include "${MASTERDIR}/Makefile"
