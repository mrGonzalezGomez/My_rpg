/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** loading_screen
*/

#include "my_rpg.h"

void display_loading_screen(menu_t *menu, rpg_t *game)
{
    sfRenderWindow_clear(game->window_data->window, sfBlack);
    sfRenderWindow_drawRectangleShape(game->window_data->window,
        menu->loading_menu->background, NULL);
    sfRenderWindow_drawText(game->window_data->window,
        menu->loading_menu->txt_title, NULL);
    sfRenderWindow_drawText(game->window_data->window,
        menu->loading_menu->txt_loading, NULL);
    sfRenderWindow_display(game->window_data->window);
}

static void set_parameter_loading_screen(menu_t *menu)
{
    sfRectangleShape_setSize(menu->loading_menu->background,
        (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(menu->loading_menu->background, sfBlack);
    set_string_to_text(menu->loading_menu->txt_title, LOADING_TITLE);
    set_string_to_text(menu->loading_menu->txt_loading, "0%");
    sfText_setFont(menu->loading_menu->txt_title, menu->main_menu->font);
    sfText_setFont(menu->loading_menu->txt_loading, menu->main_menu->font);
    sfText_setCharacterSize(menu->loading_menu->txt_title, LOADING_TXT_SIZE);
    sfText_setCharacterSize(menu->loading_menu->txt_loading, LOADING_TXT_SIZE);
    sfText_setColor(menu->loading_menu->txt_title, sfWhite);
    sfText_setColor(menu->loading_menu->txt_loading, sfWhite);
    sfText_setPosition(menu->loading_menu->txt_title,
        (sfVector2f){LOADING_TITLE_POS_X, LOADING_TITLE_POS_Y});
    sfText_setPosition(menu->loading_menu->txt_loading,
        (sfVector2f){LOADING_TXT_POS_X, LOADING_TXT_POS_Y});
}

void loadin_screen(menu_t *menu, rpg_t *game)
{
    menu->loading_menu = malloc(sizeof(loading_menu_t));
    menu->loading_menu->txt_title = sfText_create();
    menu->loading_menu->txt_loading = sfText_create();
    menu->loading_menu->background = sfRectangleShape_create();
    set_parameter_loading_screen(menu);
    display_loading_screen(menu, game);
}
