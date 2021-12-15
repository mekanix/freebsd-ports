# $FreeBSD$

PORTVERSION=	1.3.0.rc2
PORTREVISION=	0
PKGNAMESUFFIX=	-stg

GH_TAGNAME=     1.3.0-rc2

LIB_DEPENDS=    libszs-op.so:axcient/szs-stg
USES=		axcient go:modules

CONFLICTS_INSTALL=	dralserver \
			dralserver-dev

MASTERDIR=	${.CURDIR}/../dralserver
DISTINFO_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
