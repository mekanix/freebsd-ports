# $FreeBSD$

PORTVERSION=	1.5.0.${DATECODE}
PORTREVISION=	0
PKGNAMESUFFIX=	-dev

DATECODE!=	date -u "+%Y%m%d%H"

COMMENT=	Hourly build of vt2's develop branch

GH_TAGNAME=	develop

SZS_LIB_DEPENDS= libszs-op.so:axcient/szs-dev
CONFLICTS_INSTALL=	vt2 \
			vt2-stg

MASTERDIR=	${.CURDIR}/../vt2

EXTRA_PATCHES= 
MAKE_ARGS+= SERVER_LDFLAGS="${LDFLAGS} -lmicrohttpd -lszs-op -L."

# We have `go` directory in repository for golang version of vt2 client,
# didn't find a way how to change working directory for only golang build (gomod-vendor recipe),
# so need to change `WRKSRC_SUBDIR` and change it for server `gmake` build
# using `cd ${BUILD_WRKSRC}/../`, see `do-build`
# This need to be changed when we will fully rewrite vt2 including server
WRKSRC_SUBDIR=go

# Golang part
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=${WRKSRC}/cmd/client/main.go:vaulttransferclient2
USES+=	go:modules

# Disable checksum verification because this port builds from the tip of a
# branch.
checksum:

PLIST_FILES=    bin/vaulttransferserver2 \
		etc/rc.d/vt2 \
		"@sample ${EXAMPLESDIR}/newsyslog.conf.d/vt2server.conf etc/newsyslog.conf.d/vt2.conf" \
		"@sample ${EXAMPLESDIR}/rsyslog.d/vt2server.conf etc/rsyslog.d/vt2.conf" \
		bin/vaulttransferclient2 \
		"@sample ${EXAMPLESDIR}/newsyslog.conf.d/vt2client.conf etc/newsyslog.conf.d/vt2client.conf" \
		"@sample ${EXAMPLESDIR}/rsyslog.d/vt2client.conf etc/rsyslog.d/vt2client.conf"

pre-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} GOPATH=/tmp ${GO_CMD} mod vendor

# It is not possible to use the `go:modules` and `gmake` build rules together,
# so we need to redeclare do-build, containing recipe scripts from both,
# see go.mk:do-build and bsd.port.mk:do-build
do-build:
	@(cd ${GO_WRKSRC}; \
	for t in ${GO_TARGET}; do \
		out=$$(${BASENAME} $$(${ECHO_CMD} $${t} | \
			${SED} -Ee 's/^[^:]*:([^:]+).*$$/\1/' -e 's/^\.$$/${PORTNAME}/')); \
		pkg=$$(${ECHO_CMD} $${t} | \
			${SED} -Ee 's/^([^:]*).*$$/\1/' -e 's/^${PORTNAME}$$/./'); \
		${ECHO_MSG} "===>  Building $${out} from $${pkg}"; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} build ${GO_BUILDFLAGS} \
			-o ${GO_WRKDIR_BIN}/$${out} \
			$${pkg}; \
	done; \
	cd ${BUILD_WRKSRC}/../; if ! ${DO_MAKE_BUILD} ${ALL_TARGET}; then \
	if [ -n "${BUILD_FAIL_MESSAGE}" ] ; then \
		${ECHO_MSG} "===> Compilation failed unexpectedly."; \
		(${ECHO_CMD} "${BUILD_FAIL_MESSAGE}") | ${FMT_80} ; \
		fi; \
	${FALSE}; \
	fi)

do-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	# Server files
	${INSTALL_PROGRAM} ${WRKSRC}/../vaulttransferserver2 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/../freebsd-pkg/usr/local/etc/rc.d/vt2 ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/../freebsd-pkg/usr/local/etc/newsyslog.conf.d/vt2.conf ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d/vt2server.conf
	${INSTALL_DATA} ${WRKSRC}/../freebsd-pkg/usr/local/etc/rsyslog.d/vt2.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d/vt2server.conf
	# Client files
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/vaulttransferclient2 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/newsyslog.conf.d/vt2client.conf ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d/vt2client.conf
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/rsyslog.d/vt2client.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d/vt2client.conf

.include "${MASTERDIR}/Makefile"
