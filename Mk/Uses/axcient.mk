# axcient.mk - Stuff for Axcient's proprietary ports
#
# Feature:	axcient
# Usage:	USES=axcient
# Valid ARGS:	(none)

.if !defined(_INCLUDE_USES_AXCIENT_MK)
_INCLUDE_USES_AXCIENT_MK=	yes

.if !empty(axcient_ARGS)
IGNORE=	Incorrect 'USES+= axcient:${axcient_ARGS}' axcient takes no arguments
.endif

LICENSE=        AXCIENT
LICENSE_NAME=   AXCIENT
LICENSE_TEXT=   "Copyright Axcient, inc.  All Rights Reserved"
LICENSE_PERMS=  pkg-mirror  # Not really, only since our pkg server is private

FETCH_DEPENDS+=		git:devel/git

USE_GITHUB=		yes
GH_ACCOUNT=		Axcient

# Most if not all of Axcient's software is hosted in private Github repos.
# Since they're private, the distfiles can't be fetched over https.  Instead,
# we fetch them using git clone with ssh.  XXX code assumes that only a single
# distfile is private.  If DISTFILES contains more than one file (such as in go
# builds) the remainder will be fetched the usual way.
pre-fetch: git-fetch
git-fetch:
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}" ]; then \
	 echo "===>   Cloning from git@github.com:${GH_ACCOUNT}/${GH_PROJECT}" && \
	 ${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
	 cd ${DISTDIR}/${DIST_SUBDIR} && \
	  GITDIR=$$(env TMPDIR=. mktemp -dt ${GH_PROJECT} | sed 's:./::') && \
	  chmod 755 "$${GITDIR}" && \
	  git clone -q --depth=1 --recurse-submodules git@github.com:${GH_ACCOUNT}/${GH_PROJECT} "$${GITDIR}" && \
	  cd "$${GITDIR}" && \
	  git fetch --tags 2>/dev/null && \
	  git fetch origin ${GH_TAGNAME} && \
	  git checkout ${GH_TAGNAME} 2>/dev/null && \
	  ${RM} -r .git && \
	  cd .. && \
	  ${FIND} "$${GITDIR}" -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z '{}' \; && \
	  ${FIND} "$${GITDIR}" -print0 | ${SETENV} LC_ALL=C ${SORT} -z | \
	  ${TAR} czf ${DISTNAME}${EXTRACT_SUFX} -s "/$${GITDIR}/${GH_PROJECT}-${GH_TAGNAME_EXTRACT}/" --format=bsdtar --uid 0 --gid 0 --options gzip:!timestamp --no-recursion --null -T - && \
	${RM} -r "$${GITDIR}"; \
	fi

.ifndef defined(rewritable_variables)
_ASSIGMENT_MODIFIER=?
.endif

update-go-port: clean
	@make update-portversion
	@make makesum
	@make DISABLE_LICENSES=yes update-gomod-vendor
	@make makesum

update-port: clean
	@make update-portversion
	@make makesum

# This target creates a brach with changes in distinfo and Makefile in the current directory
# Usage: make push-branch-with-update
push-branch-with-update:
	@branch=cl/update-${PORTNAME}${PKGNAMESUFFIX}-to-${PORTVERSION}; \
	git branch -m $${branch}; \
	git add ${.CURDIR}/Makefile; \
	git add ${.CURDIR}/distinfo; \
	git commit -m "Update ${PORTNAME}${PKGNAMESUFFIX} to ${PORTVERSION}"; \
	git push origin $${branch}; \

# This target updates PORTVERSION, GH_TAGNAME and resets PORTREVISION in Makefile in the current directory
# Usage: make update-portversion version=1.16.0
update-portversion:
	@${ECHO_MSG} "===> version=${version} was passed"; \
	if [ -z "${version}" ]; then \
		${ECHO_MSG} "===> Please specify new port version"; exit 1; \
	fi
	@tagname=`echo "${version}" | sed "s|.rc|-rc|g"`; \
	${SED} -i '' -E "s|^PORTVERSION[\?]{0,1}=[\t|\s]{0,}.*|PORTVERSION${_ASSIGMENT_MODIFIER}=\t${version}|g" ${.CURDIR}/Makefile; \
	${ECHO_MSG} "===> Package version was updated from ${PORTVERSION} to ${version}"; \
	${SED} -i '' -E "s|^GH_TAGNAME[\?]{0,1}=[\t|\s]{0,}.*|GH_TAGNAME${_ASSIGMENT_MODIFIER}=\t$${tagname}|g" ${.CURDIR}/Makefile; \
	${ECHO_MSG} "===> GitHub tagname was updated from ${GH_TAGNAME} to $${tagname}"; \
	${SED} -i '' -E "/^PORTREVISION[\?]{0,1}=[\t|\s]{0,}.*/d" ${.CURDIR}/Makefile; \
	${ECHO_MSG} "===> Port revision was reset"; \

# This target updates GH_TUPLE in Makefile in the current directory
# To accept commercial licenses call it with DISABLE_LICENSES=yes
# Usage: DISABLE_LICENSES=yes make update-gomod-vendor
update-gomod-vendor: gomod-vendor-deps patch
	@if ! type portedit > /dev/null 2>&1; then \
		${ECHO_MSG} "===> Please install \"ports-mgmt/portfmt\""; exit 1; \
	fi
	@cd ${WRKSRC}; ${SETENV} ${GO_ENV} ${GO_CMD} mod vendor; \
	[ -r vendor/modules.txt ] && ${_MODULES2TUPLE_CMD} vendor/modules.txt | sed "s|GH_TUPLE=|GH_TUPLE${_ASSIGMENT_MODIFIER}=|g" | portedit merge -i ${.CURDIR}/Makefile; \

.endif

