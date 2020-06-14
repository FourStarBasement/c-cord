#include "c_cord/client.h"
#include "c_cord/endpoints.h"

#include <string.h>
#include <jansson.h>

discord_client* global_discord_client;

discord_config* discord_config_new(char* _token, short _token_type, int _message_cache_size) {
    /* initialize a new discord_config */
    discord_config *p = malloc(sizeof *p);

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
    discord_client *p = malloc(sizeof *p);
    p->discord_config = _discord_config;
    return p;
}

void discord_client_run(discord_client* _discord_client) {
    /* init global_discord_client */
    global_discord_client = _discord_client;
    /* set client running to true */
    global_discord_client->run = true;

    char* gateway_resp = discord_get(global_discord_client->discord_config->token_type == BOT ? strcat(DISCORD_URL, GATEWAY_BOT) : strcat(DISCORD_URL, GATEWAY), discord_headers());
    json_t *root;
    json_error_t error;
    root = json_loads(gateway_resp, 0, &error);
    json_t* url_json = json_object_get(root, "url");
    char* url = json_string_value(url_json);

    if (!strcmp("", url)) {
        discord_ws_open(url, 443);
    } else {
        printf("invalid token entered, exiting...");
        exit(0);
    }
}

void discord_ws_response() {}

void discord_ws_connect() { }

void discord_ws_open(char* discord_wss_url, short port) { }

void discord_ws_close() {

}