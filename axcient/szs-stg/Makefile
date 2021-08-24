# $FreeBSD$

PORTVERSION?=	1.11.0.rc1
PORTREVISION?=	1
PKGNAMESUFFIX=	-stg

GH_TAGNAME=     1.11.0-rc1

ADD_MBR_DEPENDS=	add_mbr:axcient/add_mbr-stg
CONFLICTS_INSTALL=	szs

MASTERDIR=	${.CURDIR}/../szs
DISTINFO_FILE=	${.CURDIR}/distinfo

GO_TARGET=	./cmd/api ./cmd/jobs ./cmd/statistics ./cmd/exports ./cmd/safetyarchivecleanup ./cmd/cleanupclones ./cmd/snapshotscleanup

.include "${MASTERDIR}/Makefile"
