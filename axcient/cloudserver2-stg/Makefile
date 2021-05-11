# $FreeBSD$

PORTVERSION=	2.3.0
PORTREVISION=	0
PKGNAMESUFFIX=	2-stg

GH_TAGNAME=     v${PORTVERSION}

LIB_DEPENDS=    libszs-op.so:axcient/szs-stg
USES=		axcient go:modules

CONFLICTS_INSTALL=	cloudserver2 \
			cloudserver2-dev \
			cloudserver \
			cloudserver-stg

MASTERDIR=	${.CURDIR}/../cloudserver2
DISTINFO_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
