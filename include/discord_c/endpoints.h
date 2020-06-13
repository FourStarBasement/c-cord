#ifndef DISCORD_C_ENDPOINTS_H
#define DISCORD_C_ENDPOINTS_H

/* discord url */
#define DISCORD_URL "https://discord.com/api/v6"
#define DISCORD_WEBSOCKET_URL "wss://gateway.discord.gg?v=6&encoding=json"

/* channel endpoints */
#define CHANNEL "/channels/%s"
#define CHANNEL_INVITES "/channels/%s/invites"
#define CHANNEL_MESSAGE "/channels/%s/messages/%s"
#define CHANNEL_MESSAGES "/channels/%s/messages"
#define CHANNEL_MESSAGES_BULK_DELETE "/channels/%s/messages/bulk-delete"
#define CHANNEL_MESSAGE_REACTION "/channels/%s/messages/%s/reactions/%s"
#define CHANNEL_MESSAGE_REACTIONS "/channels/%s/messages/%s/reactions"
#define CHANNEL_MESSAGE_REACTION_ME "/channels/%s/messages/%s/reactions/%s/@me"
#define CHANNEL_MESSAGE_REACTION_USER "/channels/%s/messages/%s/reactions/%s/%s"
#define CHANNEL_PERMISSION "/channels/%s/permissions/%s"
#define CHANNEL_PIN "/channels/%s/pins/%s"
#define CHANNEL_PINS "/channels/%s/pins"
#define CHANNEL_RECIPIENT "/channels/%s/recipients/%s"
#define CHANNEL_TYPING "/channels/%s/typing"
#define CHANNEL_WEBHOOKS "/channels/%s/webhooks"

/* gateway endpoints */
#define GATEWAY "/gateway"
#define GATEWAY_BOT "/gateway/bot"

/* guild endpoints */
#define GUILD "/guilds/%s"
#define GUILDS "/guilds"
#define GUILD_AUDIT_LOGS "/guilds/%s/audit-logs"
#define GUILD_BAN "/guilds/%s/bans/%s"
#define GUILD_BANS "/guilds/%s/bans"
#define GUILD_CHANNELS "/guilds/%s/channels"
#define GUILD_EMBED "/guilds/%s/embed"
#define GUILD_EMOJI "/guilds/%s/emojis/%s"
#define GUILD_EMOJIS "/guilds/%s/emojis"
#define GUILD_INTEGRATION "/guilds/%s/integrations/%s"
#define GUILD_INTEGRATIONS "/guilds/%s/integrations"
#define GUILD_INTEGRATION_SYNC "/guilds/%s/integrations/%s/sync"
#define GUILD_INVITES "/guilds/%s/invites"
#define GUILD_MEMBER "/guilds/%s/members/%s"
#define GUILD_MEMBERS "/guilds/%s/members"
#define GUILD_MEMBER_ME_NICK "/guilds/%s/members/@me/nick"
#define GUILD_MEMBER_ROLE "/guilds/%s/members/%s/roles/%s"
#define GUILD_PRUNE "/guilds/%s/prune"
#define GUILD_REGIONS "/guilds/%s/regions"
#define GUILD_ROLE "/guilds/%s/roles/%s"
#define GUILD_ROLES "/guilds/%s/roles"
#define GUILD_WEBHOOKS "/guilds/%s/webhooks"
#define INVITE "/invites/%s"

/* user endpoints */
#define OAUTH2_APPLICATION_ME "/oauth2/applications/@me"
#define USER "/users/%s"
#define USER_ME "/users/@me"
#define USER_ME_CHANNELS "/users/@me/channels"
#define USER_ME_CONNECTIONS "/users/@me/connections"
#define USER_ME_GUILD "/users/@me/guilds/%s"
#define USER_ME_GUILDS "/users/@me/guilds"
#define VOICE_REGIONS "/voice/regions"

/* webhook endpoints */
#define WEBHOOK "/webhooks/%s"
#define WEBHOOK_TOKEN "/webhooks/%s/%s"
#define WEBHOOK_TOKEN_GITHUB "/webhooks/%s/%s/github"
#define WEBHOOK_TOKEN_SLACK "/webhooks/%s/%s/slack"

#endif //DISCORD_C_ENDPOINTS_H
