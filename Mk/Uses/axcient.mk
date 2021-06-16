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

.endif
