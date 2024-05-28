/*
** EPITECH PROJECT, 2024
** GAME-RPG [WSL: Ubuntu-22.04]
** File description:
** load_data
*/

#include "my_rpg.h"

void choose_save(rpg_t *game, int save)
{
    game->save = save;
    game->in_game = true;
    loadin_screen(game->menu, game);
    init_game(game, save);
    destroy_loading_screen(game->menu->loading_menu);
    destroy_menu(game->menu);
    game->menu = NULL;
}

void save_data(rpg_t *game, int save)
{
    FILE *file;
    char str[] = "saves_file/save";
    char save_str[26];

    sprintf(save_str, "%s%d", str, save);
    file = fopen(save_str, "wb");
    if (file != NULL) {
        fwrite(&(game->player->pos.x), sizeof(game->player->pos.x), 1, file);
        fwrite(&(game->player->pos.y), sizeof(game->player->pos.y), 1, file);
        fclose(file);
    }
}
