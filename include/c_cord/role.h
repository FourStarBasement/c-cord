#ifndef C_CORD_ROLE_H
#define C_CORD_ROLE_H

#include "permissions.h"
#include <stdbool.h>

struct Role {
    char* name;
    int color;
    bool hoist;
    int position;
    Permission permissions;
    bool managed;
    bool mentionable;
};

#endif //DISCORD_C_ROLE_H
