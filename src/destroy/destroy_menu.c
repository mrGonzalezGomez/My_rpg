/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** destroy_menu
*/

#include "my_rpg.h"

void destroy_main_menu(main_menu_t *main_menu)
{
    sfTexture_destroy(main_menu->back_texture);
    sfSprite_destroy(main_menu->background);
    sfTexture_destroy(main_menu->texture);
    sfTexture_destroy(main_menu->texture_hover);
    sfSprite_destroy(main_menu->spt_mid_button[0]);
    sfSprite_destroy(main_menu->spt_mid_button[1]);
    sfSprite_destroy(main_menu->spt_mid_button[2]);
    sfText_destroy(main_menu->txt_mid_button[0]);
    sfText_destroy(main_menu->txt_mid_button[1]);
    sfText_destroy(main_menu->txt_mid_button[2]);
    sfText_destroy(main_menu->txt_title);
    sfFont_destroy(main_menu->font);
}

void destroy_settings_menu(settings_menu_t *settings_menu)
{
    sfTexture_destroy(settings_menu->button_texture);
    sfTexture_destroy(settings_menu->button_hover_texture);
    sfTexture_destroy(settings_menu->button_add_texture);
    sfTexture_destroy(settings_menu->button_sub_texture);
    sfSprite_destroy(settings_menu->back_button);
    sfText_destroy(settings_menu->txt_back_button);
    for (int i = 0; i < 3; i++) {
        sfSprite_destroy(settings_menu->compenant[i]->add_button);
        sfSprite_destroy(settings_menu->compenant[i]->middle_button);
        sfSprite_destroy(settings_menu->compenant[i]->sub_button);
        sfText_destroy(settings_menu->compenant[i]->txt_compenant);
        free(settings_menu->compenant[i]);
    }
    for (int i = 0; i < 2; i++) {
        sfSprite_destroy(settings_menu->video_mode[i]);
        sfText_destroy(settings_menu->txt_video_mode[i]);
    }
    sfSprite_destroy(settings_menu->video_mode[2]);
    sfSprite_destroy(settings_menu->video_mode[3]);
    sfFont_destroy(settings_menu->font);
}

void destroy_save_menu(save_menu_t *save_menu)
{
    sfTexture_destroy(save_menu->texture);
    sfSprite_destroy(save_menu->buttons[0]);
    sfSprite_destroy(save_menu->buttons[1]);
    sfSprite_destroy(save_menu->buttons[2]);
    sfText_destroy(save_menu->txt[0]);
    sfText_destroy(save_menu->txt[1]);
    sfText_destroy(save_menu->txt[2]);
    sfFont_destroy(save_menu->font);
}

void destroy_menu(menu_t *menu)
{
    destroy_main_menu(menu->main_menu);
    destroy_settings_menu(menu->settings_menu);
    if (menu->background_music != NULL)
        sfMusic_destroy(menu->background_music);
    free(menu->main_menu);
    destroy_save_menu(menu->save_menu);
    free(menu);
}
