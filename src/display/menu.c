/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** manager
*/

#include "my_rpg.h"

void display_main_menu(rpg_t *game, menu_t *menu)
{
    sfRenderWindow_drawSprite(game->window_data->window,
        menu->main_menu->background, NULL);
    sfRenderWindow_drawSprite(game->window_data->window,
        menu->main_menu->spt_mid_button[0], NULL);
    sfRenderWindow_drawSprite(game->window_data->window,
        menu->main_menu->spt_mid_button[1], NULL);
    sfRenderWindow_drawSprite(game->window_data->window,
        menu->main_menu->spt_mid_button[2], NULL);
    sfRenderWindow_drawText(game->window_data->window,
        menu->main_menu->txt_title, NULL);
    sfRenderWindow_drawText(game->window_data->window,
        menu->main_menu->txt_mid_button[0], NULL);
    sfRenderWindow_drawText(game->window_data->window,
        menu->main_menu->txt_mid_button[1], NULL);
    sfRenderWindow_drawText(game->window_data->window,
        menu->main_menu->txt_mid_button[2], NULL);
}

static void reset_all_button_click(menu_t *menu)
{
    settings_menu_t *st_menu = menu->settings_menu;

    for (int i = 0; i < 3; i++) {
        if (sfSprite_getTexture(st_menu->compenant[i]->add_button)
            != st_menu->button_add_texture)
            sfSprite_setTexture(st_menu->compenant[i]->add_button,
                st_menu->button_add_texture, sfTrue);
        if (sfSprite_getTexture(st_menu->compenant[i]->sub_button)
            != st_menu->button_sub_texture)
            sfSprite_setTexture(st_menu->compenant[i]->sub_button,
                st_menu->button_sub_texture, sfTrue);
    }
}

static void manage_reset_button_click(menu_t *menu)
{
    if (menu->settings_menu->clock &&
        sfClock_getElapsedTime(menu->settings_menu->clock).microseconds
            > 100000) {
        reset_all_button_click(menu);
        sfClock_destroy(menu->settings_menu->clock);
        menu->settings_menu->clock = NULL;
    }
}

void display_button_part_1(rpg_t *game, menu_t *menu)
{
    for (int i = 0; i < 2; i++) {
        sfRenderWindow_drawSprite(game->window_data->window,
            menu->settings_menu->video_mode[i], NULL);
        sfRenderWindow_drawText(game->window_data->window,
            menu->settings_menu->txt_video_mode[i], NULL);
    }
}

void display_button_part_2(rpg_t *game, menu_t *menu)
{
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawSprite(game->window_data->window,
            menu->settings_menu->compenant[i]->add_button, NULL);
        sfRenderWindow_drawSprite(game->window_data->window,
            menu->settings_menu->compenant[i]->middle_button, NULL);
        sfRenderWindow_drawSprite(game->window_data->window,
            menu->settings_menu->compenant[i]->sub_button, NULL);
        sfRenderWindow_drawText(game->window_data->window,
            menu->settings_menu->compenant[i]->txt_compenant, NULL);
    }
    manage_reset_button_click(menu);
}

void display_settings_menu(rpg_t *game, menu_t *menu)
{
    sfRenderWindow_drawSprite(game->window_data->window,
        menu->main_menu->background, NULL);
    sfRenderWindow_drawSprite(game->window_data->window,
        menu->settings_menu->back_button, NULL);
    sfRenderWindow_drawText(game->window_data->window,
        menu->settings_menu->txt_back_button, NULL);
    display_button_part_1(game, menu);
    display_button_part_2(game, menu);
}

void display_menu_escape(rpg_t *game, escape_menu_t *menu)
{
    sfVector2f pos = {game->map->map_info->view_x,
        game->map->map_info->view_y};

    for (int i = 0; i < 3; i++) {
        sfSprite_setPosition(menu->buttons[i], (sfVector2f){pos.x - 150,
            pos.y + 100 - (i * 100)});
        sfRenderWindow_drawSprite(game->window_data->window,
            menu->buttons[i], NULL);
        sfRenderWindow_drawText(game->window_data->window,
            menu->txt[i], NULL);
    }
    sfText_setPosition(menu->txt[2], (sfVector2f){pos.x - 83,
        pos.y + 100 - (2 * 100)});
    sfText_setPosition(menu->txt[1], (sfVector2f){pos.x - 50,
        pos.y + 100 - (1 * 100)});
    sfText_setPosition(menu->txt[0], (sfVector2f){pos.x - 50,
        pos.y + 100 - (0 * 100)});
}
