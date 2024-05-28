/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** manager
*/

#include "my_rpg.h"

static void reset_texture_button(rpg_t *game, int i)
{
    main_menu_t *menu = game->menu->main_menu;

    if (sfSprite_getTexture(menu->spt_mid_button[i]) != menu->texture) {
        sfSprite_setTexture(menu->spt_mid_button[i], menu->texture, sfTrue);
        sfText_setColor(menu->txt_mid_button[i], sfWhite);
    }
}

void manage_hover_button_main_menu(sfVector2f mouse_pos, rpg_t *game)
{
    sfFloatRect bounds;

    for (int i = 0; i < 3; i++) {
        bounds =
            sfSprite_getGlobalBounds(game->menu->main_menu->spt_mid_button[i]);
        if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
            sfSprite_setTexture(game->menu->main_menu->spt_mid_button[i],
                game->menu->main_menu->texture_hover, sfTrue);
            sfText_setColor(game->menu->main_menu->txt_mid_button[i], sfBlack);
        } else
            reset_texture_button(game, i);
    }
}

static void reset_texture_back_button(rpg_t *game)
{
    settings_menu_t *menu = game->menu->settings_menu;

    if (sfSprite_getTexture(menu->back_button) != menu->button_texture) {
        sfSprite_setTexture(menu->back_button, menu->button_texture, sfTrue);
        sfText_setColor(menu->txt_back_button, sfWhite);
    }
}

static void reset_texture_video_setting_button(rpg_t *game, int i)
{
    settings_menu_t *menu = game->menu->settings_menu;

    if (sfSprite_getTexture(menu->video_mode[i]) != menu->button_texture) {
        sfSprite_setTexture(menu->video_mode[i], menu->button_texture, sfTrue);
        sfText_setColor(menu->txt_video_mode[i], sfWhite);
    }
}

void manage_hover_button_setting(sfVector2f mouse_pos, rpg_t *game)
{
    sfFloatRect bounds =
        sfSprite_getGlobalBounds(game->menu->settings_menu->back_button);

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
        sfSprite_setTexture(game->menu->settings_menu->back_button,
            game->menu->settings_menu->button_hover_texture, sfTrue);
        sfText_setColor(game->menu->settings_menu->txt_back_button, sfBlack);
    } else
        reset_texture_back_button(game);
    for (int i = 0; i < 2; i++) {
        bounds = sfSprite_getGlobalBounds(
            game->menu->settings_menu->video_mode[i]);
        if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
            sfSprite_setTexture(game->menu->settings_menu->video_mode[i],
                game->menu->settings_menu->button_hover_texture, sfTrue);
            sfText_setColor(game->menu->settings_menu->txt_video_mode[i],
                sfBlack);
        } else
            reset_texture_video_setting_button(game, i);
    }
}

static void reset_texture_button_save_menu(rpg_t *game, int i)
{
    save_menu_t *menu = game->menu->save_menu;

    if (sfSprite_getTexture(menu->buttons[i]) != menu->texture) {
        sfSprite_setTexture(menu->buttons[i], menu->texture, sfTrue);
        sfText_setColor(menu->txt[i], sfWhite);
    }
}

void manage_hover_button_save_menu(sfVector2f mouse_pos, rpg_t *game)
{
    sfFloatRect bounds;

    for (int i = 0; i < 3; i++) {
        bounds = sfSprite_getGlobalBounds(game->menu->save_menu->buttons[i]);
        if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
            sfSprite_setTexture(game->menu->save_menu->buttons[i],
                game->menu->save_menu->hover, sfTrue);
            sfText_setColor(game->menu->save_menu->txt[i], sfBlack);
        } else
            reset_texture_button_save_menu(game, i);
    }
}

void manage_hover_button(rpg_t *game)
{
    sfVector2i pixelPos =
        sfMouse_getPositionRenderWindow(game->window_data->window);
    sfVector2f mouse_pos =
        sfRenderWindow_mapPixelToCoords(game->window_data->window, pixelPos,
            sfRenderWindow_getView(game->window_data->window));

    if (game->menu->setting_open == true)
        return manage_hover_button_setting(mouse_pos, game);
    else if (game->in_save == false)
        return manage_hover_button_main_menu(mouse_pos, game);
    else
        return manage_hover_button_save_menu(mouse_pos, game);
}

static void reset_hover_button_escape(rpg_t *game, int i)
{
    escape_menu_t *menu = game->escape_menu;

    if (sfSprite_getTexture(menu->buttons[i]) != menu->texture) {
        sfText_setColor(game->escape_menu->txt[i], sfWhite);
        sfSprite_setTexture(menu->buttons[i], menu->texture, sfTrue);
    }
}

void manage_hover_button_escape(rpg_t *game)
{
    sfVector2i pixelPos =
        sfMouse_getPositionRenderWindow(game->window_data->window);
    sfVector2f mouse_pos =
        sfRenderWindow_mapPixelToCoords(game->window_data->window, pixelPos,
            sfRenderWindow_getView(game->window_data->window));
    sfFloatRect bounds;

    for (int i = 0; i < 3; i++) {
        bounds =
            sfSprite_getGlobalBounds(game->escape_menu->buttons[i]);
        if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
            sfSprite_setTexture(game->escape_menu->buttons[i],
                game->escape_menu->texture_hover, sfTrue);
            sfText_setColor(game->escape_menu->txt[i], sfBlack);
        } else
            reset_hover_button_escape(game, i);
    }
}
