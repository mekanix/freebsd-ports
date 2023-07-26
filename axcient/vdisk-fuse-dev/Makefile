# $FreeBSD$

PORTVERSION=	1.1.3.${DATECODE}
# Set PORTREVISION explicitly so it won't be inherited from the MASTERDIR
PKGNAMESUFFIX=	-dev

DATECODE!=	date -u "+%Y%m%d%H"

COMMENT=	Hourly build of vdisk-fuse's develop branch

GH_TAGNAME=	develop
GH_COMMIT_FILE=	.gitcommit

CONFLICTS_INSTALL=	vdisk-fuse \
			vdisk-fuse-stg

MASTERDIR=	${.CURDIR}/../vdisk-fuse

# Disable checksum verification because this port builds from the tip of a
# branch.
checksum:

.include "${MASTERDIR}/Makefile"
