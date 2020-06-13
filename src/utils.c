#include "discord_c/utils.h"
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include "client.h"

size_t write_memory(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct memory_struct *mem = (struct memory_struct *)userp;

    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if (ptr == NULL) {
        /* out of memory! */
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

struct curl_slist* discord_headers() {
    struct curl_slist* headers = NULL;

    headers = curl_slist_append(headers, "User-Agent: DiscordBot (https://github.com/intexisty/discord.c, v0.0.0)");
    headers = curl_slist_append(headers, "X-RateLimit-Precision: millisecond");
    /* discord requires bot accounts to have Bot added to the front of the token */
    headers = curl_slist_append(headers, strcat(global_discord_client->discord_config->token_type == BOT ? "Authorization: Bot " : "Authorization: ", global_discord_client->discord_config->token));

    return headers;
}

char* discord_get(char* url, struct curl_slist* headers) {
    CURL *curl;
    CURLcode res;

    struct memory_struct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_memory);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return chunk.memory;
}

char* discord_post(char* url, char* body, struct curl_slist* headers) {
    CURL *curl;
    CURLcode res;

    struct memory_struct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_memory);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return chunk.memory;
}

char* discord_patch(char* url, char* body, struct curl_slist* headers) {
    /* todo: implement */
    return "d";
}

char* discord_delete(char* url, struct curl_slist* headers) {
    /* todo: implement */
    return 'd';
}