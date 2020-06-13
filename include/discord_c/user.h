#ifndef DISCORD_C_USER_H
#define DISCORD_C_USER_H

#include "utils.h"
#include <stdbool.h>

enum PremiumType {
    NO_NITRO,
    NITRO_CLASSIC,
    NITRO
};

struct User {
    /* username (ex: Intexisty) */
    char* username;
    /* discriminator (ex: 1744) */
    char* discriminator;
    /* hashed avatar */
    char* avatar_hash;
    /* whether or not it is a bot account */
    bool bot;
    /* whether or not it is discord system account */
    bool system;
    /* whether or not 2fa is enabled */
    bool mfa_enabled;
    char* locale;
    bool verified;
    /* email only shows on current logged in user */
    char* email;
    int flags;
    PremiumType premium_type;
    int public_flags;
    /* when the user was created */
    char* created_at;
    char* mention;
};

#endif //DISCORD_C_USER_H
