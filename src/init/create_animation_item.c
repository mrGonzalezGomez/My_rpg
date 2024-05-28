/*
** EPITECH PROJECT, 2024
** GAME-RPG [WSL: Ubuntu-22.04]
** File description:
** interaction
*/

#include "my_rpg.h"

char *get_description_item(char *name)
{
    if (strcmp(name, "Sword") == 0)
        return ("A sword to kill enemies");
    return "\0";
}

void create_animation_item(rpg_t *game, char *name)
{
    items_anim_t *anim = game->inventory->items_anim;
    int path_size = snprintf(NULL, 0, "assets/inventory/%s.png", name) + 1;
    char *path_sprite = malloc(path_size);

    snprintf(path_sprite, path_size, "assets/inventory/%s.png", name);
    anim->is_anim = true;
    anim->texture = sfTexture_createFromFile(path_sprite, NULL);
    sfSprite_setTexture(anim->sprite, anim->texture, sfTrue);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){55, 75});
    sfSprite_setScale(anim->sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setOrigin(anim->sprite, (sfVector2f){55, 75});
    set_string_to_text(anim->item_name, name);
    set_string_to_text(anim->item_descr, get_description_item(name));
    sfClock_restart(anim->clock);
    free(path_sprite);
}
