# $FreeBSD$

PORTNAME=	sas3flash
PORTVERSION=	17.00.00.00
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTNAME=	Installer_P16_for_FreeBSD

MAINTAINER=	asomers@axcient.com
COMMENT=	SAS-3 HBA Firmware Update Utility

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
PLIST_FILES=	sbin/sas3flash
PORTDOCS=	FLASH_MPT_GEN3_Phase16.0-17.00.00.00.pdf \
		README_Installer_P16_FreeBSD.txt \
		sas3Flash_quickRefGuide_rev1-0.pdf

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
	${INSTALL_DATA} ${WRKSRC}/FLASH_MPT_GEN3_Phase16.0-17.00.00.00.pdf \
		${WRKSRC}/README_Installer_P16_FreeBSD.txt \
		${WRKSRC}/sas3Flash_quickRefGuide_rev1-0.pdf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
