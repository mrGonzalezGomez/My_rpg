/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** map
*/

#include "my_rpg.h"

void create_chunks(map_t *map, int i)
{
    int pos_x = 0;
    int pos_y = 0;

    for (int y = 0; y < 36; y++) {
        map->map_sprites[i]->chunk[y] = sfSprite_create();
        sfSprite_setTexture(map->map_sprites[i]->chunk[y],
            map->map_sprites[i]->texture, sfTrue);
        map->map_sprites[i]->rect = (sfIntRect){pos_x, pos_y, 1604, 1604};
        sfSprite_setTextureRect(map->map_sprites[i]->chunk[y],
            map->map_sprites[i]->rect);
        sfSprite_setPosition(map->map_sprites[i]->chunk[y],
            (sfVector2f){(y % 6) * 1604, (y / 6) * 1604});
        pos_x += 1604;
        if (pos_x >= 9624) {
            pos_x = 0;
            pos_y += 1604;
        }
    }
}

void set_new_volume(rpg_t *game, int i)
{
    int volume =
        game->window_data->vol_principal * game->window_data->vol_music * 100;
    int new_volume = volume * (12 - i) / 12;

    sfMusic_setVolume(game->menu->background_music, new_volume);
}

void init_map_info(map_t *map, sfRenderWindow *window)
{
    map->map_info = malloc(sizeof(map_info_t));
    map->map_info->chunk_x = 0;
    map->map_info->chunk_y = 0;
    map->map_info->chunks_to_display = 2;
    map->map_info->window_size = sfRenderWindow_getSize(window);
    map->map_info->view = sfView_create();
    map->map_info->map_width = 9624;
    map->map_info->map_height = 9624;
    map->map_info->view_x = 0;
    map->map_info->view_y = 0;
    sfView_setSize(map->map_info->view,
        (sfVector2f){(float)map->map_info->window_size.x,
        (float)map->map_info->window_size.y});
    sfRenderWindow_setView(window, map->map_info->view);
}

void init_map(map_t *map, rpg_t *game)
{
    char str[24];
    char loading[4];

    for (int i = 0; i < 13; i++) {
        sfRenderWindow_pollEvent(game->window_data->window,
            &game->window_data->event);
        map->map_sprites[i] = malloc(sizeof(map_sprites_t));
        sprintf(str, "assets/map/Calque%d.png", i + 1);
        if (i < 12) {
            sprintf(loading, "%d%%", (i + 1) * 8);
            set_string_to_text(game->menu->loading_menu->txt_loading, loading);
            display_loading_screen(game->menu, game);
        }
        map->map_sprites[i]->texture = sfTexture_createFromFile(
            str, NULL);
        create_chunks(map, i);
        set_new_volume(game, i);
    }
    init_map_info(map, game->window_data->window);
    game->escape_menu = init_escape_menu();
}
