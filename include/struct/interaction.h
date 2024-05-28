/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** csfml_lib
*/

#pragma once

#include "csfml_lib.h"
#include "utils.h"

typedef struct interaction_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f *cords_array;
    bool *is_active;
    int nb_interact;
    bool is_interacting;
} interaction_t;
