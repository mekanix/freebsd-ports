# $FreeBSD$

PORTNAME=	rsync-proxy
DATECODE!=	date -u "+%Y%m%d%H"
PORTVERSION=	1.2.0.${DATECODE}
PKGNAMESUFFIX=	-dev
CATEGORIES=	axcient
MAINTAINER=	kklimov@axcient.com
COMMENT=	Hourly build of rsync-proxy's develop branch

CONFLICTS_INSTALL= 	rsync-proxy rsync-proxy-stg
LIB_DEPENDS=		libszs-op.so:axcient/szs-dev
#TODO remove 1.21 pinned version when `GO_DEFAULT` will be go1.21 or higher, the USES should be: `USES=axcient go:modules`
USES=			axcient go:1.21,modules

GH_TAGNAME=	develop
GO_PKGNAME=	github.com/${GH_ACCOUNT}/rsync-proxy
GO_TARGET=	./cmd/proxy

NO_CHECKSUM=	yes

pre-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} GOPATH=/tmp ${GO_CMD} mod vendor

.include "${.CURDIR}/post-install.mk"
.include <bsd.port.mk>
