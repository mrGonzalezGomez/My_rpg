/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** death
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct death_s {
    sfRectangleShape *darken;
    sfText *text;
    sfFont *font;
    sfMusic *music;
} death_t;
