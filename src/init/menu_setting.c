/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** menu
*/

#include "my_rpg.h"
#include <stdio.h>

static void create_package_settings_menu(settings_menu_t *settings_menu)
{
    settings_menu->font = sfFont_createFromFile(FONT_PATH);
    settings_menu->button_texture = sfTexture_createFromFile(
        MAIN_MENU_TEXTURE, NULL);
    settings_menu->button_hover_texture = sfTexture_createFromFile(
        MAIN_MENU_TEXTURE_HOVER, NULL);
    settings_menu->button_add_texture = sfTexture_createFromFile(
        SETTING_BUTTON_ADD, NULL);
    settings_menu->button_sub_click_texture = sfTexture_createFromFile(
        SETTING_BUTTON_SUB_CLICK, NULL);
    settings_menu->button_sub_texture = sfTexture_createFromFile(
        SETTING_BUTTON_SUB, NULL);
    settings_menu->button_add_click_texture = sfTexture_createFromFile(
        SETTING_BUTTON_ADD_CLICK, NULL);
}

static compenant_t *create_package_compenant(void)
{
    compenant_t *compenant = malloc(sizeof(compenant_t));

    compenant->add_button = sfSprite_create();
    compenant->middle_button = sfSprite_create();
    compenant->sub_button = sfSprite_create();
    compenant->txt_compenant = sfText_create();
    return compenant;
}

static void asigne_position_compenant(compenant_t *compenant, int i)
{
    sfVector2f add_pos =
        {SETTING_MENU_ADD_POS_X, SETTING_MENU_ADD_POS_Y + i * 100};
    sfVector2f middle_pos =
        {SETTING_MENU_MIDDLE_POS_X, SETTING_MENU_MIDDLE_POS_Y + i * 100};
    sfVector2f sub_pos =
        {SETTING_MENU_SUB_POS_X, SETTING_MENU_SUB_POS_Y + i * 100};
    sfVector2f tmp_txt_pos =
        {SETTING_TXT_POS_X, SETTING_TXT_POS_Y};
    sfVector2f txt_pos;

    sfSprite_setPosition(compenant->add_button, add_pos);
    sfSprite_setPosition(compenant->middle_button, middle_pos);
    sfSprite_setPosition(compenant->sub_button, sub_pos);
    if (i == 0)
        txt_pos = (sfVector2f) {tmp_txt_pos.x - 90, tmp_txt_pos.y};
    else if (i == 1)
        txt_pos = (sfVector2f) {tmp_txt_pos.x - 85, tmp_txt_pos.y};
    else
        txt_pos = (sfVector2f) {tmp_txt_pos.x - 65, tmp_txt_pos.y};
    sfText_setPosition(compenant->txt_compenant, txt_pos);
}

static void set_txt_button_setting_menu(settings_menu_t *set_menu,
    rpg_t *rpg)
{
    char *vol_principal = malloc(sizeof(char) * 23);
    char *vol_musique = malloc(sizeof(char) * 21);
    char *vol_effets = malloc(sizeof(char) * 20);

    snprintf(vol_principal, 23, "Volume principal : %.1f",
        rpg->window_data->vol_principal);
    snprintf(vol_musique, 21, "Volume musique : %.1f",
        rpg->window_data->vol_music);
    snprintf(vol_effets, 20, "Volume effets : %.1f",
        rpg->window_data->vol_effets);
    set_string_to_text(set_menu->compenant[0]->txt_compenant, vol_principal);
    set_string_to_text(set_menu->compenant[1]->txt_compenant, vol_musique);
    set_string_to_text(set_menu->compenant[2]->txt_compenant, vol_effets);
    free(vol_principal);
    free(vol_musique);
    free(vol_effets);
}

void create_compenant_setting_menu(settings_menu_t *set_menu,
    rpg_t *rpg)
{
    for (int i = 0; i < 3; i++) {
        set_menu->compenant[i] = create_package_compenant();
        sfSprite_setTexture(set_menu->compenant[i]->add_button,
            set_menu->button_add_texture, sfTrue);
        sfSprite_setTexture(set_menu->compenant[i]->middle_button,
            set_menu->button_texture, sfTrue);
        sfSprite_setTexture(set_menu->compenant[i]->sub_button,
            set_menu->button_sub_texture, sfTrue);
        sfText_setFont(set_menu->compenant[i]->txt_compenant,
            set_menu->font);
        sfText_setCharacterSize(set_menu->compenant[i]->txt_compenant, 30);
        sfText_setColor(set_menu->compenant[i]->txt_compenant, sfWhite);
        asigne_position_compenant(set_menu->compenant[i], i);
    }
    set_txt_button_setting_menu(set_menu, rpg);
}

void create_back_button_setting_menu(settings_menu_t *settings_menu,
    rpg_t *rpg)
{
    settings_menu->back_button = sfSprite_create();
    sfSprite_setTexture(settings_menu->back_button,
        settings_menu->button_texture, sfTrue);
    settings_menu->txt_back_button = sfText_create();
    sfText_setFont(settings_menu->txt_back_button, settings_menu->font);
    set_string_to_text(settings_menu->txt_back_button, "BACK");
    sfText_setCharacterSize(settings_menu->txt_back_button, 50);
    sfText_setColor(settings_menu->txt_back_button, sfWhite);
    sfSprite_setPosition(settings_menu->back_button, (sfVector2f)
        {SETTING_MENU_BACK_POS_X, SETTING_MENU_BACK_POS_Y});
    sfText_setPosition(settings_menu->txt_back_button, (sfVector2f)
        {SETTING_MENU_BACK_POS_X + 100, SETTING_MENU_BACK_POS_Y});
    create_compenant_setting_menu(settings_menu, rpg);
}

static void asigne_position_video_mode(settings_menu_t *settings_menu, int i)
{
    sfVector2f pos = {SETTING_MENU_VIDEO_MODE_POS_X + i * 400,
        SETTING_MENU_VIDEO_MODE_POS_Y};
    sfVector2f txt_pos = {pos.x, pos.y};

    if (i == 1)
        txt_pos.x += 75;
    else
        txt_pos.x += 25;
    sfSprite_setPosition(settings_menu->video_mode[i], pos);
    sfText_setPosition(settings_menu->txt_video_mode[i], txt_pos);
}

void create_video_mode_button(settings_menu_t *settings_menu)
{
    for (int i = 0; i < 2; i++) {
        settings_menu->video_mode[i] = sfSprite_create();
        settings_menu->txt_video_mode[i] = sfText_create();
        sfSprite_setTexture(settings_menu->video_mode[i],
            settings_menu->button_texture, sfTrue);
        sfText_setFont(settings_menu->txt_video_mode[i], settings_menu->font);
        sfText_setCharacterSize(settings_menu->txt_video_mode[i], 50);
        sfText_setColor(settings_menu->txt_video_mode[i], sfWhite);
        asigne_position_video_mode(settings_menu, i);
    }
    for (int i = 2; i < 4; i++) {
        settings_menu->video_mode[i] = sfSprite_create();
        sfSprite_setTexture(settings_menu->video_mode[i],
            settings_menu->button_texture, sfTrue);
    }
    set_string_to_text(settings_menu->txt_video_mode[0], "Plein ecran");
    set_string_to_text(settings_menu->txt_video_mode[1], "Fenetre");
}

void init_settings_menu(settings_menu_t *settings_menu, rpg_t *rpg)
{
    create_package_settings_menu(settings_menu);
    create_back_button_setting_menu(settings_menu, rpg);
    create_video_mode_button(settings_menu);
    settings_menu->clock = NULL;
}
