/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** init
*/

#include "my_rpg.h"

void init_player_and_load_save(rpg_t *game, int save)
{
    FILE *file;
    char str[] = "saves_file/save";
    char save_str[26];

    game->player = malloc(sizeof(player_t));
    init_player(game, game->player);
    sprintf(save_str, "%s%d", str, save);
    file = fopen(save_str, "rb");
    if (file != NULL) {
        fread(&(game->player->pos.x), sizeof(game->player->pos.x), 1, file);
        fread(&(game->player->pos.y), sizeof(game->player->pos.y), 1, file);
        fclose(file);
    }
}

void init_game_2(rpg_t *game)
{
    game->interaction = malloc(sizeof(interaction_t));
    init_interaction(game->interaction);
    game->pnj = malloc(sizeof(pnj_t));
    init_pnjs(game->pnj);
    game->king = malloc(sizeof(pnj_t));
    init_king(game->king);
    init_dialogue(game);
}

void init_game_components(rpg_t *game)
{
    game->map = malloc(sizeof(map_t));
    init_map(game->map, game);
    game->map->parsing = malloc(sizeof(parsing_t));
    init_parsing(game->map->parsing);
    game->interaction = malloc(sizeof(interaction_t));
    init_interaction(game->interaction);
    game->quests = malloc(sizeof(quest_t));
    init_quests(game->quests);
    game->inventory = malloc(sizeof(inventory_t));
    init_inventory(game->inventory);
    game->inventory->items_anim = malloc(sizeof(items_anim_t));
    init_items_animation(game->inventory->items_anim);
    game->items = malloc(sizeof(items_t));
    init_items(game->items);
    game->boss = malloc(sizeof(boss_t));
    init_boss(game->boss, game);
}

void init_game(rpg_t *game, int save)
{
    init_player_and_load_save(game, save);
    init_game_components(game);
    init_game_2(game);
}

void init_struct(rpg_t *game)
{
    game->in_game = false;
    game->window_data = malloc(sizeof(windows_t));
    init_window(game->window_data);
    game->menu = malloc(sizeof(menu_t));
    init_menu(game->menu, game);
}
