#ifndef C_CORD_EMOJI_H
#define C_CORD_EMOJI_H

#include <stdbool.h>
#include "user.h"

struct Emoji {
    char* name;
    char* unicode;
    User user;
    bool require_colons;
    bool managed;
    bool animated;
};

char* emoji_tostring(struct Emoji* _emoji);

#endif //DISCORD_C_EMOJI_H
