# $FreeBSD$

PORTNAME=	cloudserver
PORTVERSION=	2.0.4
PORTREVISION= 	1
CATEGORIES=	axcient

MAINTAINER=	nsemchenkov@axcient.com
COMMENT=	Cloudserver tool

LIB_DEPENDS=	libszs-op.so:axcient/szs
USES=		axcient go:modules

CONFLICTS_INSTALL=	cloudserver-stg \
			cloudserver2 \
			cloudserver2-dev \
			cloudserver2-stg

GH_TAGNAME=	v${PORTVERSION}
GH_TUPLE=	\
		apache:thrift:327ebb6c2b6d:apache_thrift/vendor/git.apache.org/thrift.git \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-check:check:788fd7840127:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.57.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-resty:resty:v2.3.0:go_resty_resty_v2/vendor/github.com/go-resty/resty/v2 \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:mock:v1.4.3:golang_mock/vendor/github.com/golang/mock \
		golang:net:627f9648deb9:golang_net/vendor/golang.org/x/net \
		golang:sys:85ca7c5b95cd:golang_sys/vendor/golang.org/x/sys \
		kr:pretty:v0.1.0:kr_pretty/vendor/github.com/kr/pretty \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rs:xid:v1.2.1:rs_xid/vendor/github.com/rs/xid \
		smartystreets:goconvey:v1.6.4:smartystreets_goconvey/vendor/github.com/smartystreets/goconvey \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify

GO_PKGNAME=	github.com/${GH_ACCOUNT}/cloudserver
GO_BUILDFLAGS=  -ldflags "-X=main.version=${PORTVERSION}"
GO_TARGET=	cloudserver

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rsyslog.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/cloudserver
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-pkg/usr/local/etc/rc.d/cloudserver ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/rsyslog.d/cloudserver.conf ${STAGEDIR}${EXAMPLESDIR}/rsyslog.d
	${INSTALL_DATA} ${WRKSRC}/freebsd-pkg/usr/local/etc/cloudserver/cloudserver.conf.example  ${STAGEDIR}${ETCDIR}/cloudserver.conf.sample

.include <bsd.port.mk>
