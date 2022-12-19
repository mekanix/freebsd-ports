PORTNAME=	grpc-tests
PORTVERSION=	1.0.0.${DATECODE}
CATEGORIES=	axcient

DATECODE!=	date -u "+%Y%m%d%H"

MAINTAINER=	kgermanov@axcient.com
COMMENT=	Build of grpc-tests develop branch

BUILD_DEPENDS=	flex>=2.6:textproc/flex coreutils>=9.1:sysutils/coreutils e2fsprogs>=1.46:sysutils/e2fsprogs

USES=		axcient cmake pkgconfig bison qt:5 ssl
USE_QT=		buildtools:build qmake network core
GH_TAGNAME=	develop

PLIST_FILES=	bin/grpc-client
PLIST_FILES+=	bin/grpc-server
PLIST_FILES+=	bin/file-getter-server

CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE=ON -DUSE_CHEKS=OFF

checksum:

do-install:
	${INSTALL} ${WRKDIR}/.build/src/Server/grpc-server ${STAGEDIR}${PREFIX}/bin/grpc-server
	${INSTALL} ${WRKDIR}/.build/src/Client/grpc-client ${STAGEDIR}${PREFIX}/bin/grpc-client
	${INSTALL} ${WRKDIR}/.build/src/FileGetterServer/file-getter-server ${STAGEDIR}${PREFIX}/bin/file-getter-server

.include <bsd.port.mk>
