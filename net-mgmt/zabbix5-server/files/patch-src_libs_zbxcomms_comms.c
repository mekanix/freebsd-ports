--- src/libs/zbxcomms/comms.c.orig	2020-04-30 15:29:30 UTC
+++ src/libs/zbxcomms/comms.c
@@ -1144,7 +1144,7 @@ int	zbx_tcp_listen(zbx_socket_t *s, const char *listen
 					goto out;
 			}
 
-			if (ZBX_PROTO_ERROR == listen(s->sockets[s->num_socks], SOMAXCONN))
+			if (ZBX_PROTO_ERROR == listen(s->sockets[s->num_socks], INT_MAX))
 			{
 				zbx_set_socket_strerror("listen() for [[%s]:%s] failed: %s",
 						ip ? ip : "-", port, strerror_from_system(zbx_socket_last_error()));
@@ -1305,7 +1305,7 @@ int	zbx_tcp_listen(zbx_socket_t *s, const char *listen
 			goto out;
 		}
 
-		if (ZBX_PROTO_ERROR == listen(s->sockets[s->num_socks], SOMAXCONN))
+		if (ZBX_PROTO_ERROR == listen(s->sockets[s->num_socks], INT_MAX))
 		{
 			zbx_set_socket_strerror("listen() for [[%s]:%hu] failed: %s",
 					ip ? ip : "-", listen_port, strerror_from_system(zbx_socket_last_error()));
