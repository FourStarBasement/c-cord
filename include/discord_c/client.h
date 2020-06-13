#ifndef DISCORD_C_CLIENT_H
#define DISCORD_C_CLIENT_H

#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

enum token_type {
    BOT,
    USER
};

typedef struct {
    short token_type;
    char* token;
    int message_cache_size;
} discord_config;

typedef struct {
    bool ready;
    bool reconnecting;
    bool disconnected;
    bool stay_disconnected;
    bool run;
    char* session_id;
    char* gateway_endpoint;
    discord_config *discord_config;
} discord_client;

extern discord_client* global_discord_client;

discord_config* discord_config_new(char* _token, short _token_type, int _message_cache_size);
discord_client* discord_client_new(discord_config* _discord_config);

void discord_client_run(discord_client* _discord_client);
void discord_hb_thread();
void discord_ws_open(char* discord_wss_url, short port);
void discord_ws_close();

#endif //DISCORD_C_CLIENT_H
