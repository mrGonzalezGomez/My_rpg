/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** manager
*/

#include "my_rpg.h"

void up_volume_principal(rpg_t *game, bool display_update)
{
    if (game->window_data->vol_principal < 1)
        game->window_data->vol_principal += 0.1;
    if (display_update)
        update_display_princiapl_volume(game);
}

void up_volume_music(rpg_t *game, bool display_update)
{
    if (game->window_data->vol_music < 1)
        game->window_data->vol_music += 0.1;
    if (display_update)
        update_display_music_volume(game);
}

void up_volume_effect(rpg_t *game, bool display_update)
{
    if (game->window_data->vol_effets < 1)
        game->window_data->vol_effets += 0.1;
    if (display_update)
        update_display_effect_volume(game);
}
