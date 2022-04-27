# $FreeBSD$

PORTNAME=	dralserver
PORTVERSION?=	1.6.0
CATEGORIES=	axcient

MAINTAINER=	kklimov@axcient.com
COMMENT=	Dralserver recovery API

LIB_DEPENDS?=	libszs-op.so:axcient/szs
USES=		axcient go:modules

CONFLICTS_INSTALL?=	dralserver-stg \
			dralserver-dev

GH_TAGNAME?=	1.6.0
GH_TUPLE?=	BurntSushi:toml:v0.4.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-kit:kit:v0.12.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-kit:log:v0.2.0:go_kit_log/vendor/github.com/go-kit/log \
		go-logfmt:logfmt:v0.5.1:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-resty:resty:v2.7.0:go_resty_resty_v2/vendor/github.com/go-resty/resty/v2 \
		go-validator:validator:b37d688a7fb0:go_validator_validator/vendor/gopkg.in/validator.v2 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang-jwt:jwt:v4.0.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
		golang:net:69e39bad7dc2:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:0a5406a5449c:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		gomodule:redigo:v1.8.5:gomodule_redigo/vendor/github.com/gomodule/redigo \
		google:go-genproto:a5da7257a6f7:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		grpc:grpc-go:v1.42.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		jarcoal:httpmock:v1.1.0:jarcoal_httpmock/vendor/github.com/jarcoal/httpmock \
		jinzhu:configor:v1.2.1:jinzhu_configor/vendor/github.com/jinzhu/configor \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		otiai10:copy:v1.7.0:otiai10_copy/vendor/github.com/otiai10/copy \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.32.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.7.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify

GO_PKGNAME=	github.com/${GH_ACCOUNT}/dralserver
GO_TARGET?=	./cmd/dralserver ./cmd/cleanupdralclones

.include "${.CURDIR}/post-install.mk"

.include <bsd.port.mk>
