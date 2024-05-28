/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** manager
*/

#include "my_rpg.h"

void reset_txt_dialogue(dialogue_t *dia)
{
    dia->txt_id++;
    dia->letter_id = 0;
    free(dia->tmp);
    dia->tmp = strdup("\0");
    dia->txt_is_hover = false;
}

void set_full_txt_dialogue(dialogue_t *dia)
{
    while (dia->text[dia->txt_id][dia->letter_id] != '\0') {
        dia->tmp = realloc(dia->tmp, sizeof(char) *
            ((strlen(dia->tmp) + 2)));
        dia->tmp[dia->letter_id] = dia->text[dia->txt_id][dia->letter_id];
        dia->tmp[dia->letter_id + 1] = '\0';
        dia->letter_id++;
    }
    set_string_to_text(dia->text_obj, dia->tmp);
    dia->animation_rect.left = 0;
    sfSprite_setTextureRect(dia->animation_sprite, dia->animation_rect);
    dia->txt_is_hover = true;
}

void manage_click_dialogue(rpg_t *game)
{
    dialogue_t *dia = game->actual_dialogue;

    if (dia == NULL)
        return;
    if (dia->txt_is_hover && dia->nb_text == dia->txt_id + 1) {
        game->actual_dialogue = NULL;
        return;
    }
    if (dia->txt_is_hover) {
        reset_txt_dialogue(dia);
    } else
        set_full_txt_dialogue(dia);
}

void manage_click(rpg_t *game)
{
    if (!game->in_game)
        return manage_click_menu(game);
    if (game->escape_menu->is_open)
        return manage_click_menu_escape(game);
    if (game->in_game)
        return manage_click_dialogue(game);
}
