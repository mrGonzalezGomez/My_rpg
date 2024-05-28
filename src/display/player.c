/*
** EPITECH PROJECT, 2024
** GAME-RPG [WSL: Ubuntu-22.04]
** File description:
** player
*/

#include "my_rpg.h"

void move_sprite(player_sprites_t *sprite, int height, int width, int skip_md)
{
    static int last_height = -1;
    static int last_width = -1;

    if (last_height != height || last_width != width) {
        sprite->rect.left = 76.4 * width;
        sprite->rect.top = 76.4 * height;
        sfSprite_setTextureRect(sprite->sprite, sprite->rect);
        last_height = height;
        last_width = width;
        return;
    }
    if (skip_md == 1)
        sprite->rect.left += 76.4 * 2;
    else
        sprite->rect.left += 76.4;
    if (sprite->rect.left > 76.4 * (width + 2))
        sprite->rect.left = 76.4 * width;
    sprite->rect.top = 76.4 * height;
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
}

void display_player(rpg_t *game, player_sprites_t *sprite)
{
    sfRenderWindow_drawSprite(game->window_data->window, sprite->sprite, NULL);
    sfSprite_setPosition(sprite->sprite, game->player->pos);
    if (game->player->move != NONE &&
        sfTime_asSeconds(sfClock_getElapsedTime(game->player->clock->clock))
        > game->player->clock_speed_spite) {
        move_player_sprite(game->player->move, sprite, game->player);
        sfClock_restart(game->player->clock->clock);
    }
}
