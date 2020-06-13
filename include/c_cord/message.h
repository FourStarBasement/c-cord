#ifndef C_CORD_MESSAGE_H
#define C_CORD_MESSAGE_H

#include <stdbool.h>
#include "channel.h"
#include "guild.h"
#include "user.h"
#include "utils.h"

struct Message {
    Channel channel;
    User author;
    char* content;
    char* timestamp;
    char* edited_timestamp;
    bool tts;
    bool mention_everyone;
    bool pinned;
    int type;
    int flags;
};

struct GuildMessage {
    Message internal_message;
    Guild guild;
    GuildChannel guild_channel;
    snowflake webhook_id;
};

struct Message* discord_message_new(Channel* channel, User* author, char* content, char* timestamp, char* edited_timestamp, bool tts, bool mention_everyone, bool pinned, int type, int flags);
struct GuildMessage* discord_guild_message_new(Message* internal_message, Guild* _guild, GuildChannel _guild_channel, snowflake _webhook_id);

#endif //DISCORD_C_MESSAGE_H
