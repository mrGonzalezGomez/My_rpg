/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** destroy
*/

#include "my_rpg.h"

void destroy_pnjs(pnj_t *pnj)
{
    sfTexture_destroy(pnj->texture);
    sfSprite_destroy(pnj->sprite);
    free(pnj);
}
