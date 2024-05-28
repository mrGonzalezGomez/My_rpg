/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** manager
*/

#include "my_rpg.h"

static int set_player_move_direction_bis(rpg_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (sfKeyboard_isKeyPressed(sfKeyRight)) {
            game->player->move = DOWN_RIGHT;
            return 1;
        }
        if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
            game->player->move = DOWN_LEFT;
            return 1;
        }
        game->player->move = DOWN;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        game->player->move = RIGHT;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        game->player->move = LEFT;
    return 0;
}

static void set_player_move_direction(rpg_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (sfKeyboard_isKeyPressed(sfKeyRight)) {
            game->player->move = UP_RIGHT;
            return;
        }
        if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
            game->player->move = UP_LEFT;
            return;
        }
        game->player->move = UP;
    }
    if (set_player_move_direction_bis(game) == 1)
        return;
}

static void manage_mouvement(rpg_t *game)
{
    game->player->move = NONE;
    set_player_move_direction(game);
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        game->player->move += 8;
    if (game->player->move != NONE && game->escape_menu->is_open == false)
        update_position(game->player->move, game, game->player->speed);
}

int another_bis(rpg_t *game, sfFloatRect save_button,
    sfFloatRect save_button2, sfVector2i mouse_pos)
{
    sfFloatRect save_button3 =
        sfSprite_getGlobalBounds(game->menu->save_menu->buttons[2]);

    if (sfFloatRect_contains(&save_button, mouse_pos.x, mouse_pos.y)
        && game->in_save == true) {
        choose_save(game, 1);
        return 1;
        }
    if (sfFloatRect_contains(&save_button2, mouse_pos.x, mouse_pos.y)
        && game->in_save == true) {
        choose_save(game, 2);
        return 1;
        }
    if (sfFloatRect_contains(&save_button3, mouse_pos.x, mouse_pos.y)
        && game->in_save == true) {
        choose_save(game, 3);
        return 1;
        }
    return 0;
}

static int manage_click_menu_bis(rpg_t *game, sfVector2i mouse_pos)
{
    sfFloatRect save_button =
        sfSprite_getGlobalBounds(game->menu->save_menu->buttons[0]);
    sfFloatRect save_button2 =
        sfSprite_getGlobalBounds(game->menu->save_menu->buttons[1]);

    if (another_bis(game, save_button, save_button2, mouse_pos) == 1)
        return 1;
    return 0;
}

static void call_play(rpg_t *game, sfVector2f mouse_pos, sfFloatRect
    play_button)
{
    if (sfFloatRect_contains(&play_button, mouse_pos.x, mouse_pos.y))
        game->in_save = true;
}

static void call_settings(rpg_t *game, sfVector2f mouse_pos,
    sfFloatRect settings_button)
{
    if (sfFloatRect_contains(&settings_button, mouse_pos.x, mouse_pos.y))
        game->menu->setting_open = true;
}

void manage_click_menu(rpg_t *game)
{
    sfVector2i pixelPos =
        sfMouse_getPositionRenderWindow(game->window_data->window);
    sfVector2f mouse_pos =
        sfRenderWindow_mapPixelToCoords(game->window_data->window, pixelPos,
            sfRenderWindow_getView(game->window_data->window));
    sfFloatRect play_button =
        sfSprite_getGlobalBounds(game->menu->main_menu->spt_mid_button[0]);
    sfFloatRect quit_button =
        sfSprite_getGlobalBounds(game->menu->main_menu->spt_mid_button[1]);
    sfFloatRect settings_button =
        sfSprite_getGlobalBounds(game->menu->main_menu->spt_mid_button[2]);

    call_settings(game, mouse_pos, settings_button);
    if (game->menu->setting_open)
        return manage_click_settings(mouse_pos, game);
    call_play(game, mouse_pos, play_button);
    if (manage_click_menu_bis(game, pixelPos) == 1)
        return;
    if (!game->in_save &&
        sfFloatRect_contains(&quit_button, mouse_pos.x, mouse_pos.y))
        return sfRenderWindow_close(game->window_data->window);
}
    
static void manage_interaction(rpg_t *game) {
    float dx;
    float dy;
    float distance;

    for (int i = 0; i < game->interaction->nb_interact; i++) {
        dx = game->player->pos.x - game->interaction->cords_array[i].x + 40;
        dy = game->player->pos.y - game->interaction->cords_array[i].y + 30;
        distance = sqrt(dx * dx + dy * dy);
        if (distance <= 50) {
            game->interaction->is_active[i] = true;
            if (sfKeyboard_isKeyPressed(sfKeyE)) {
                game->interaction->is_interacting = true;
            } else
                game->interaction->is_interacting = false;
        } else {
            game->interaction->is_active[i] = false;
        }
    }
}

void manager_event(rpg_t *game)
{
    while (sfRenderWindow_pollEvent(game->window_data->window,
        &game->window_data->event)) {
        if (game->window_data->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window_data->window);
        if (game->in_game && game->window_data->event.type == sfEvtKeyPressed) {
            if (game->window_data->event.key.code == sfKeyEscape)
                game->escape_menu->is_open = !game->escape_menu->is_open;
        }
        if (game->window_data->event.type == sfEvtKeyPressed) {
            if (game->window_data->event.key.code == sfKeyO)
                game->player->pos = (sfVector2f){500, 8000};
        }
        if (game->window_data->event.type == sfEvtMouseButtonPressed)
            manage_click(game);
    }
    if (game->in_game) {
        manage_mouvement(game);
        manage_interaction(game);
        if (game->escape_menu->is_open)
            manage_hover_button_escape(game);
        progress_quests(game);
    } else
        manage_hover_button(game);
    if (game->in_game && !game->in_boss)
        manage_boss(game);
}
