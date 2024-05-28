/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** destroy_player
*/

#include "my_rpg.h"

void destroy_player(player_t *player)
{
    sfTexture_destroy(player->kn_btt_sprite->texture);
    sfSprite_destroy(player->kn_btt_sprite->sprite);
    free(player->kn_btt_sprite);
    sfTexture_destroy(player->kn_sh_1__sprite->texture);
    sfSprite_destroy(player->kn_sh_1__sprite->sprite);
    free(player->kn_sh_1__sprite);
    sfTexture_destroy(player->kn_sh_2__sprite->texture);
    sfSprite_destroy(player->kn_sh_2__sprite->sprite);
    free(player->kn_sh_2__sprite);
    sfTexture_destroy(player->kn_sh_3__sprite->texture);
    sfSprite_destroy(player->kn_sh_3__sprite->sprite);
    free(player->kn_sh_3__sprite);
    sfClock_destroy(player->clock->clock);
    free(player->clock);
    free(player);
}
