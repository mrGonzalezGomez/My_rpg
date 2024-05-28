/*
** EPITECH PROJECT, 2023
** GAME-RPG
** File description:
** manage_boss.c
*/

#include "my_rpg.h"

void manage_boss(rpg_t *game)
{
    if (sqrt(pow(game->player->pos.x - 680, 2) +
        (pow(game->player->pos.y - 8754, 2))) < 100) {
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            game->player->pos = (sfVector2f){1460, 8522};
            init_speech(game);
            game->in_boss = true;
        }
    }
}

void handle_boss_death(rpg_t *game)
{
    update_boss_animation(game->boss->death);
    sfRenderWindow_drawSprite(game->window_data->window,
        game->boss->death->sprite, NULL);
    if (game->boss->death->animation_finished) {
        sfSleep(sfSeconds(1));
        sfMusic_stop(game->boss->music);
        game->player->pos = (sfVector2f){680, 8754};
        game->in_boss = false;
    }
}

void handle_player_death(rpg_t *game)
{
    update_boss_animation_pl(game->boss->death_pl);
    sfRenderWindow_drawSprite(game->window_data->window,
        game->boss->death_pl->sprite, NULL);
    if (game->boss->death_pl->animation_finished) {
        sfSleep(sfSeconds(1));
        game->player->pos = (sfVector2f){4000, 4000};
        sfMusic_stop(game->boss->music);
        game->in_boss = false;
        game->player->is_alive = false;
        handle_death(game, game->player);
    }
}

static void manage_boss_idle_and_attack(rpg_t *game)
{
    if (!game->boss->death_started &&
        !game->boss->hit_started && !game->boss->attack_started) {
        update_boss_animation(game->boss->idle);
        sfRenderWindow_drawSprite(game->window_data->window,
            game->boss->idle->sprite, NULL);
    }
    if (game->boss->attack_started) {
        update_boss_animation(game->boss->attack);
        sfRenderWindow_drawSprite(game->window_data->window,
            game->boss->attack->sprite, NULL);
        if (game->boss->attack->animation_finished)
            game->boss->attack_started = false;
    }
}

static void manage_boss_hit_and_death(rpg_t *game)
{
    if (game->boss->boss_life <= 0)
        game->boss->death_started = true;
    if (game->boss->hit_started) {
        update_boss_animation(game->boss->hurt);
        sfRenderWindow_drawSprite(game->window_data->window,
            game->boss->hurt->sprite, NULL);
        if (game->boss->hurt->animation_finished)
            game->boss->hit_started = false;
    }
    if (game->boss->death_started)
        handle_boss_death(game);
}

void manage_boss_sprite(rpg_t *game)
{
    manage_boss_idle_and_attack(game);
    manage_boss_hit_and_death(game);
}

static void manage_boss_idle_attack_defend(rpg_t *game)
{
    if (!game->boss->death_started_pl &&
        !game->boss->attack_started_pl && !game->boss->defend_started_pl) {
        update_boss_animation_pl(game->boss->idle_pl);
        sfRenderWindow_drawSprite(game->window_data->window,
            game->boss->idle_pl->sprite, NULL);
    }
    if (game->boss->attack_started_pl) {
        update_boss_animation_pl(game->boss->attack_pl);
        sfRenderWindow_drawSprite(game->window_data->window,
            game->boss->attack_pl->sprite, NULL);
        if (game->boss->attack_pl->animation_finished)
            game->boss->attack_started_pl = false;
    }
    if (game->boss->defend_started_pl) {
        update_boss_animation_pl(game->boss->protect);
        sfRenderWindow_drawSprite(game->window_data->window,
            game->boss->protect->sprite, NULL);
        if (game->boss->protect->animation_finished)
            game->boss->defend_started_pl = false;
    }
}

static void manage_player_death(rpg_t *game)
{
    if (game->boss->player_life <= 0)
        game->boss->death_started_pl = true;
    if (game->boss->death_started_pl)
        handle_player_death(game);
}

void manage_boss_pl_sprite(rpg_t *game)
{
    manage_boss_idle_attack_defend(game);
    manage_player_death(game);
}
