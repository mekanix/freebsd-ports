PORTNAME=         rsync-proxy
PORTVERSION=      1.1.0.rc1
PKGNAMESUFFIX=    -stg
CATEGORIES=       axcient
MAINTAINER=       kklimov@axcient.com


CONFLICTS_INSTALL=    rsync-proxy-dev rsync-proxy
LIB_DEPENDS=          libszs-op.so:axcient/szs-stg
#TODO remove 1.21 pinned version when `GO_DEFAULT` will be go1.21 or higher, the USES should be: `USES=axcient go:modules`
USES=                 axcient go:1.21,modules

GH_TAGNAME=  1.1.0-rc1
GH_TUPLE=	\
		alexflint:go-arg:v1.4.3:alexflint_go_arg/vendor/github.com/alexflint/go-arg \
		alexflint:go-scalar:v1.2.0:alexflint_go_scalar/vendor/github.com/alexflint/go-scalar \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgraph-io:ristretto:v0.1.1:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-resty:resty:v2.10.0:go_resty_resty_v2/vendor/github.com/go-resty/resty/v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:glog:v1.1.2:golang_glog/vendor/github.com/golang/glog \
		golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
		golang:net:v0.18.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.5.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.14.0:golang_sys/vendor/golang.org/x/sys \
		gomodule:redigo:v1.8.9:gomodule_redigo/vendor/github.com/gomodule/redigo \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		stretchr:testify:v1.8.4:stretchr_testify/vendor/github.com/stretchr/testify

GO_PKGNAME=  github.com/${GH_ACCOUNT}/rsync-proxy
GO_TARGET=   ./cmd/proxy

.include "${.CURDIR}/post-install.mk"
.include <bsd.port.mk>
