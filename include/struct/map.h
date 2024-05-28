/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** player
*/

#pragma once

#include <stdbool.h>
#include "csfml_lib.h"
#include "utils.h"

typedef struct map_sprites_s {
    sfTexture *texture;
    sfSprite *chunk[36];
    sfIntRect rect;
} map_sprites_t;

typedef struct parsing_s {
    int **coll_file;
} parsing_t;

typedef struct map_info_s {
    sfView *view;
    float view_x;
    float view_y;
    sfVector2u window_size;
    float map_width;
    float map_height;
    int chunks_to_display;
    int chunk_x;
    int chunk_y;
} map_info_t;

typedef struct map_s {
    map_sprites_t *map_sprites[13];
    parsing_t *parsing;
    map_info_t *map_info;
} map_t;
