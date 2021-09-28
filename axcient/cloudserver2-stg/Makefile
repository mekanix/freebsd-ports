# $FreeBSD$

PORTVERSION=	2.6.0.rc2
PORTREVISION=	0
PKGNAMESUFFIX=	2-stg

GH_TAGNAME=     v2.6.0-rc2
GH_TUPLE=	\
		apache:thrift:327ebb6c2b6d:apache_thrift/vendor/git.apache.org/thrift.git \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dominikh:go-tools:v0.1.3:dominikh_go_tools/vendor/honnef.co/go/tools \
		getsentry:sentry-go:v0.11.0:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.62.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-resty:resty:v2.5.0:go_resty_resty_v2/vendor/github.com/go-resty/resty/v2 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:lint:83fdc39ff7b5:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.5.0:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.4.2:golang_mod/vendor/golang.org/x/mod \
		golang:net:e18ecbb05110:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:09787c993a3a:golang_sync/vendor/golang.org/x/sync \
		golang:sys:68d13333faf2:golang_sys/vendor/golang.org/x/sys \
		gomodule:redigo:v1.8.4:gomodule_redigo/vendor/github.com/gomodule/redigo \
		gopherjs:gopherjs:bed99a852dfe:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.9.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.15.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rs:xid:v1.2.1:rs_xid/vendor/github.com/rs/xid \
		smartystreets:assertions:v1.2.0:smartystreets_assertions/vendor/github.com/smartystreets/assertions \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.6.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.16.0:uber_go_zap/vendor/go.uber.org/zap

LIB_DEPENDS=    libszs-op.so:axcient/szs-stg
USES=		axcient go:modules

CONFLICTS_INSTALL=	cloudserver2 \
			cloudserver2-dev \
			cloudserver \
			cloudserver-stg

MASTERDIR=	${.CURDIR}/../cloudserver2
DISTINFO_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
