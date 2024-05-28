/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** destroy_loading
*/

#include "my_rpg.h"

void destroy_loading_screen(loading_menu_t *loading_menu)
{
    sfText_destroy(loading_menu->txt_loading);
    sfText_destroy(loading_menu->txt_title);
    sfRectangleShape_destroy(loading_menu->background);
    free(loading_menu);
}
