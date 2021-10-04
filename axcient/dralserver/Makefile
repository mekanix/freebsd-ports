# $FreeBSD$

PORTNAME=	dralserver
PORTVERSION?=	1.2.2
PORTREVISION?=	0
CATEGORIES=	axcient

MAINTAINER=	kklimov@axcient.com
COMMENT=	Dralserver recovery API

LIB_DEPENDS?=	libszs-op.so:axcient/szs
USES=		axcient go:modules

CONFLICTS_INSTALL?=	dralserver-stg \
			dralserver-dev

GH_TAGNAME?=	${PORTVERSION}
GH_TUPLE?=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-kit:kit:v0.10.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-logfmt:logfmt:v0.5.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-resty:resty:v2.6.0:go_resty_resty_v2/vendor/github.com/go-resty/resty/v2 \
		go-validator:validator:b37d688a7fb0:go_validator_validator/vendor/gopkg.in/validator.v2 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
		golang:net:064579744ee0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:977fb7262007:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		gomodule:redigo:v1.8.4:gomodule_redigo/vendor/github.com/gomodule/redigo \
		google:go-genproto:92282443c685:google_go_genproto/vendor/google.golang.org/genproto \
		grpc:grpc-go:v1.37.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		jarcoal:httpmock:v1.0.8:jarcoal_httpmock/vendor/github.com/jarcoal/httpmock \
		jinzhu:configor:v1.2.1:jinzhu_configor/vendor/github.com/jinzhu/configor \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		otiai10:copy:v1.6.0:otiai10_copy/vendor/github.com/otiai10/copy \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.10.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.20.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify

GO_PKGNAME=	github.com/${GH_ACCOUNT}/dralserver
GO_TARGET=	./cmd/dralserver

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/newsyslog.conf.d/dralserver.conf ${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf.d
	${INSTALL_SCRIPT} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/rc.d/dralserver ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/rsyslog.d/dralserver.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-pkg/usr/local/etc/dralserver/dralserver.yml.example  ${STAGEDIR}${ETCDIR}/dralserver.yml.sample

.include <bsd.port.mk>
