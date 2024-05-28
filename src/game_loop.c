/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** game_loop
*/

#include "my_rpg.h"

void game_loop(rpg_t *game)
{
    while (sfRenderWindow_isOpen(game->window_data->window)) {
        manager_event(game);
        manager_display(game);
        sfRenderWindow_display(game->window_data->window);
        sfRenderWindow_clear(game->window_data->window, sfWhite);
    }
}
