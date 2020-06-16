#include "user.h"

User* discord_user_new(json_t* json) {
    User* tmp = malloc(sizeof(*tmp));

    /* parse username */
    tmp->username = discord_get_string_value(json, "username");
    /* parse discriminator */
    tmp->discriminator = discord_get_int_value(json, "discriminator");
    /* parse id */
    tmp->id = discord_str_snowflake(discord_get_string_value(json, "id"));
    /* parse avatar_hash */
    tmp->avatar_hash = discord_get_string_value(json, "avatar_hash");
    /* parse bot */
    tmp->bot = discord_get_bool_value(json, "bot");
    /* parse system */
    tmp->system = discord_get_bool_value(json, "system");
    /* parse mfa */
    tmp->mfa_enabled = discord_get_bool_value(json, "mfa_enabled");
    /* parse verified */
    tmp->verified = discord_get_bool_value(json, "verified");
    /* parse badges */
    tmp->public_flags = discord_get_int_value(json, "public_flags");
    /* parse created_at */
    tmp->created_at = discord_get_string_value(json, "created_at");
    /* create mention */
    tmp->mention = malloc(25*sizeof(char));
    sprintf(tmp->mention, "<@!%llu>", tmp->id);

    return tmp;
}

void discord_user_delete(User* user) {
    free(user);
}