#ifndef C_CORD_UTILS_H
#define C_CORD_UTILS_H

#include <stdbool.h>
#include "client.h"
#include <jansson.h>

/* epoch */
#define DISCORD_EPOCH = 1420070400000

enum OP_CODES {
    DISPATCH,
    HEART_BEAT,
    IDENTIFY,
    STATUS_UPDATE,
    VOICE_STATE_UPDATE,
    VOICE_SERVER_PING,
    RESUME,
    RECONNECT,
    REQUEST_GUILD_MEMBERS,
    INVALID_SESSION,
    HELLO,
    HEART_BEAT_ACK
};

typedef unsigned long snowflake;

/* nanoseconds to microseconds (ns->μs) */
inline double nstous(double ns) { return ns / 1000; }

/* microseconds to milliseconds (μs->ms) */
inline double ustoms(double us) { return nstous(us); }

/* milliseconds to seconds (ms->s) */
inline double mstos(double ms) { return nstous(ms); }

/* seconds to minutes (s->min) */
inline double stomin(double s) { return s / 60; }

/* minutes to hours (min->h) */
inline double mintoh(double min) { return stomin(min); }

/* hours to days (h->d) */
inline double htoday(double h) { return h / 24; }

/* days to weeks (d->w) */
inline double dtow(double d) { return d / 7; }

struct memory_struct {
    char *memory;
    size_t size;
};

void init_memory(struct memory_struct *s);
size_t write_memory(void *contents, size_t size, size_t nmemb, void *userp);

struct curl_slist* discord_headers();
struct curl_slist* discord_additional_headers(char* additional_headers);

char* discord_get(char* url, struct curl_slist* headers);
char* discord_post(char* url, char* body, struct curl_slist* headers);
char* discord_patch(char* url, char* body, struct curl_slist* headers) ;
char* discord_delete(char* url, struct curl_slist* headers);

char* discord_get_string_value(json_t* json, char* key);
bool discord_get_bool_value(json_t* json, char* key);
int discord_get_int_value(json_t* json, char* key);

inline snowflake discord_str_snowflake(char* _snowflake) { return atoll(_snowflake); }
char* discord_snowflake_str(snowflake _snowflake);

#endif //DISCORD_C_UTILS_H