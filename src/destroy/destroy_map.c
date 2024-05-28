/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** destroy_map
*/

#include "my_rpg.h"

void destroy_map_info(map_info_t *map_info)
{
    sfView_destroy(map_info->view);
    free(map_info);
}

void destroy_map(map_t *map)
{
    for (int i = 0; i < 13; i++) {
        sfTexture_destroy(map->map_sprites[i]->texture);
        for (int j = 0; j < 36; j++)
            sfSprite_destroy(map->map_sprites[i]->chunk[j]);
        free(map->map_sprites[i]);
    }
    destroy_map_info(map->map_info);
    free(map);
}
