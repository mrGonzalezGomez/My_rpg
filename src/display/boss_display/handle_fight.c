/*
** EPITECH PROJECT, 2023
** GAME-RPG
** File description:
** handle_fight.c
*/

#include "my_rpg.h"

void draw_buttons_and_texts(rpg_t *game)
{
    sfRenderWindow_drawSprite(game->window_data->window,
        game->boss->attack_button->sprite, NULL);
    sfRenderWindow_drawSprite(game->window_data->window,
        game->boss->defend_button->sprite, NULL);
    sfRenderWindow_drawSprite(game->window_data->window,
        game->boss->heal_button->sprite, NULL);
    sfRenderWindow_drawSprite(game->window_data->window,
        game->boss->run_button->sprite, NULL);
    sfRenderWindow_drawText(game->window_data->window,
        game->boss->attack_button->text, NULL);
    sfRenderWindow_drawText(game->window_data->window,
        game->boss->defend_button->text, NULL);
    sfRenderWindow_drawText(game->window_data->window,
        game->boss->heal_button->text, NULL);
    sfRenderWindow_drawText(game->window_data->window,
        game->boss->run_button->text, NULL);
}

bool is_button_pressed(sfVector2i mouse_pos, int x1, int y1, int x2, int y2)
{
    return mouse_pos.x >= x1 && mouse_pos.x <= x2
        && mouse_pos.y >= y1 && mouse_pos.y <= y2;
}

static void handle_input_bis(sfVector2i mouse_pos, rpg_t *game, int *player_action,
    bool *action_chosen)
{
    if (is_button_pressed(mouse_pos, 650, 70, 750, game->boss->pos.y + 170)) {
        *player_action = 1;
        *action_chosen = true;
    }
    if (is_button_pressed(mouse_pos, 835, 85, 935, 185)) {
        *player_action = 2;
        *action_chosen = true;
    }
    if (is_button_pressed(mouse_pos, 1040, 75, 1140, 175)) {
        *player_action = 3;
        *action_chosen = true;
    }
    if (is_button_pressed(mouse_pos, 1245, 75, 1345, 175)) {
        *player_action = 4;
        *action_chosen = true;
    }
}

void handle_mouse_input(rpg_t *game, int *player_action,
    bool *action_chosen, bool *mouse_pressed)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(game->window_data->window);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (!(*mouse_pressed)) {
            *mouse_pressed = true;
            handle_input_bis(mouse_pos, game, player_action, action_chosen);
        }
    } else
        *mouse_pressed = false;
}

void execute_player_action(rpg_t *game, int player_action)
{
    switch (player_action) {
        case 1:
            game->boss->player_life += 20;
            break;
        case 2:
            game->boss->player_life += 1;
            game->boss->defend_started_pl = true;
            break;
        case 3:
            game->boss->boss_life -= 10;
            game->boss->hit_started = true;
            game->boss->attack_started_pl = true;
            break;
        case 4:
            if (rand() % 2 == 0) {
                game->player->pos = (sfVector2f){4000, 4000};
                game->in_boss = false;
            }
            break;
    }
}

static void execute_boss_action(rpg_t *game)
{
    int boss_action = rand() % 2;

    if (boss_action == 0) {
        game->boss->player_life -= 15;
        game->boss->attack_started = true;
        game->boss->defend_started_pl = true;
    } else
        game->boss->boss_life += 5;
}

void handle_buttons_and_text(rpg_t *game)
{
    static bool player_turn = true;
    static bool action_chosen = false;
    static int player_action = 0;
    static bool mouse_pressed = false;

    if (player_turn || (player_turn && (game->boss->attack->animation_finished
        || game->boss->hurt->animation_finished))) {
        if (!action_chosen) {
            draw_buttons_and_texts(game);
            handle_mouse_input(game,
                &player_action, &action_chosen, &mouse_pressed);
        } else {
            execute_player_action(game, player_action);
            action_chosen = false;
            player_turn = false;
        }
    } else if (!player_turn) {
        execute_boss_action(game);
        player_turn = true;
    }
    life_bar_animation(game->boss, game);
    life_bar_animation_pl(game->boss, game);
}
