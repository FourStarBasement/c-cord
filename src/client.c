#include "c_cord/client.h"
#include "c_cord/endpoints.h"

#include <string.h>
#include <OpenSSL/ssl.h>
#include <OpenSSL/bio.h>
#include <OpenSSL/err.h>
#include <OpenSSL/pem.h>
#include <uv.h>

discord_client* global_discord_client;

discord_config* discord_config_new(char* _token, short _token_type, int _message_cache_size) {
	/* initialize a new discord_config */
	discord_config* p = malloc(sizeof(*p));

	/* copy token over */
	p->token = _token;
	/* set token type */
	p->token_type = _token_type;
	/* set message cache size */
	p->message_cache_size = _message_cache_size;

	return p;
}

discord_client* discord_client_new(discord_config* _discord_config) {
	/* initialize a new discord_client */
	discord_client* p = malloc(sizeof(*p));
	p->discord_config = _discord_config;
	return p;
}

void discord_client_run(discord_client* _discord_client) {
	/* init global_discord_client */
	global_discord_client = _discord_client;
	/* set client running to true */
	global_discord_client->run = true;

	char* gateway_resp;
	if (global_discord_client->discord_config->token_type == BOT) {
	    gateway_resp = discord_get(GATEWAY_BOT, discord_headers());
	} else {
	    gateway_resp = discord_get(GATEWAY, discord_headers());
	}

	/* parse json */
	json_t* root;
	json_error_t error;
	root = json_loads(gateway_resp, 0, &error);
	free(gateway_resp);
	char* url = json_string_value(json_object_get(root, "url"));
	free(root);
	printf(url);
	if (url == NULL) {
		printf("invalid token entered, exiting...");
		exit(0);
	} else {
		/* discord uses port 443 */
		discord_ws_open(url, 443);
	}
}

void alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf) {
    buf->base = malloc(suggested_size);
    buf->len = suggested_size;
}

void discord_ws_response(uv_stream_t *client, ssize_t nread, const uv_buf_t *buf) {
    if (nread < 0) {
        if (nread != UV_EOF)
            fprintf(stderr, "Read error %s\n", uv_err_name(nread));
        uv_close((uv_handle_t*) client, NULL);
        free(buf->base);
        free(client);
        return;
    }

    char *data = (char*) malloc(sizeof(char) * (nread+1));
    data[nread] = '\0';
    strncpy(data, buf->base, nread);

    fprintf(stderr, "%s", data);
    free(data);
    free(buf->base);
}

void discord_ws_connect(uv_connect_t* req, int status) {
    if (status < 0) {
        fprintf(stderr, "connect failed error %s\n", uv_err_name(status));
        free(req);
        return;
    }

    uv_read_start((uv_stream_t*) req->handle, alloc_buffer, discord_ws_response);
    free(req);
}

void discord_ws_open(char* discord_wss_url, short port) {
    /* setup websocket and loop for libuv */
    uv_loop_t *loop = malloc(sizeof(uv_loop_t));
    uv_loop_init(loop);
    uv_tcp_t* socket = (uv_tcp_t*)malloc(sizeof(uv_tcp_t));
    uv_tcp_init(loop, socket);

    /* setup connection to discord websocket */
    uv_connect_t* connect = (uv_connect_t*)malloc(sizeof(uv_connect_t));
    struct sockaddr_in dest;
    uv_ip4_addr(discord_wss_url, port, &dest);

    uv_tcp_connect(connect, socket, (const struct sockaddr*)&dest, discord_ws_connect);
    uv_run(loop, UV_RUN_DEFAULT);
}

void discord_ws_close() {

}
