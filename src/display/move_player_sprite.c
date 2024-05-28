/*
** EPITECH PROJECT, 2024
** GAME-RPG [WSL: Ubuntu-22.04]
** File description:
** player
*/

#include "my_rpg.h"

static int move_player_sprite_bis_1(player_sprites_t *sprite,
    enum player_move move)
{
    sprite->width = sprite->width;
    if (move == DOWN || move == LEFT || move == RIGHT || move == UP)
        sprite->width = 1;
    if (move == DOWN)
        sprite->height = 0;
    if (move == LEFT)
        sprite->height = 1;
    if (move == RIGHT)
        sprite->height = 2;
    if (move == UP)
        sprite->height = 3;
    if (sprite->height != -1) {
        move_sprite(sprite, sprite->height, 0, sprite->skip_mid);
        return 0;
    }
    return 1;
}

static int move_player_sprite_bis_2(player_sprites_t *sprite,
    enum player_move move)
{
    if (move == SPEED_DOWN || move == SPEED_LEFT
        || move == SPEED_RIGHT || move == SPEED_UP)
        sprite->width = 6;
    if (move == SPEED_LEFT || move == SPEED_RIGHT)
        sprite->skip_mid = 0;
    if (move == SPEED_DOWN)
        sprite->height = 0;
    if (move == SPEED_LEFT)
        sprite->height = 1;
    if (move == SPEED_RIGHT)
        sprite->height = 2;
    if (move == SPEED_UP)
        sprite->height = 3;
    if (sprite->height != -1) {
        move_sprite(sprite, sprite->height, sprite->width, sprite->skip_mid);
        return 0;
    }
    return 1;
}

static int move_player_sprite_bis_3(player_sprites_t *sprite,
    enum player_move move)
{
    if (move == DOWN_LEFT || move == DOWN_RIGHT
        || move == UP_LEFT || move == UP_RIGHT)
        sprite->width = 3;
    if (move == DOWN_LEFT)
        sprite->height = 0;
    if (move == DOWN_RIGHT)
        sprite->height = 1;
    if (move == UP_LEFT)
        sprite->height = 2;
    if (move == UP_RIGHT)
        sprite->height = 3;
    if (sprite->height != -1) {
        move_sprite(sprite, sprite->height, sprite->width, sprite->skip_mid);
        return 0;
    }
    return 1;
}

static int move_player_sprite_bis_4(player_sprites_t *sprite,
    enum player_move move)
{
    if (move == SPEED_DOWN_LEFT || move == SPEED_DOWN_RIGHT
        || move == SPEED_UP_LEFT || move == SPEED_UP_RIGHT)
        sprite->width = 9;
    if (move == SPEED_DOWN_LEFT)
        sprite->height = 0;
    if (move == SPEED_DOWN_RIGHT)
        sprite->height = 1;
    if (move == SPEED_UP_LEFT)
        sprite->height = 2;
    if (move == SPEED_UP_RIGHT)
        sprite->height = 3;
    if (sprite->height != -1) {
        move_sprite(sprite, sprite->height, sprite->width, sprite->skip_mid);
        return 0;
    }
    return 1;
}

void move_player_sprite(enum player_move move, player_sprites_t *sprite,
    player_t *player)
{
    sprite->height = -1;
    sprite->width = 1;
    sprite->skip_mid = 1;
    player->clock_speed_spite = 0.3;
    if (move_player_sprite_bis_1(sprite, move) == 0)
        return;
    if (move_player_sprite_bis_2(sprite, move) == 0)
        return;
    if (move_player_sprite_bis_3(sprite, move) == 0)
        return;
    if (move_player_sprite_bis_4(sprite, move) == 0)
        return;
}
