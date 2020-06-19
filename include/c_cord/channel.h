#ifndef C_CORD_CHANNEL_H
#define C_CORD_CHANNEL_H

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

typedef struct {
    char* icon;
    snowflake category_id;
    snowflake guild_id;
    int position;
    int bitrate;
    int user_limit;
    int rate_limit_per_user;
    bool nsfw;
} GuildChannel;


typedef struct {
    ChannelType channel_type;
    union ChannelSpecifics {
        GuildChannel guild_channel;
    };
    char* name;
    char* topic;
    snowflake owner_id;
    snowflake application_id;
    char* last_pin_timestamp;
} Channel;

#endif //DISCORD_C_CHANNEL_H
