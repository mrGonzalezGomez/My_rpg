/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** menu
*/

#include "my_rpg.h"

void create_sprite_escape_menu(escape_menu_t *menu)
{
    menu->texture = sfTexture_createFromFile(MAIN_MENU_TEXTURE, NULL);
    menu->texture_hover =
        sfTexture_createFromFile(MAIN_MENU_TEXTURE_HOVER, NULL);
    for (int i = 0; i < 3; i++) {
        menu->buttons[i] = sfSprite_create();
        sfSprite_setTexture(menu->buttons[i], menu->texture, sfTrue);
    }
}

void create_txt_escape_menu(escape_menu_t *menu)
{
    menu->font = sfFont_createFromFile(FONT_PATH);
    for (int i = 0; i < 3; i++) {
        menu->txt[i] = sfText_create();
        sfText_setFont(menu->txt[i], menu->font);
        sfText_setCharacterSize(menu->txt[i], 50);
        sfText_setColor(menu->txt[i], sfWhite);
    }
    set_string_to_text(menu->txt[0], "QUIT");
    set_string_to_text(menu->txt[1], "SAVE");
    set_string_to_text(menu->txt[2], "RESUME");
}

escape_menu_t *init_escape_menu(void)
{
    escape_menu_t *menu = malloc(sizeof(escape_menu_t));

    create_sprite_escape_menu(menu);
    create_txt_escape_menu(menu);
    menu->is_open = false;
    return menu;
}
