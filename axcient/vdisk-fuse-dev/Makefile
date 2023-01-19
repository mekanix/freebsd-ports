# $FreeBSD$

PORTVERSION=	1.1.1.${DATECODE}
# Set PORTREVISION explicitly so it won't be inherited from the MASTERDIR
PORTREVISION=	0
PKGNAMESUFFIX=	-dev

DATECODE!=	date -u "+%Y%m%d%H"

COMMENT=	Hourly build of vdisk-fuse's develop branch

GH_TAGNAME=	develop

CONFLICTS_INSTALL=	vdisk-fuse \
			vdisk-fuse-stg

MASTERDIR=	${.CURDIR}/../vdisk-fuse

# Disable checksum verification because this port builds from the tip of a
# branch.
checksum:

.include "${MASTERDIR}/Makefile"
