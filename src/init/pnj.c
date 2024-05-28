/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** init
*/

#include "my_rpg.h"

void init_pnjs(pnj_t *pnj)
{
    pnj->texture = sfTexture_createFromFile(PNJ_SPRITE_PATH, NULL);
    pnj->sprite = sfSprite_create();
    pnj->rect = (sfIntRect){0, 75 * 5, 76, 70};
    pnj->pos = (sfVector2f){800, 531};
    sfSprite_setTexture(pnj->sprite, pnj->texture, sfTrue);
    sfSprite_setTextureRect(pnj->sprite, pnj->rect);
    sfSprite_setPosition(pnj->sprite, pnj->pos);
}

void init_king(pnj_t *king)
{
    king->texture = sfTexture_createFromFile(KING_SPRITE_PATH, NULL);
    king->sprite = sfSprite_create();
    king->rect = (sfIntRect){0, 75 * 5, 76, 70};
    king->pos = (sfVector2f){5050, 5333};
    sfSprite_setTexture(king->sprite, king->texture, sfTrue);
    sfSprite_setTextureRect(king->sprite, king->rect);
    sfSprite_setPosition(king->sprite, king->pos);
}
