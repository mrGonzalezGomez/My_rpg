/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** player
*/

#pragma once

#include "csfml_lib.h"
#include "utils.h"
#include <stdbool.h>

enum player_sprite {
    KN_BTT,
    KN_SH_1,
    KN_SH_2,
    KN_SH_3
};

enum player_move {
    NONE,
    UP,
    UP_LEFT,
    UP_RIGHT,
    DOWN,
    DOWN_LEFT,
    DOWN_RIGHT,
    LEFT,
    RIGHT,
    SPEED_UP,
    SPEED_UP_LEFT,
    SPEED_UP_RIGHT,
    SPEED_DOWN,
    SPEED_DOWN_LEFT,
    SPEED_DOWN_RIGHT,
    SPEED_LEFT,
    SPEED_RIGHT
};

typedef struct player_sprites_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int width;
    int height;
    int skip_mid;
} player_sprites_t;

typedef struct player_s {
    enum player_sprite type;
    enum player_move move;
    player_sprites_t *kn_btt_sprite;
    player_sprites_t *kn_sh_1__sprite;
    player_sprites_t *kn_sh_2__sprite;
    player_sprites_t *kn_sh_3__sprite;
    clock_data_t *clock;
    float clock_speed_spite;
    sfVector2f pos;
    sfVector2f old_pos;
    int speed;
    bool is_alive;
} player_t;
