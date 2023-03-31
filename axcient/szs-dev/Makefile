# $FreeBSD$

PORTVERSION=	1.28.0.${DATECODE}
PORTREVISION=	1
PKGNAMESUFFIX=	-dev

DATECODE!=	date -u "+%Y%m%d%H"

COMMENT=	Hourly build of szs's develop branch

#TODO Move this dependency to szs prod port after azure-recovery utility will be released
RUN_DEPENDS+=	vdisk-fuse:axcient/vdisk-fuse


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
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} GOPATH=/tmp ${GO_CMD} mod vendor

GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}"
GO_TARGET=	./cmd/api ./cmd/jobs ./cmd/statistics ./cmd/safetyarchivecleanup ./cmd/cleanupclones ./cmd/snapshotscleanup ./cmd/clonesnapshots ./cmd/azurerecovery

.include "${MASTERDIR}/Makefile"
