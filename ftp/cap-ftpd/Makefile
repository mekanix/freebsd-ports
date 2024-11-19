PORTNAME=	cap-ftpd
PORTVERSION=	0.1.0.20241119
CATEGORIES=	ftp axcient

MAINTAINER=	asomers@axcient.com
COMMENT=	Highly secure FTPS server

BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}

USES=		axcient cargo
SUB_FILES=	cap-ftpd.toml

GH_PROJECT=	cap-ftpd
GH_TAGNAME=	500ae3aa94a31e31ed4dac25a647d2271f1b6e5f

USE_RC_SUBR=	cap_ftpd

CARGO_ENV+=	LLVM_CONFIG_PATH=${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT}

PLIST_FILES=	sbin/${PORTNAME} \
		libexec/${PORTNAME}-worker \
		"@sample ${ETCDIR}/cap-ftpd.toml.sample"

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
		${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-worker
		${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-worker ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}-worker
		${MKDIR} ${STAGEDIR}${ETCDIR}
		${INSTALL_DATA} ${WRKDIR}/cap-ftpd.toml ${STAGEDIR}${ETCDIR}/cap-ftpd.toml.sample

.include <bsd.port.mk>
