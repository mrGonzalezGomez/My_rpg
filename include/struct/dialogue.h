/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** structure
*/

#pragma once

#include "csfml_lib.h"
#include "utils.h"

typedef struct dialogue_s {
    bool activ;

    bool txt_is_hover;
    int txt_id;
    int letter_id;
    int nb_text;
    char *tmp;
    char **text;
    sfText *text_obj;
    sfFont *font;
    sfTexture *animation_texture;
    sfSprite *animation_sprite;
    sfIntRect animation_rect;
    sfVector2f animation_pos;
    sfClock *clock;
    sfClock *clock_letter;
    struct dialogue_s *next;
} dialogue_t;
