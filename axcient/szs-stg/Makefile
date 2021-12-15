# $FreeBSD$

PORTVERSION?=	1.14.0.rc1
PORTREVISION?=	0
PKGNAMESUFFIX=	-stg

GH_TAGNAME=     1.14.0-rc1

ADD_MBR_DEPENDS=	add_mbr:axcient/add_mbr-stg
CONFLICTS_INSTALL=	szs

MASTERDIR=	${.CURDIR}/../szs
DISTINFO_FILE=	${.CURDIR}/distinfo
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
