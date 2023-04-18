# $FreeBSD$

PORTNAME=	vt2
PORTVERSION?=	1.4.0
PORTREVISION?=	1
CATEGORIES=	axcient
MASTER_SITES=	GH

MAINTAINER=	dprokopchenkov@axcient.com
COMMENT?=	Vault Transfer 2

SZS_LIB_DEPENDS?= libszs-op.so:axcient/szs
LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd \
		libgnutls.so:security/gnutls \
		libunistring.so:devel/libunistring \
		libtasn1.so:security/libtasn1 \
		libnettle.so:security/nettle \
		libhogweed.so:security/nettle \
		libgmp.so:math/gmp \
		libidn2.so:dns/libidn2 \
		${SZS_LIB_DEPENDS}

# I'm skeptical that ca_root_nss is really needed, but it was specified as a
# dependency in the prior version of the package at
# https://raw.githubusercontent.com/Axcient/vaulttransfer2/6d5d3224796695bf163b9e6d37fe089f2b4109af/freebsd-pkg/%2BMANIFEST?token=AAA7VONVI376NMBQPJLHG6K6T4YLG
RUN_DEPENDS+=	ca_root_nss>0:security/ca_root_nss

USES+=		axcient gmake
GH_PROJECT=	vaulttransfer2
GH_TAGNAME?=    1.4.0

GH_TUPLE=       alexflint:go-arg:v1.4.3:alexflint_go_arg/vendor/github.com/alexflint/go-arg \
                alexflint:go-scalar:v1.1.0:alexflint_go_scalar/vendor/github.com/alexflint/go-scalar \
                davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
                go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
                pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
                stretchr:testify:v1.8.1:stretchr_testify/vendor/github.com/stretchr/testify

CONFLICTS_INSTALL?=	vt2-stg

MAKE_JOBS_UNSAFE=yes
ALL_TARGET=	server
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES?=  etc/rc.d/vt2 \
               "@dir etc/rsyslog.d" \
               bin/vaulttransferserver2 \
               bin/vaulttransferclient2 \
               "@sample ${EXAMPLESDIR}/newsyslog.conf etc/newsyslog.conf.d/vt2.conf" \
               "@sample ${EXAMPLESDIR}/rsyslog.conf etc/rsyslog.d/vt2.conf" \
               "@sample ${EXAMPLESDIR}/newsyslog.conf.d/vt2client.conf etc/newsyslog.conf.d/vt2client.conf" \
               "@sample ${EXAMPLESDIR}/rsyslog.d/vt2client.conf etc/rsyslog.d/vt2client.conf"


DISTINFO_FILE=	${.CURDIR}/distinfo

# We have `go` directory in repository for golang version of vt2 client,
# didn't find a way how to change working directory for only golang build (gomod-vendor recipe),
# so need to change `WRKSRC_SUBDIR` and change it for server `gmake` build
# using `cd ${BUILD_WRKSRC}/../`, see `do-build`
# This need to be changed when we will fully rewrite vt2 including server
WRKSRC_SUBDIR=go

# Golang part
GO_PKGNAME=     github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=${WRKSRC}/cmd/client/main.go:vaulttransferclient2

USES+=          axcient gmake go:modules

MAKE_ARGS+= SERVER_LDFLAGS="${LDFLAGS} -lmicrohttpd -lszs-op -L."

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

.  if !target(do-install)
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rsyslog.d
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	# Server files
	${INSTALL_PROGRAM} ${WRKSRC}/../vaulttransferserver2 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/../freebsd-pkg/usr/local/etc/newsyslog.conf.d/vt2.conf ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf
	${INSTALL_SCRIPT} ${WRKSRC}/../freebsd-pkg/usr/local/etc/rc.d/vt2 ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/../freebsd-pkg/usr/local/etc/rsyslog.d/vt2.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.conf
	# Client files
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/vaulttransferclient2 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/newsyslog.conf.d/vt2client.conf ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d/vt2client.conf
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/rsyslog.d/vt2client.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d/vt2client.conf
.  endif

.include <bsd.port.mk>
