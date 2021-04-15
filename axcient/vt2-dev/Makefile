# $FreeBSD$

PORTVERSION=	1.1.5.${DATECODE}
PORTREVISION=	0
PKGNAMESUFFIX=	-dev

DATECODE!=	date -u "+%Y%m%d%H"

COMMENT=	Hourly build of vt2's develop branch

GH_TAGNAME=	develop

SZS_LIB_DEPENDS= libszs-op.so:axcient/szs-dev
CONFLICTS_INSTALL=	vt2 \
			vt2-stg

MASTERDIR=	${.CURDIR}/../vt2

# Disable checksum verification because this port builds from the tip of a
# branch.
checksum:

.include "${MASTERDIR}/Makefile"
