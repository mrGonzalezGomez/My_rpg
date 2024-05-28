/*
** EPITECH PROJECT, 2024
** GAME-RPG [WSL: Ubuntu-22.04]
** File description:
** player
*/

#include "my_rpg.h"

void display_save_buttons(rpg_t *game, menu_t *menu, save_menu_t *save_menu)
{
    save_menu = save_menu;
    sfRenderWindow_drawSprite(game->window_data->window,
        menu->main_menu->background, NULL);
    sfRenderWindow_drawSprite(game->window_data->window,
        menu->save_menu->buttons[0], NULL);
    sfRenderWindow_drawSprite(game->window_data->window,
        menu->save_menu->buttons[1], NULL);
    sfRenderWindow_drawSprite(game->window_data->window,
        menu->save_menu->buttons[2], NULL);
    sfRenderWindow_drawText(game->window_data->window,
        menu->save_menu->txt[0], NULL);
    sfRenderWindow_drawText(game->window_data->window,
        menu->save_menu->txt[1], NULL);
    sfRenderWindow_drawText(game->window_data->window,
        menu->save_menu->txt[2], NULL);
    sfRenderWindow_drawText(game->window_data->window,
        menu->save_menu->txt_title, NULL);
}
