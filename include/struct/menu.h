/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** main_menu
*/

#pragma once

#include "csfml_lib.h"
#include "utils.h"

typedef struct save_menu_s {
    sfText *txt_title;
    sfTexture *texture;
    sfSprite *buttons[3];
    sfText *txt[3];
    sfFont *font;
    sfTexture *hover;
} save_menu_t;

typedef struct main_menu_s {
    sfText *txt_title;
    sfTexture *texture;
    sfTexture *texture_hover;
    sfSprite *spt_mid_button[3];
    sfText *txt_mid_button[3];
    sfFont *font;
    sfTexture *back_texture;
    sfSprite *background;
} main_menu_t;

typedef struct loading_menu_s {
    sfText *txt_title;
    sfText *txt_loading;
    sfRectangleShape *background;
} loading_menu_t;

typedef struct compenant_s {
    sfSprite *add_button;
    sfSprite *add_button_click;
    sfSprite *middle_button;
    sfSprite *sub_button;
    sfSprite *sub_button_click;
    sfText *txt_compenant;
} compenant_t;

typedef struct settings_menu_s {
    sfFont *font;
    sfTexture *button_texture;
    sfTexture *button_hover_texture;
    sfTexture *button_add_texture;
    sfTexture *button_add_click_texture;
    sfTexture *button_sub_texture;
    sfTexture *button_sub_click_texture;

    sfSprite *video_mode[4];
    sfText *txt_video_mode[2];
    sfSprite *back_button;
    sfText *txt_back_button;
    sfClock *clock;
    compenant_t *compenant[3];
} settings_menu_t;

typedef struct menu_s {
    main_menu_t *main_menu;
    loading_menu_t *loading_menu;
    bool setting_open;
    settings_menu_t *settings_menu;
    sfMusic *background_music;
    save_menu_t *save_menu;
} menu_t;

typedef struct escape_menu_s {
    sfFont *font;
    sfTexture *texture;
    sfTexture *texture_hover;
    sfSprite *buttons[3];
    sfText *txt[3];
    bool is_open;
} escape_menu_t;
