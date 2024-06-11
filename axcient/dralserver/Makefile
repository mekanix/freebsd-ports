# $FreeBSD$

PORTNAME=	dralserver
PORTVERSION?=	2.2.0
PORTREVISION?=	0
CATEGORIES=	axcient

MAINTAINER=	kklimov@axcient.com
COMMENT=	Dralserver recovery API

LIB_DEPENDS?=	libszs-op.so:axcient/szs
USES=		axcient go:modules

CONFLICTS_INSTALL?=	dralserver-stg \
			dralserver-dev

GH_TAGNAME?=	2.2.0
GH_TUPLE?=      BurntSushi:toml:v0.4.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
                atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
                aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/vendor/github.com/aymanbagabas/go-osc52/v2 \
                beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
                cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
                charmbracelet:bubbles:v0.17.1:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
                charmbracelet:bubbletea:v0.25.0:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
                charmbracelet:lipgloss:v0.9.1:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
                containerd:console:1ae8d489ac81:containerd_console/vendor/github.com/containerd/console \
                davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
                evertras:bubble-table:v0.15.6:evertras_bubble_table/vendor/github.com/evertras/bubble-table \
                go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
                go-kit:kit:v0.12.0:go_kit_kit/vendor/github.com/go-kit/kit \
                go-kit:log:v0.2.0:go_kit_log/vendor/github.com/go-kit/log \
                go-logfmt:logfmt:v0.5.1:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
                go-resty:resty:v2.7.0:go_resty_resty_v2/vendor/github.com/go-resty/resty/v2 \
                go-validator:validator:b37d688a7fb0:go_validator_validator/vendor/gopkg.in/validator.v2 \
                go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
                go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
                golang-jwt:jwt:v4.0.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
                golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
                golang:net:v0.14.0:golang_net/vendor/golang.org/x/net \
                golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
                golang:sync:v0.3.0:golang_sync/vendor/golang.org/x/sync \
                golang:sys:090e33056c14:golang_sys/vendor/golang.org/x/sys \
                golang:term:v0.11.0:golang_term/vendor/golang.org/x/term \
                golang:text:v0.12.0:golang_text/vendor/golang.org/x/text \
                golang:xerrors:04be3eba64a2:golang_xerrors/vendor/golang.org/x/xerrors \
                golang:glog:23def4e6c14b:golang_glog/vendor/github.com/golang/glog \
                gomodule:redigo:v1.8.5:gomodule_redigo/vendor/github.com/gomodule/redigo \
                google:go-genproto:a5da7257a6f7:google_go_genproto/vendor/google.golang.org/genproto \
                google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
                grpc-ecosystem:go-grpc-middleware:v1.3.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
                grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
                grpc:grpc-go:v1.42.0:grpc_grpc_go/vendor/google.golang.org/grpc \
                hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
                jarcoal:httpmock:v1.1.0:jarcoal_httpmock/vendor/github.com/jarcoal/httpmock \
                jinzhu:configor:v1.2.1:jinzhu_configor/vendor/github.com/jinzhu/configor \
                lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
                mattn:go-isatty:v0.0.18:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
                mattn:go-localereader:v0.0.1:mattn_go_localereader/vendor/github.com/mattn/go-localereader \
                mattn:go-runewidth:v0.0.15:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
                matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
                muesli:ansi:2e021307bc4b:muesli_ansi/vendor/github.com/muesli/ansi \
                muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
                muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
                muesli:termenv:v0.15.2:muesli_termenv/vendor/github.com/muesli/termenv \
                otiai10:copy:v1.7.0:otiai10_copy/vendor/github.com/otiai10/copy \
                pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
                pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
                prometheus:client_golang:v1.11.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
                prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
                prometheus:common:v0.32.1:prometheus_common/vendor/github.com/prometheus/common \
                prometheus:procfs:v0.7.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
                protocolbuffers:protobuf-go:v1.31.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
                rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
                satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
                dgraph-io:ristretto:v0.1.1:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
                dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
                stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify
GO_PKGNAME=	github.com/${GH_ACCOUNT}/dralserver
GO_TARGET?=	./cmd/dralserver ./cmd/cleanupdralclones ./cmd/cleanupdralftpsexports ./cmd/cli

.include "${.CURDIR}/post-install.mk"

.include <bsd.port.mk>
