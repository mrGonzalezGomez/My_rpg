/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** manager
*/

#include "my_rpg.h"

static void click_menu_button(void (*func)(rpg_t *, bool), rpg_t *game, int id,
    int up)
{
    if (up == 1)
        sfSprite_setTexture(
            game->menu->settings_menu->compenant[id]->add_button,
            game->menu->settings_menu->button_add_click_texture, sfTrue);
    else
        sfSprite_setTexture(
            game->menu->settings_menu->compenant[id]->sub_button,
            game->menu->settings_menu->button_sub_click_texture, sfTrue);
    func(game, true);
    game->menu->settings_menu->clock = sfClock_create();
}

void change_video_mode(rpg_t *game, int id)
{
    sfVideoMode mode = {1920, 1080, 32};

    if (id == 0 && !game->window_data->fullscreen) {
        sfRenderWindow_close(game->window_data->window);
        game->window_data->fullscreen = true;
        game->window_data->window =
            sfRenderWindow_create(mode, "Valkyria", sfFullscreen, NULL);
        game->collision = false;
    } else if (game->window_data->fullscreen) {
        sfRenderWindow_close(game->window_data->window);
        game->window_data->fullscreen = false;
        game->window_data->window =
            sfRenderWindow_create(mode, "Valkyria", sfClose | sfResize, NULL);
    }
}

static void manage_click_settings3(sfVector2f mouse_pos, rpg_t *game)
{
    sfFloatRect video_mode =
        sfSprite_getGlobalBounds(game->menu->settings_menu->video_mode[0]);

    if (sfFloatRect_contains(&video_mode, mouse_pos.x, mouse_pos.y))
        return change_video_mode(game, 0);
    video_mode =
        sfSprite_getGlobalBounds(game->menu->settings_menu->video_mode[1]);
    if (sfFloatRect_contains(&video_mode, mouse_pos.x, mouse_pos.y))
        return change_video_mode(game, 1);
}

static void manage_click_settings2(sfVector2f mouse_pos, rpg_t *game,
    sfFloatRect *compenant)
{
    if (sfFloatRect_contains(&compenant[4], mouse_pos.x, mouse_pos.y))
        return click_menu_button((void (*)(rpg_t *, bool))up_volume_effect,
            game, 2, 1);
    if (sfFloatRect_contains(&compenant[5], mouse_pos.x, mouse_pos.y))
        return click_menu_button((void (*)(rpg_t *, bool))down_volume_effect,
            game, 2, 0);
    manage_click_settings3(mouse_pos, game);
}

void manage_click_settings(sfVector2f mouse_pos, rpg_t *game)
{
    sfFloatRect back_button =
        sfSprite_getGlobalBounds(game->menu->settings_menu->back_button);
    sfFloatRect *compenant = get_compenant(game);

    if (sfFloatRect_contains(&back_button, mouse_pos.x, mouse_pos.y))
        game->menu->setting_open = false;
    if (sfFloatRect_contains(&compenant[0], mouse_pos.x, mouse_pos.y))
        return click_menu_button
            ((void (*)(rpg_t *, bool))up_volume_principal, game, 0, 1);
    if (sfFloatRect_contains(&compenant[1], mouse_pos.x, mouse_pos.y))
        return click_menu_button
            ((void (*)(rpg_t *, bool))down_volume_principal, game, 0, 0);
    if (sfFloatRect_contains(&compenant[2], mouse_pos.x, mouse_pos.y))
        return click_menu_button
            ((void (*)(rpg_t *, bool))up_volume_music, game, 1, 1);
    if (sfFloatRect_contains(&compenant[3], mouse_pos.x, mouse_pos.y))
        return click_menu_button
            ((void (*)(rpg_t *, bool))down_volume_music, game, 1, 0);
    manage_click_settings2(mouse_pos, game, compenant);
}

static void check_action_click(rpg_t *game, int i)
{
    if (i == 0) {
        save_data(game, game->save);
        sfRenderWindow_close(game->window_data->window);
        return;
    }
    if (i == 1) {
        save_data(game, game->save);
        game->escape_menu->is_open = false;
        return;
    }
    if (i == 2)
        game->escape_menu->is_open = false;
}

void manage_click_menu_escape(rpg_t *game)
{
    sfVector2i pixelPos =
        sfMouse_getPositionRenderWindow(game->window_data->window);
    sfVector2f mouse_pos =
        sfRenderWindow_mapPixelToCoords(game->window_data->window, pixelPos,
            sfRenderWindow_getView(game->window_data->window));
    sfFloatRect bounds;

    for (int i = 0; i < 3; i++) {
        bounds = sfSprite_getGlobalBounds(game->escape_menu->buttons[i]);
        if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y))
            check_action_click(game, i);
    }
}
