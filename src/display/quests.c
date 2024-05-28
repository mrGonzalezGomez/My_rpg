/*
** EPITECH PROJECT, 2024
** GAME-RPG [WSL: Ubuntu-22.04]
** File description:
** quests
*/

#include "my_rpg.h"

void display_quest_ingame(rpg_t *game, quest_t *quest)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(DEFAULT_FONT);
    sfVector2f pos =
        {game->map->map_info->view_x + 480, game->map->map_info->view_y - 400};

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, pos);
    set_string_to_text(text, quest->name);
    sfRenderWindow_drawText(game->window_data->window, text, NULL);
}

void display_quests(rpg_t *game)
{
    quest_t *tmp = game->quests;

    while (tmp != NULL) {
        if (tmp->state == IS_ACTIVE) {
            display_quest_ingame(game, tmp);
        }
        tmp = tmp->next;
    }
}
