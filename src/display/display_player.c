/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** display_player
*/

#include "my_rpg.h"


void manage_display_player(rpg_t *game)
{
    if (game->player->type == KN_SH_1)
        display_player(game, game->player->kn_sh_1__sprite);
    if (game->player->type == KN_SH_2)
        display_player(game, game->player->kn_sh_2__sprite);
    if (game->player->type == KN_SH_3)
        display_player(game, game->player->kn_sh_3__sprite);
    if (game->player->type == KN_BTT)
        display_player(game, game->player->kn_btt_sprite);
}
