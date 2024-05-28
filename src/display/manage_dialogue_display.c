/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** manager
*/

#include "my_rpg.h"

void animation_sprite_talk(dialogue_t *dia)
{
    if (dia->animation_rect.left >= 576 / 4 * 3)
        dia->animation_rect.left = 0;
    else
        dia->animation_rect.left += 576 / 4;
    sfSprite_setTextureRect(dia->animation_sprite, dia->animation_rect);
}

static void set_new_letter_dialogue(dialogue_t *dia)
{
    dia->tmp = realloc(dia->tmp, sizeof(char) * ((strlen(dia->tmp) + 2)));
    dia->tmp[dia->letter_id] = dia->text[dia->txt_id][dia->letter_id];
    dia->tmp[dia->letter_id + 1] = '\0';
    set_string_to_text(dia->text_obj, dia->tmp);
    dia->letter_id++;
}

void manage_str_to_display(rpg_t *rpg)
{
    dialogue_t *dia = rpg->actual_dialogue;

    if (!dia->txt_is_hover &&
        sfTime_asSeconds(sfClock_getElapsedTime(dia->clock)) > 0.3) {
        animation_sprite_talk(dia);
        sfClock_restart(dia->clock);
    }
    if (!dia->txt_is_hover &&
        sfTime_asSeconds(sfClock_getElapsedTime(dia->clock_letter)) > 0.05) {
        if (dia->text[dia->txt_id][dia->letter_id] != '\0') {
            set_new_letter_dialogue(dia);
        } else {
            dia->txt_is_hover = true;
            dia->animation_rect.left = 0;
            sfSprite_setTextureRect(dia->animation_sprite, dia->animation_rect);
        }
        sfClock_restart(dia->clock_letter);
    }
}

void manage_dialogue_display(rpg_t *rpg)
{
    sfVector2f pos = {rpg->map->map_info->view_x,
        rpg->map->map_info->view_y};

    if (rpg->actual_dialogue == NULL)
        return;
    if (rpg->actual_dialogue->activ == true) {
        sfSprite_setPosition(rpg->actual_dialogue->animation_sprite,
            (sfVector2f){pos.x - 750, pos.y + 190});
        sfText_setPosition(rpg->actual_dialogue->text_obj,
            (sfVector2f){pos.x - 400, pos.y + 300});
        manage_str_to_display(rpg);
        sfRenderWindow_drawSprite(rpg->window_data->window,
            rpg->actual_dialogue->animation_sprite, NULL);
        sfRenderWindow_drawText(rpg->window_data->window,
            rpg->actual_dialogue->text_obj, NULL);
    }
}
