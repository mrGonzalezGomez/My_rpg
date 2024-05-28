/*
** EPITECH PROJECT, 2023
** GAME-RPG
** File description:
** display_boss.c
*/

#include "my_rpg.h"

void set_texture(sfSprite *sprite, sfTexture *texture, int life)
{
    sfIntRect rect = {0, 0, 17, 17};

    if (life >= 25)
        rect = (sfIntRect){0, 0, 17, 17};
    if (life < 25 && life >= 20)
        rect = (sfIntRect){17, 0, 17, 17};
    if (life < 20 && life >= 15)
        rect = (sfIntRect){34, 0, 17, 17};
    if (life < 15 && life >= 10)
        rect = (sfIntRect){51, 0, 17, 17};
    if (life < 10 && life >= 5)
        rect = (sfIntRect){68, 0, 17, 17};
    if (life < 5 && life > 0)
    sfSprite_setPosition(sprite, (sfVector2f){-100, -100});
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
}

void life_bar_animation(boss_t *boss, rpg_t *game)
{
    (void)game;
    if (boss->boss_life >= 100)
        set_texture(boss->life_bar_sp[4],
            boss->life_bar_text, boss->boss_life - 100);
    if (boss->boss_life >= 75 && boss->boss_life < 100)
        set_texture(boss->life_bar_sp[3],
            boss->life_bar_text, boss->boss_life - 75);
    if (boss->boss_life >= 50 && boss->boss_life < 75)
        set_texture(boss->life_bar_sp[2],
            boss->life_bar_text, boss->boss_life - 50);
    if (boss->boss_life > 25 && boss->boss_life < 50)
        set_texture(boss->life_bar_sp[1],
            boss->life_bar_text, boss->boss_life - 25);
    if (boss->boss_life > 0 && boss->boss_life <= 25)
        set_texture(boss->life_bar_sp[0],
            boss->life_bar_text, boss->boss_life);
}

void life_bar_animation_pl(boss_t *boss, rpg_t *game)
{
    (void)game;
    if (boss->player_life >= 100)
        set_texture(boss->life_bar_sp_pl[4],
            boss->life_bar_text, boss->player_life - 100);
    if (boss->player_life >= 75 && boss->player_life < 100)
        set_texture(boss->life_bar_sp_pl[3],
            boss->life_bar_text, boss->player_life - 75);
    if (boss->player_life >= 50 && boss->player_life < 75)
        set_texture(boss->life_bar_sp_pl[2],
            boss->life_bar_text, boss->player_life - 50);
    if (boss->player_life > 25 && boss->player_life < 50)
        set_texture(boss->life_bar_sp_pl[1],
            boss->life_bar_text, boss->player_life - 25);
    if (boss->player_life > 0 && boss->player_life <= 25)
        set_texture(boss->life_bar_sp_pl[0],
            boss->life_bar_text, boss->player_life);
}

static void no_spaces(rpg_t *game)
{
    manage_boss_sprite(game);
    manage_boss_pl_sprite(game);
    handle_buttons_and_text(game);
}

void display_boss(rpg_t *game)
{
    sfRenderWindow_drawSprite(game->window_data->window,
        game->boss->back_sp, NULL);
    for (int i = 0; i < 5; i++) {
        sfSprite_setScale(game->boss->life_bar_sp[i], (sfVector2f){2, 2});
        sfSprite_setScale(game->boss->life_bar_sp_pl[i], (sfVector2f){2, 2});
        sfRenderWindow_drawSprite(game->window_data->window,
            game->boss->life_bar_sp[i], NULL);
        sfRenderWindow_drawSprite(game->window_data->window,
            game->boss->life_bar_sp_pl[i], NULL);
    }
    no_spaces(game);
}
