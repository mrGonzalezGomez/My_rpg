/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** destroy
*/

#include "my_rpg.h"

void destroy_window_data(windows_t *window_data)
{
    sfRenderWindow_destroy(window_data->window);
    sfClock_destroy(window_data->clock->clock);
    free(window_data->clock);
    free(window_data);
}

void destroy(rpg_t *game)
{
    if (game->in_game == true)
        save_data(game, game->save);
    destroy_window_data(game->window_data);
    if (game->menu != NULL)
        destroy_menu(game->menu);
    if (game->player != NULL)
        destroy_player(game->player);
    if (game->map != NULL)
        destroy_map(game->map);
    if (game->boss != NULL)
        destroy_boss(game->boss, game);
    if (game->pnj != NULL)
        destroy_pnjs(game->pnj);
}
