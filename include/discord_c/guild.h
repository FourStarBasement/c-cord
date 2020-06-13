//
// Created by intexisty on 5/10/20.
//

#ifndef DISCORD_C_GUILD_H
#define DISCORD_C_GUILD_H

#include <stdbool.h>

struct Guild {
    char* name;
    char* icon;
    char* splash;
    char* discovery_splash;
    char* owner;
    int permissions;
    char* region;
    int afk_timeout;
    bool embed_enabled;
    int verification_level;
    bool widget_enabled;
    int system_channel_flags;
    char* joined_at;
    bool large;
    bool unavailable;
    int member_count;
    int max_presences;
    int max_members;
    char* vanity_url_code;
    char* description;
    char* banner;
    int premium_subscription_count;
};

#endif //DISCORD_C_GUILD_H
