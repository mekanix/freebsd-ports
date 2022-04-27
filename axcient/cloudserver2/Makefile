# $FreeBSD$

PORTNAME=	cloudserver
PKGNAMESUFFIX?=  2
PORTVERSION?=	2.10.0
CATEGORIES=	axcient

MAINTAINER=	nsemchenkov@axcient.com
COMMENT?=	Cloudserver tool

LIB_DEPENDS?=	libszs-op.so:axcient/szs
USES=		axcient go:modules

CONFLICTS_INSTALL?=	cloudserver \
			cloudserver-stg \
			cloudserver2-dev \
			cloudserver2-stg

GH_TAGNAME?=	2.10.0

GH_TUPLE?=	alexflint:go-arg:v1.4.3:alexflint_go_arg/vendor/github.com/alexflint/go-arg \
		alexflint:go-scalar:v1.1.0:alexflint_go_scalar/vendor/github.com/alexflint/go-scalar \
		apache:thrift:327ebb6c2b6d:apache_thrift/vendor/git.apache.org/thrift.git \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgraph-io:ristretto:v0.1.0:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
		dominikh:go-tools:v0.1.3:dominikh_go_tools/vendor/honnef.co/go/tools \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		getsentry:sentry-go:v0.11.0:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.62.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-resty:resty:v2.5.0:go_resty_resty_v2/vendor/github.com/go-resty/resty/v2 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:2c7772ba3064:golang_crypto/vendor/golang.org/x/crypto \
		golang:glog:23def4e6c14b:golang_glog/vendor/github.com/golang/glog \
		golang:lint:83fdc39ff7b5:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.5.0:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.4.2:golang_mod/vendor/golang.org/x/mod \
		golang:net:69e39bad7dc2:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:09787c993a3a:golang_sync/vendor/golang.org/x/sync \
		golang:sys:e17cdc41300f:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		gomodule:redigo:v1.8.4:gomodule_redigo/vendor/github.com/gomodule/redigo \
		gopherjs:gopherjs:bed99a852dfe:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		klauspost:cpuid:v2.0.12:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:colorstring:d06e56a500db:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.9.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.15.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rs:xid:v1.2.1:rs_xid/vendor/github.com/rs/xid \
		schollz:progressbar:v3.8.6:schollz_progressbar_v3/vendor/github.com/schollz/progressbar/v3 \
		smartystreets:assertions:v1.2.0:smartystreets_assertions/vendor/github.com/smartystreets/assertions \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.6.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.16.0:uber_go_zap/vendor/go.uber.org/zap \
		zeebo:blake3:v0.2.3:zeebo_blake3/vendor/github.com/zeebo/blake3

GO_PKGNAME=	github.com/${GH_ACCOUNT}/cloudserver
GO_TARGET?=	cloudserver ./cmd/integritycheck

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rsyslog.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/cloudserver
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/newsyslog.conf.d/cloudserver.conf ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-pkg/usr/local/etc/rc.d/cloudserver ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/rsyslog.d/cloudserver.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/cloudserver/cloudserver.conf.example  ${STAGEDIR}${ETCDIR}/cloudserver.conf.sample

.include <bsd.port.mk>
