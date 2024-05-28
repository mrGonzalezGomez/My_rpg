/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** inventory
*/

#include "my_rpg.h"

static int get_id_by_name(rpg_t *game, char *name)
{
    items_t *tmp = game->items;

    while (tmp) {
        if (strcmp(tmp->name, name) == 0)
            return (tmp->id);
        tmp = tmp->next;
    }
    return (-1);
}

static sfVector2i get_empty_slot_2(inventory_t *inventory, int i)
{
    sfVector2i slot = {0, 0};

    for (int j = 0; j < 3; j++) {
        if (inventory->items[i][j] == 0) {
            slot.x = i;
            slot.y = j;
            return (slot);
        }
    }
    slot.x = -1;
    slot.y = -1;
    return (slot);
}

static sfVector2i get_empty_slot(inventory_t *inventory)
{
    sfVector2i slot = {0, 0};

    for (int i = 0; i < 3; i++) {
        slot = get_empty_slot_2(inventory, i);
        if (slot.x != -1 && slot.y != -1)
            return (slot);
    }
    return (slot);
}

bool have_item_in_inventory_2(rpg_t *game, int id, int i)
{
    for (int j = 0; j < 3; j++)
        if (game->inventory->items[i][j] == id)
            return (true);
    return (false);
}

bool have_item_in_inventory(rpg_t *game, char *name)
{
    int id = get_id_by_name(game, name);

    if (id == -1)
        return (false);
    for (int i = 0; i < 3; i++) {
        if (have_item_in_inventory_2(game, id, i))
            return (true);
    }
    return (false);
}

void give_item_in_inventory(rpg_t *game, char *name)
{
    int id = get_id_by_name(game, name);
    sfVector2i slot = get_empty_slot(game->inventory);

    if (id == -1)
        return;
    game->inventory->items[slot.x][slot.y] = id;
    game->boss->damage = game->items[id].damage;
    create_animation_item(game, name);
}

void remove_item_in_inventory(rpg_t *game, char *name)
{
    int id = get_id_by_name(game, name);

    if (id == -1)
        return;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game->inventory->items[i][j] == id)
                game->inventory->items[i][j] = 0;
        }
    }
}
