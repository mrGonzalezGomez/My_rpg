/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** save
*/

#include "my_rpg.h"

static void create_button_save_menu(save_menu_t *save_menu)
{
    save_menu->texture = sfTexture_createFromFile(MAIN_MENU_TEXTURE, NULL);
    save_menu->hover = sfTexture_createFromFile(MAIN_MENU_TEXTURE_HOVER,
        NULL);
    save_menu->buttons[0] = sfSprite_create();
    save_menu->buttons[1] = sfSprite_create();
    save_menu->buttons[2] = sfSprite_create();
    sfSprite_setTexture(save_menu->buttons[0], save_menu->texture,
        sfTrue);
    sfSprite_setTexture(save_menu->buttons[1], save_menu->texture,
        sfTrue);
    sfSprite_setTexture(save_menu->buttons[2], save_menu->texture,
        sfTrue);
}

void create_text_save_menu(save_menu_t *save_menu)
{
    save_menu->font = sfFont_createFromFile(FONT_PATH);
    save_menu->txt_title = sfText_create();
    save_menu->txt[0] = sfText_create();
    save_menu->txt[1] = sfText_create();
    save_menu->txt[2] = sfText_create();
    sfText_setFont(save_menu->txt_title, save_menu->font);
    sfText_setFont(save_menu->txt[0], save_menu->font);
    sfText_setFont(save_menu->txt[1], save_menu->font);
    sfText_setFont(save_menu->txt[2], save_menu->font);
    set_string_to_text(save_menu->txt_title, "CHOOSE YOUR SAVE");
    set_string_to_text(save_menu->txt[0], "SAVE 1");
    set_string_to_text(save_menu->txt[1], "SAVE 2");
    set_string_to_text(save_menu->txt[2], "SAVE 3");
    sfText_setCharacterSize(save_menu->txt_title, 100);
    sfText_setCharacterSize(save_menu->txt[0], 50);
    sfText_setCharacterSize(save_menu->txt[1], 50);
    sfText_setCharacterSize(save_menu->txt[2], 50);
}

static void set_position_save_menu(save_menu_t *save_menu)
{
    sfSprite_setPosition(save_menu->buttons[0],
        (sfVector2f){SAVE_1_POS_X, SAVE_1_POS_Y});
    sfSprite_setPosition(save_menu->buttons[1],
        (sfVector2f){SAVE_2_POS_X, SAVE_2_POS_Y});
    sfSprite_setPosition(save_menu->buttons[2],
        (sfVector2f){SAVE_3_POS_X, SAVE_3_POS_Y});
    sfText_setPosition(save_menu->txt[0], (sfVector2f)
        {SAVE_1_TXT_X + 155 / 2 + 20, SAVE_1_TXT_Y});
    sfText_setPosition(save_menu->txt[1], (sfVector2f)
        {SAVE_2_TXT_X + 155 / 2 + 20, SAVE_2_TXT_Y});
    sfText_setPosition(save_menu->txt[2], (sfVector2f)
        {SAVE_3_TXT_X + 155 / 2 + 20, SAVE_3_TXT_Y});
    sfText_setPosition(save_menu->txt_title, (sfVector2f)
        {960 - 400, 650});
}

void init_save_menu(menu_t *menu)
{
    menu->save_menu = malloc(sizeof(save_menu_t));
    create_text_save_menu(menu->save_menu);
    create_button_save_menu(menu->save_menu);
    set_position_save_menu(menu->save_menu);
}
