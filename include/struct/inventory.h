/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** inventory
*/

#pragma once

#include "csfml_lib.h"
#include "utils.h"

typedef struct items_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f *pos;
    char *name;
    int id;
    int damage;
    int armor;
    int heatlh;
    struct items_s *next;
} items_t;

typedef struct items_anim_s {
    bool is_anim;
    int alpha;
    sfClock *clock;

    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *back_texture;
    sfSprite *back_sprite;
    sfText *item_name;
    sfText *item_descr;
    sfFont *font;
} items_anim_t;


typedef struct inventory_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f *pos;
    bool is_open;
    int **items;
    items_anim_t *items_anim;
} inventory_t;
