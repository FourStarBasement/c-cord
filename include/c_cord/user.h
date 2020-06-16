#ifndef C_CORD_USER_H
#define C_CORD_USER_H

#include "utils.h"
#include <stdbool.h>
#include <string.h>
#include <jansson.h>

enum PremiumType {
    NO_NITRO,
    NITRO_CLASSIC,
    NITRO
};

typedef struct {
    /* username (ex: Intexisty) */
    char* username;
    /* discriminator (ex: 1744) */
    char* discriminator;
    /* user id */
    snowflake id;
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
    enum PremiumType premium_type;
    int public_flags;
    /* when the user was created */
    char* created_at;
    char* mention;
} User;

User* discord_user_new(json_t* json);
User* discord_user_delete(User* user);
#endif //DISCORD_C_USER_H
