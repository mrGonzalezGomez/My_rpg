/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** manager
*/

#include "my_rpg.h"

static bool is_chunk_within_bounds(int chunk_x, int chunk_y)
{
    return (chunk_x >= 0 && chunk_x < 6 && chunk_y >= 0 && chunk_y < 6);
}

static void draw_chunk(sfRenderWindow *window, map_sprites_t *map_sprite,
    int chunk_index)
{
    sfRenderWindow_drawSprite(window, map_sprite->chunk[chunk_index], NULL);
}

void process_chunk(sfRenderWindow *window, map_sprites_t *map_sprite,
    int chunk_x, int chunk_y)
{
    int chunk_index;

    if (is_chunk_within_bounds(chunk_x, chunk_y)) {
        chunk_index = chunk_y * 6 + chunk_x;
        draw_chunk(window, map_sprite, chunk_index);
    }
}

static void process_sprite_chunks(sfRenderWindow *window,
    map_sprites_t *map_sprite, map_info_t *map_info)
{
    int chunk_x_to_display;
    int chunk_y_to_display;

    for (int y_offset = -map_info->chunks_to_display; y_offset
        <= map_info->chunks_to_display; y_offset++) {
        for (int x_offset = -map_info->chunks_to_display; x_offset
            <= map_info->chunks_to_display; x_offset++) {
            chunk_x_to_display = map_info->chunk_x + x_offset;
            chunk_y_to_display = map_info->chunk_y + y_offset;
            process_chunk(window, map_sprite, chunk_x_to_display,
                chunk_y_to_display);
        }
    }
}

static void draw_visible_chunks(rpg_t *game, map_t *map, map_info_t *map_info)
{
    map_sprites_t *map_sprite;

    for (int i = 0; i < 13; i++) {
        map_sprite = map->map_sprites[i];
        process_sprite_chunks(game->window_data->window,
            map_sprite, map_info);
        if (i == 9) {
            manage_display_pnjs(game);
            manage_display_player(game);
        }
    }
}

void manage_display_map(rpg_t *game, map_t *map)
{
    map_info_t *map_info = game->map->map_info;
    sfVector2f player_pos = game->player->pos;

    map_info->chunk_x = (int)((player_pos.x + 25) / 1604);
    map_info->chunk_y = (int)(player_pos.y / 1604);
    map_info->view_x = player_pos.x + 25;
    map_info->view_y = player_pos.y;
    set_view_center(map->map_info->view, map->map_info);
    draw_visible_chunks(game, map, map_info);
    sfRenderWindow_setView(game->window_data->window, map->map_info->view);
}

void display_menu(rpg_t *game, menu_t *menu)
{
    if (menu->setting_open)
        return display_settings_menu(game, menu);
    display_main_menu(game, menu);
}

static void display_interaction(rpg_t *game)
{
    for (int i = 0; i < game->interaction->nb_interact; i++) {
        if (game->interaction->is_active[i]) {
            sfSprite_setPosition(game->interaction->sprite,
                (sfVector2f){game->player->pos.x + 50,
                    game->player->pos.y - 25});
            sfRenderWindow_drawSprite(game->window_data->window,
                game->interaction->sprite, NULL);
        }
    }
}

void manager_display(rpg_t *game)
{
    if (!game->in_game && !game->in_save) {
        display_menu(game, game->menu);
        return;
    }
    if (!game->in_game && game->in_save) {
        display_save_buttons(game, game->menu, game->menu->save_menu);
        return;
    }
    manage_display_map(game, game->map);
    display_interaction(game);
    if (game->escape_menu->is_open)
        display_menu_escape(game, game->escape_menu);
    display_quests(game);
    if (game->inventory->items_anim->is_anim)
        display_item_animation(game);
    if (game->quests->display_completed)
        display_quest_completed(game);
    if (game->in_boss == true)
        display_boss(game);
    manage_dialogue_display(game);
}
