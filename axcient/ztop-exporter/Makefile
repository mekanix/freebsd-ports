PORTNAME=	ztop-exporter
PORTVERSION=	0.1.0.20230522
CATEGORIES=	axcient net-mgmt
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	asomers@axcient.com
COMMENT=	Export ZFS performance statistics to Prometheus

USES=		axcient cargo

GH_PROJECT=	ztop-exporter
GH_TAGNAME=	fa4ced93efc999915a744410bd1ea587bdd7e442

CARGO_CRATES=	aho-corasick-0.7.18 \
		ascii-1.1.0 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		byteorder-1.4.3 \
		cfg-if-1.0.0 \
		chunked_transfer-1.4.1 \
		clap-3.2.22 \
		clap_derive-3.2.18 \
		clap_lex-0.2.4 \
		fnv-1.0.7 \
		form_urlencoded-1.1.0 \
		hashbrown-0.12.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		humanize-rs-0.1.5 \
		idna-0.3.0 \
		indexmap-1.9.1 \
		itoa-1.0.6 \
		lazy_static-1.4.0 \
		libc-0.2.139 \
		lock_api-0.4.9 \
		log-0.4.17 \
		memchr-2.4.1 \
		once_cell-1.15.0 \
		os_str_bytes-6.3.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.7 \
		percent-encoding-2.2.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.36 \
		prometheus-0.13.3 \
		prometheus_exporter-0.8.5 \
		quote-1.0.15 \
		redox_syscall-0.2.11 \
		regex-1.5.5 \
		regex-syntax-0.6.25 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		serde-1.0.163 \
		smallvec-1.10.0 \
		strsim-0.10.0 \
		syn-1.0.89 \
		sysctl-0.4.4 \
		termcolor-1.1.3 \
		textwrap-0.15.2 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		time-0.3.21 \
		time-core-0.1.1 \
		time-macros-0.2.9 \
		tiny_http-0.10.0 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		unicode-bidi-0.3.13 \
		unicode-normalization-0.1.22 \
		unicode-xid-0.2.2 \
		url-2.3.1 \
		version_check-0.9.4 \
		walkdir-2.3.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.45.0 \
		windows-targets-0.42.2 \
		windows_aarch64_gnullvm-0.42.2 \
		windows_aarch64_msvc-0.42.2 \
		windows_i686_gnu-0.42.2 \
		windows_i686_msvc-0.42.2 \
		windows_x86_64_gnu-0.42.2 \
		windows_x86_64_gnullvm-0.42.2 \
		windows_x86_64_msvc-0.42.2

PLIST_FILES=	bin/${PORTNAME}

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
