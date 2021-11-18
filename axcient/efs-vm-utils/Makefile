PORTNAME=	efs-vm-utils
PORTVERSION=	3.21.70.20211118
CATEGORIES=	axcient sysutils
MASTER_SITES=	GH

MAINTAINER=	asomers@axcient.com
COMMENT=	Utilities for VMs originally from the efs-backup package

FETCH_DEPENDS=	git:devel/git
RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

USES=		axcient gmake shebangfix
PERL_USES=	perl5
GH_PROJECT=	efs-backup
GH_TAGNAME=	7629924e0d5bf76ac4d94722d2be09c989a7ebec

SHEBANG_FILES=	eFolderStore/deploy/server/aa-get-billable-disk-usage

PLIST_FILES=	bin/readgptinfile
PLIST_FILES+=	bin/aa-get-billable-disk-usage

do-build:
	cd ${WRKSRC}/eFolderStore/readgptinfile && make -f Makefile.freebsd
	${SED} -i "" "s:/repository/server:${PREFIX}/bin:" ${WRKSRC}/eFolderStore/deploy/server/aa-get-billable-disk-usage

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eFolderStore/readgptinfile/readgptinfile ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/eFolderStore/deploy/server/aa-get-billable-disk-usage ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
