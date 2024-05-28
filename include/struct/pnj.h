/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** structure
*/

#pragma once

#include "csfml_lib.h"
#include "utils.h"

typedef struct pnj_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
} pnj_t;
