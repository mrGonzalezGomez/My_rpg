/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** manager
*/

#include "my_rpg.h"

void manage_display_pnjs(rpg_t *game)
{
    sfRenderWindow_drawSprite(game->window_data->window, game->pnj->sprite,
        NULL);
    sfRenderWindow_drawSprite(game->window_data->window, game->king->sprite,
        NULL);
}
