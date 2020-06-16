#include "user.h"

User* discord_user_new(json_t* json) {
    User* tmp;

    /* parse username */
    json_t* username_json = json_object_get(json, "username");
    if (!json_is_string(username_json)) {
        printf("error parsing username");
    } else {
        tmp->username = json_string_value(username_json);
    }
    json_decref(username_json);
    free(username_json);

    /* parse discriminator */
    json_t* discriminator_json = json_object_get(json, "discriminator");
    if (!json_is_integer(discriminator_json)) {
        printf("error parsing discriminator");
    } else {
        tmp->discriminator = json_integer_value(discriminator_json);
    }
    json_decref(discriminator_json);
    free(discriminator_json);

    json_t* id_json = json_object_get(json, "id");
    if(!json_is_string(id_json)) {
        printf("error parsing id");
    } else {
        tmp->id = atoll(json_string_value(id_json));
    }
    json_decref(id_json);
    free(id_json);

    /* parse avatar_hash */
    json_t* avatarhash_json = json_object_get(json, "avatar_hash");
    if (!json_is_string(avatarhash_json)) {
        printf("error parsing username");
    } else {
        tmp->avatar_hash = json_integer_value(avatarhash_json);
    }
    json_decref(avatarhash_json);
    free(avatarhash_json);

    /* parse bot */
    json_t* bot_json = json_object_get(json, "bot");
    if (!json_is_boolean(bot_json)) {
        printf("error parsing bot");
    } else {
        tmp->bot = json_boolean_value(bot_json);
    }
    json_decref(bot_json);
    free(bot_json);

    /* parse system */
    json_t* system_json = json_object_get(json, "system");
    if (!json_is_boolean(system_json)) {
        printf("error parsing system");
    } else {
        tmp->system = json_boolean_value(system_json);
    }
    json_decref(system_json);
    free(system_json);

    /* parse mfa */
    json_t* mfa_json = json_object_get(json, "mfa");
    if (!json_is_boolean(mfa_json)) {
        printf("error parsing mfa");
    } else {
        tmp->mfa_enabled = json_boolean_value(mfa_json);
    }
    json_decref(mfa_json);
    free(mfa_json);

    /* parse verified */
    json_t* verified_json = json_object_get(json, "verified");
    if (!json_is_boolean(mfa_json)) {
        printf("error parsing verified");
    } else {
        tmp->verified = json_boolean_value(verified_json);
    }
    json_decref(mfa_json);
    free(mfa_json);

    /* parse badges */
    json_t* public_flags_json = json_object_get(json, "public_flags");
    if (!json_is_integer(public_flags_json)) {
        printf("error parsing public flags");
    } else {
        tmp->public_flags = json_integer_value(public_flags_json);
    }
    json_decref(public_flags_json);
    free(public_flags_json);

    /* parse created_at */
    json_t* created_at_json = json_object_get(json, "created_at");
    if (!json_is_string(created_at_json)) {
        printf("error parsing created_at_json");
    } else {
        tmp->created_at = json_string_value(created_at_json);
    }
    json_decref(created_at_json);
    free(created_at_json);

    return tmp;
}

User* discord_user_delete(User* user) {
    free(user);
}