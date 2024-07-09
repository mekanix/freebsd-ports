# $FreeBSD$

PORTNAME=	szs
PORTVERSION?=	2.3.0
PORTREVISION?=	1
CATEGORIES=	axcient
MASTER_SITES=	GH

MAINTAINER=	dprokopchenkov@axcient.com
COMMENT?=	Szs-op components

FETCH_DEPENDS+=	git:devel/git
ADD_MBR_DEPENDS?=	add_mbr:axcient/add_mbr
RUN_DEPENDS+=	mbuffer:misc/mbuffer \
		lzop:archivers/lzop \
		pv:sysutils/pv \
		wget:ftp/wget \
		fuse-ext2:sysutils/fusefs-ext2 \
		xfs-fuse:sysutils/fusefs-xfuse \
		mount.exfat:sysutils/fusefs-exfat \
		ntfs-3g:sysutils/fusefs-ntfs \
		${LOCALBASE}/lib/pam_pwdfile.so:security/pam_pwdfile \
		${ADD_MBR_DEPENDS}

USES=		axcient go:modules ssl:run
USE_LDCONFIG=	yes
GH_PROJECT=	szs-op
GH_TAGNAME?=	2.3.0
GH_TUPLE?=	\
		RichardKnop:logging:1a693bdd4fae:richardknop_logging/vendor/github.com/RichardKnop/logging \
		RichardKnop:machinery:v1.10.6:richardknop_machinery/vendor/github.com/RichardKnop/machinery \
		aws:aws-sdk-go:v1.37.16:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bradfitz:gomemcache:a41fca850d0b:bradfitz_gomemcache/vendor/github.com/bradfitz/gomemcache \
		census-instrumentation:opencensus-go:v0.22.6:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		coreos:go-semver:v0.3.1:coreos_go_semver/vendor/github.com/coreos/go-semver \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgryski:go-rendezvous:9f7001d12a5f:dgryski_go_rendezvous/vendor/github.com/dgryski/go-rendezvous \
		dnephin:pflag:v1.0.7:dnephin_pflag/vendor/github.com/dnephin/pflag \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		getsentry:sentry-go:v0.10.0:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		gin-contrib:pprof:v1.3.0:gin_contrib_pprof/vendor/github.com/gin-contrib/pprof \
		gin-contrib:sse:v0.1.0:gin_contrib_sse/vendor/github.com/gin-contrib/sse \
		gin-gonic:gin:v1.7.0:gin_gonic_gin/vendor/github.com/gin-gonic/gin \
		go-playground:locales:v0.13.0:go_playground_locales/vendor/github.com/go-playground/locales \
		go-playground:universal-translator:v0.17.0:go_playground_universal_translator/vendor/github.com/go-playground/universal-translator \
		go-playground:validator:v10.4.1:go_playground_validator_v10/vendor/github.com/go-playground/validator/v10 \
		redis:go-redis:v8.11.4:go_redis_redis_v8/vendor/github.com/go-redis/redis/v8 \
		go-redsync:redsync:v4.6.0:go_redsync_redsync_v4/vendor/github.com/go-redsync/redsync/v4 \
		go-resty:resty:v2.7.0:go_resty_resty_v2/vendor/github.com/go-resty/resty/v2 \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:089bfa567519:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:83fdc39ff7b5:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.5.0:golang_mock/vendor/github.com/golang/mock \
		golang:mod:9b9b3d81d5e3:golang_mod/vendor/golang.org/x/mod \
		golang:net:2871e0cb64e4:golang_net/vendor/golang.org/x/net \
		golang:oauth2:010130855d6c:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.2:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:9388b58f7150:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.10:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		gomodule:redigo:v2.0.0:gomodule_redigo/vendor/github.com/gomodule/redigo \
		google:go-cmp:v0.5.8:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:bba0dbe2a9ea:google_go_genproto/vendor/google.golang.org/genproto \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.39.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:pubsub/v1.10.0:googleapis_google_cloud_go_pubsub \
		googleapis:google-cloud-go:v0.76.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gotestyourself:gotestsum:v1.7.0:gotestyourself_gotestsum/vendor/gotest.tools/gotestsum \
		grpc:grpc-go:v1.35.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		jarcoal:httpmock:v1.3.0:jarcoal_httpmock/vendor/github.com/jarcoal/httpmock \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jonboulle:clockwork:v0.2.2:jonboulle_clockwork/vendor/github.com/jonboulle/clockwork \
		json-iterator:go:v1.1.10:json_iterator_go/vendor/github.com/json-iterator/go \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		kelseyhightower:envconfig:v1.4.0:kelseyhightower_envconfig/vendor/github.com/kelseyhightower/envconfig \
		klauspost:compress:v1.11.7:klauspost_compress/vendor/github.com/klauspost/compress \
		leodido:go-urn:v1.2.0:leodido_go_urn/vendor/github.com/leodido/go-urn \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		mongodb:mongo-go-driver:v1.4.6:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.10.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.18.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.28.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		robfig:cron:v3.0.1:robfig_cron_v3/vendor/github.com/robfig/cron/v3 \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		streadway:amqp:v1.0.0:streadway_amqp/vendor/github.com/streadway/amqp \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		ugorji:go:v1.1.7:ugorji_go_codec/vendor/github.com/ugorji/go \
		xdg:scram:7eeb5667e42c:xdg_scram/vendor/github.com/xdg/scram \
		xdg:stringprep:v1.0.0:xdg_stringprep/vendor/github.com/xdg/stringprep
CONFLICTS_INSTALL?=	szs-stg

SUB_FILES=	zfs-holds.lua 900.zfs-holds

GO_PKGNAME=	github.com/${GH_ACCOUNT}/szs-op
GO_BUILDFLAGS=	-ldflags "-X=main.version=${PORTVERSION}"
GO_TARGET?=	./cmd/api ./cmd/jobs ./cmd/statistics ./cmd/safetyarchivecleanup ./cmd/cleanupclones ./cmd/snapshotscleanup ./cmd/clonesnapshots

# go.mk doesn't have any code for building shared libraries
post-build:
	${MKDIR} ${WRKDIR}/lib
	cd ${GO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} build `echo ${GO_BUILDFLAGS} | ${SED} 's/buildmode=exe/buildmode=c-shared/'` -o ${WRKDIR}/lib/libszs-op.so cmd/shared/binding.go

.include "${.CURDIR}/post-extract.mk"
.include "${.CURDIR}/post-install.mk"

.include <bsd.port.mk>
