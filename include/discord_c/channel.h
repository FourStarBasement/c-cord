#ifndef DISCORD_C_CHANNEL_H
#define DISCORD_C_CHANNEL_H

#include "utils.h"
#include <stdbool.h>

enum ChannelType {
    GUILD_TEXT,
    DM,
    GUILD_VOICE,
    GROUP_DM,
    GROUP_CATEGORY,
    GROUP_NEWS,
    GROUP_STORE
};

struct Channel {
    ChannelType channel_type;
    snowflake guild_id;
    int position;
    char* name;
    char* topic;
    bool nsfw;
    int bitrate;
    int user_limit;
    int rate_limit_per_user;
    char* icon;
    snowflake owner_id;
    snowflake application_id;
    snowflake category_id;
    char* last_pin_timestamp;
};

struct GuildChannel {
    struct Channel *internal_channel;
    snowflake guild_id;
};

#endif //DISCORD_C_CHANNEL_H
