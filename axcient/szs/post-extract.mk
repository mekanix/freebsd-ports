post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/pubsub
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_pubsub}/pubsub ${WRKSRC}/vendor/cloud.google.com/go/pubsub
	# Temporarily delete cleanup_clones
	# CL-3414
	@${RM} freebsd-pkg/usr/local/etc/cron.d/cleanup_clones
