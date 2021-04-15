# $FreeBSD$

PORTNAME=	sas2flash
PORTVERSION=	20.00.00.00
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTNAME=	Installer_P20_for_FreeBSD

MAINTAINER=	asomers@axcient.com
COMMENT=	SAS-2 HBA Firmware Update Utility

LICENSE=	BROADCOM
LICENSE_NAME=	Broadcom personal use license
LICENSE_TEXT=	License can be found at \
		${LSI_SITES}${DISTNAME}${EXTRACT_SUFX} .\n \
		Permission to restribute is included.
LICENSE_PERMS=	dist-mirror pkg-mirror pkg-sell

.if defined(PACKAGE_BUILDING)
IGNORE=		requires manual fetch
.endif
ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Binaries only available for i386 and amd64 from Broadcom

USES=	zip

WRKSRC=	${WRKDIR}/${DISTNAME}

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS
PLIST_FILES=	sbin/sas2flash
PORTDOCS=	SAS2FLASH_Phase20.0-20.00.00.00.pdf \
		SAS2Flash_ReferenceGuide.pdf \
		README_Installer_P20_FreeBSD.txt

LSI_SITES=	https://docs.broadcom.com/docs/
DISTFILE_INSTRUCTIONS=	\n\
Due to licensing restrictions, certain files must be fetched manually.\n\
Please visit the following URL and accept the license agreement.\n\n\
${LSI_SITES}${DISTNAME}${EXTRACT_SUFX}\n\n\
After the download has completed, please place ${DISTNAME}${EXTRACT_SUFX} in\n\
${DISTDIR}, then restart the build.\n\n

.include <bsd.port.pre.mk>

.if ! exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
pre-fetch:
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}" ; exit 1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}_${OPSYS:tl}_${ARCH:tl}_rel/${PORTNAME} \
		${STAGEDIR}${PREFIX}/sbin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/SAS2FLASH_Phase20.0-${PORTVERSION}.pdf \
		${WRKSRC}/README_Installer_P20_FreeBSD.txt \
		${WRKSRC}/SAS2Flash_ReferenceGuide.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
