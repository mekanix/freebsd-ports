# $FreeBSD$

PORTVERSION=	2.0.1.${DATECODE}
# Set PORTREVISION explicitly so it won't be inherited from the MASTERDIR
PORTREVISION=	0
PKGNAMESUFFIX=	-dev

DATECODE!=	date -u "+%Y%m%d%H"

COMMENT=	Hourly build of add_mbr's develop branch

GH_TAGNAME=	develop

CONFLICTS_INSTALL=	add_mbr \
			add_mbr-stg

MASTERDIR=	${.CURDIR}/../add_mbr

# Disable checksum verification because this port builds from the tip of a
# branch.
checksum:

.include "${MASTERDIR}/Makefile"
