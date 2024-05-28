/*
** EPITECH PROJECT, 2024
** GAME-RPG [WSL: Ubuntu-22.04]
** File description:
** interaction
*/

#include "my_rpg.h"

static void create_interact_interaction(interaction_t *interact)
{
    interact->sprite = sfSprite_create();
    interact->texture = sfTexture_createFromFile(PATH_INTERACTION, NULL);
    interact->scale = (sfVector2f){0.07, 0.07};
    sfSprite_setScale(interact->sprite, interact->scale);
    sfSprite_setTexture(interact->sprite, interact->texture, sfTrue);
}

static void fill_vector_array(interaction_t *interact)
{
    interact->cords_array = malloc(sizeof(sfVector2i) *
        interact->nb_interact);
    interact->KING = (sfVector2f){5088, 5333};
    interact->ARCHER = (sfVector2f){816, 531};
    interact->SWORD = (sfVector2f){6842, 7470};
    interact->NOTE = (sfVector2f){4560, 3770};
    interact->BOSS = (sfVector2f){680, 8754};
    interact->SHIELD = (sfVector2f){5088, 7544};
    interact->BLACKSMITH = (sfVector2f){5174, 2105};
    interact->is_active = malloc(sizeof(bool) * interact->nb_interact);
    for (int i = 0; i < interact->nb_interact; i++)
        interact->is_active[i] = false;
}

void init_interaction(interaction_t *interact)
{
    interact->is_interacting = false;
    interact->nb_interact = 7;
    create_interact_interaction(interact);
    fill_vector_array(interact);
}
