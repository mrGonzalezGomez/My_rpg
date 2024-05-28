/*
** EPITECH PROJECT, 2024
** GAME-RPG [WSL: Ubuntu-22.04]
** File description:
** inventory
*/

#include "my_rpg.h"

void create_item(items_t *item, char *name, int data[5][4], int id)
{
    item->name = name;
    item->id = data[id][0];
    item->damage = data[id][1];
    item->armor = data[id][2];
    item->heatlh = data[id][3];
    item->next = malloc(sizeof(items_t));
}

void init_items(items_t *items)
{
    int data[5][4] = {
        {1, 5, 0, 0},
        {2, 0, 5, 0},
        {3, 0, 0, 10},
        {4, 20, 0, 0},
        {5, 0, 20, 0}
    };

    create_item(items, "Sword", data, 0);
    create_item(items->next, "Shield", data, 1);
    create_item(items->next->next, "Potion", data, 2);
    create_item(items->next->next->next, "Sword_2", data, 3);
    create_item(items->next->next->next->next, "Shield_2", data, 4);
    items->next->next->next->next->next = NULL;
}

static void malloc_and_fill_inventory(inventory_t *inventory)
{
    inventory->items = malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++)
        inventory->items[i] = malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            inventory->items[i][j] = 0;
}

void init_inventory(inventory_t *inventory)
{
    inventory->sprite = sfSprite_create();
    inventory->texture = sfTexture_createFromFile(PATH_INVENTORY, NULL);
    inventory->scale = (sfVector2f){5, 5};
    sfSprite_setScale(inventory->sprite, inventory->scale);
    sfSprite_setTexture(inventory->sprite,
        inventory->texture, sfTrue);
    inventory->is_open = false;
    malloc_and_fill_inventory(inventory);
}

void init_items_animation(items_anim_t *items_anim)
{
    items_anim->is_anim = false;
    items_anim->alpha = 255;
    items_anim->clock = sfClock_create();
    items_anim->texture = NULL;
    items_anim->sprite = sfSprite_create();
    items_anim->back_texture = sfTexture_createFromFile(PATH_POPUP, NULL);
    items_anim->back_sprite = sfSprite_create();
    sfSprite_setOrigin(items_anim->back_sprite, (sfVector2f){175, 97.5});
    sfSprite_setTexture(items_anim->back_sprite,
        items_anim->back_texture, sfTrue);
    sfSprite_setScale(items_anim->back_sprite, (sfVector2f){1.5, 1.5});
    items_anim->font = sfFont_createFromFile(FONT_PATH);
    items_anim->item_name = sfText_create();
    items_anim->item_descr = sfText_create();
    sfText_setFont(items_anim->item_name, items_anim->font);
    sfText_setFont(items_anim->item_descr, items_anim->font);
    sfText_setCharacterSize(items_anim->item_name, 50);
    sfText_setCharacterSize(items_anim->item_descr, 20);
    sfText_setColor(items_anim->item_name, sfBlack);
    sfText_setColor(items_anim->item_descr, sfBlack);
}
