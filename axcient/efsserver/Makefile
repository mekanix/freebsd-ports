PORTNAME=	efsserver
PORTVERSION=	3.21.70.20240305
CATEGORIES=	axcient net
MASTER_SITES=	GH

MAINTAINER=	asomers@axcient.com
COMMENT=	eFolder backup storage server
WWW=		https://github.com/Axcient/efs-backup

FETCH_DEPENDS=	git:devel/git
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libsqlite3.so:databases/sqlite3
RUN_DEPENDS=	${LOCALBASE}/bin/mailx:mail/heirloom-mailx \
		${LOCALBASE}/bin/gawk:lang/gawk \
		${LOCALBASE}/bin/python3:lang/python3

USES=		axcient gettext-runtime gmake python:3.6+,run,test ssl pgsql:12
USE_RC_SUBR=	efsserver
USERS=		monagent iasouser efolder efwebdev aa vmcloud
GH_PROJECT=	efs-backup
GH_TAGNAME=	2920d47a2567ab3194669b94c23233fa9298cb57
GROUPS=		iasouser monagent efolder efdev efwebdev kvm vmcloud
WANT_PGSQL=	client
MASTER_VARS=	WANT_PGSQL+=server

OPTIONS_DEFAULT=	DEBUG STORAGE
OPTIONS_DEFINE+=	DEBUG MASTER STORAGE WEB
OPTIONS_SUB=		yes
DEBUG_DESC=		Build with extended debugging support
MASTER_DESC=		Install a master server
STORAGE_DESC=		Install an online backup storage daemon server
WEB_DESC=		Install a web portal

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
WITH_DEBUG?=		yes
.endif

do-build:
	cd ${WRKSRC}/eFolderStore && ./build-all

do-install:
	# First create directory structure
	@${MKDIR} ${STAGEDIR}/repository
	@${MKDIR} ${STAGEDIR}/repository/cfg
	@${MKDIR} ${STAGEDIR}/repository/efolder
	@${MKDIR} ${STAGEDIR}/repository/efolder-sf
	@${MKDIR} ${STAGEDIR}/repository/efolder-del
	@${MKDIR} ${STAGEDIR}/repository/efolder-cfg
	@${MKDIR} ${STAGEDIR}/repository/efolder-rpts
	@${MKDIR} ${STAGEDIR}/repository/server
	@${MKDIR} ${STAGEDIR}/repository/server/pprec
	@${MKDIR} ${STAGEDIR}/repository/tools
	@${MKDIR} ${STAGEDIR}/repository/tmp
	@${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}
	# XXX For which combinations of options knob should the pgsql dir exist?
	@${MKDIR} ${STAGEDIR}/repository/pgsql/data
	#
	# eFSServer no longer uses mysql, ever
	${TOUCH} ${STAGEDIR}/repository/server/flag-check-mysql.no
	# Storage servers don't need postgresql to run.
	# TODO: conditionalize on MASTER knob
	${TOUCH} ${STAGEDIR}/repository/server/flag-check-postgresql.no
	#
	# Delete copies of sample files.  pkg will take care of creating them.
	@${RM} ${WRKSRC}/eFolderStore/deploy/installserver/files/server-cfg/common/repository/mon/cfg/map-adapterid-to-controllerid
	@${RM} ${WRKSRC}/eFolderStore/deploy/installserver/files/server-cfg/common/repository/mon/cfg/map-enclosureid-to-name
	@${RM} ${WRKSRC}/eFolderStore/deploy/installserver/files/server-cfg/common/repository/mon/cfg/map-hba-to-enclosure
	@${RM} ${WRKSRC}/eFolderStore/deploy/installserver/files/server-cfg/common/repository/mon/cfg/map-wwn-to-enclosure
	#
	# Delete Solaris-specific scripts
	@${RM} ${WRKSRC}/eFolderStore/deploy/server/start-server*
	#
	# Install server scripts
	( cd ${WRKSRC}/eFolderStore/deploy/installserver/files/server-cfg/common/repository/ && ${COPYTREE_SHARE} . ${STAGEDIR}/repository )
	${INSTALL_SCRIPT} ${WRKSRC}/eFolderStore/deploy/server/do-pprec ${STAGEDIR}/repository/
	# Install utility scripts
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/efs-utils/efs-common.sh ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/efs-utils/account-util ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/efs-utils/efs-acct-check ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/efs-utils/efs-acct-fix-perms ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/efs-utils/efs-acct-migrate ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/efs-utils/efs-pprec ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/efs-utils/efs-preload-process ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/efs-utils/efs-preload-rsync ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/efs-utils/efs-zfs-list-bdr ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/efs-utils/efs-zfs-list-nonbdr ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/efs-utils/efs-zfsr ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/efs-utils/efs-zfss ${STAGEDIR}${PREFIX}/sbin
	#
	# Set default email addresses
	${ECHO_CMD} donotreply@efoldering.com > ${STAGEDIR}/repository/efolder-cfg/info.email.from.sample
	${ECHO_CMD} support@efoldering.com KHDev4u.Urgent@vtext.com > ${STAGEDIR}/repository/efolder-cfg/info.email.pprec.sample
	${ECHO_CMD} support@efoldering.com > ${STAGEDIR}/repository/efolder-cfg/info.email.support.sample
	${ECHO_CMD} khoffman@efoldering.com > ${STAGEDIR}/repository/efolder-cfg/info.email.maintenance.sample
	@${TOUCH} ${STAGEDIR}/repository/efolder-cfg/info.email.notifications.sample
	@${TOUCH} ${STAGEDIR}/repository/efolder-cfg/info.email.logsummary.sample
	@${TOUCH} ${STAGEDIR}/repository/efolder-cfg/info.email.reports.sample
	#
	# TODO: Install the stuff in files/server-apache-cfg for WEB builds
	# TODO: Install efolder-web-app-tar.gz for WEB builds
	# TODO: Install efolder-web-opensource-pkgs.gz for WEB builds
	# TODO: Install efolder-web-app-branded-images.gz for WEB builds
	#
	# Install server and other compiled binaries
	( cd ${WRKSRC}/eFolderStore/deploy/server/ && ${COPYTREE_SHARE} . ${STAGEDIR}/repository/server )
	${TOUCH} ${STAGEDIR}/repository/server/flag-file-force-down.no
	${INSTALL_PROGRAM} ${WRKSRC}/eFolderStore/eFSServer/eFSServer ${STAGEDIR}/repository/server
	${INSTALL_DATA} ${WRKSRC}/eFolderStore/eFSServer/eFSServer.ini.template ${STAGEDIR}/repository/server
	${INSTALL_DATA} ${WRKSRC}/eFolderStore/eFSServer/eFSServer-dev.ini.template ${STAGEDIR}/repository/server
	# XXX deploy/installserver/package-server installs TestServer but it's
	# not installed on r55.  I'm choosing not to install it.
	${INSTALL_PROGRAM} ${WRKSRC}/eFolderStore/metainfotool/metainfotool ${STAGEDIR}/repository/server
	${INSTALL_PROGRAM} ${WRKSRC}/eFolderStore/pprecover/pprecover ${STAGEDIR}/repository/server/pprec
	${INSTALL_PROGRAM} ${WRKSRC}/eFolderStore/readgptinfile/readgptinfile ${STAGEDIR}/repository/server/readgptinfile
	#
	# Install keys and certs
	${INSTALL_DATA} ${WRKSRC}/keys/efolder-passphrase-public.rsa ${STAGEDIR}/repository/server/pprec
	${INSTALL_DATA} ${WRKSRC}/certs/efolder-certs/2010.eFolder.Server.cert ${STAGEDIR}/repository/efolder-cfg/
	${INSTALL_DATA} ${WRKSRC}/certs/efolder-certs/2010.eFolder.Server.key ${STAGEDIR}/repository/efolder-cfg/
	# Sigh.  The repository contains two copies of this file.  I think this
	# is the correct copy.
	${INSTALL_DATA} ${WRKSRC}/certs/efolder-ca-list.pem ${STAGEDIR}/repository/efolder-cfg

#do-test:
	#@cd ${WRKSRC}/testing && gmake -f Makefile.freebsd precompile run
.include <bsd.port.mk>
