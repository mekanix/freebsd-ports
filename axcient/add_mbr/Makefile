# $FreeBSD$

PORTNAME=	add_mbr
PORTVERSION?=	2.0.1
PORTREVISION?=	0
CATEGORIES=	axcient sysutils
MASTER_SITES=	GH

MAINTAINER=	dprokopchenkov@axcient.com
COMMENT?=	Replibit add_mbr tool

USES=		axcient fuse gmake
GH_PROJECT=	Disk-Manager
GH_TAGNAME?=	2.0.1

CONFLICTS_INSTALL=	add_mbr-stg

PLIST_FILES=	bin/add_mbr

do-install:
	${INSTALL} ${WRKSRC}/add_mbr ${STAGEDIR}${PREFIX}/bin/add_mbr

.include <bsd.port.mk>
