post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/pubsub
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_pubsub}/pubsub ${WRKSRC}/vendor/cloud.google.com/go/pubsub

