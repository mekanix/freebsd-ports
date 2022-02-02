# $FreeBSD$

PORTVERSION=	1.16.0.${DATECODE}
PORTREVISION=	0
PKGNAMESUFFIX=	-dev

DATECODE!=	date -u "+%Y%m%d%H"

COMMENT=	Hourly build of szs's develop branch

GH_TAGNAME=	develop

ADD_MBR_DEPENDS=	add_mbr:axcient/add_mbr-dev
CONFLICTS_INSTALL=	szs \
			szs-stg

MASTERDIR=	${.CURDIR}/../szs
PLIST=		${.CURDIR}/pkg-plist

# Disable checksum verification because this port builds from the tip of a
# branch.
checksum:

pre-build:
	cd ${WRKSRC}; GOPATH=/tmp go mod vendor

.include "${MASTERDIR}/Makefile"
