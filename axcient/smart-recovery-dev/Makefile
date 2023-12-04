# $FreeBSD$

DISTVERSION=	1.2.3.${DATECODE}
# Set PORTREVISION explicitly so it won't be inherited from the MASTERDIR
PORTREVISION=	0
PKGNAMESUFFIX=	-dev

DATECODE!=	date -u "+%Y%m%d%H"

COMMENT=	Hourly build of smart-recovery's develop branch

GH_TAGNAME=	develop
GH_COMMIT_FILE=	.gitcommit

CONFLICTS_INSTALL=	smart-recovery \
			smart-recovery-stg

MASTERDIR=	${.CURDIR}/../smart-recovery

# Disable checksum verification because this port builds from the tip of a
# branch.
checksum:

.include "${MASTERDIR}/Makefile"
