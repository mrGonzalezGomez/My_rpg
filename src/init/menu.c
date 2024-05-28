/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** menu
*/

#include "my_rpg.h"

static void create_back_ground_main_menu(main_menu_t *main_menu)
{
    main_menu->background = sfSprite_create();
    main_menu->back_texture = sfTexture_createFromFile(BACKGROUND_MENU, NULL);
    sfSprite_setTexture(main_menu->background, main_menu->back_texture,
        sfTrue);
}

static void create_text_main_menu(main_menu_t *main_menu)
{
    main_menu->font = sfFont_createFromFile(FONT_PATH);
    main_menu->txt_title = sfText_create();
    main_menu->txt_mid_button[0] = sfText_create();
    main_menu->txt_mid_button[1] = sfText_create();
    main_menu->txt_mid_button[2] = sfText_create();
    sfText_setFont(main_menu->txt_title, main_menu->font);
    sfText_setFont(main_menu->txt_mid_button[0], main_menu->font);
    sfText_setFont(main_menu->txt_mid_button[1], main_menu->font);
    sfText_setFont(main_menu->txt_mid_button[2], main_menu->font);
    set_string_to_text(main_menu->txt_title, MAIN_MENU_TITLE);
    set_string_to_text(main_menu->txt_mid_button[0], "PLAY");
    set_string_to_text(main_menu->txt_mid_button[1], "QUIT");
    set_string_to_text(main_menu->txt_mid_button[2], "OPTION");
    sfText_setCharacterSize(main_menu->txt_title, 200);
    sfText_setCharacterSize(main_menu->txt_mid_button[0], 50);
    sfText_setCharacterSize(main_menu->txt_mid_button[1], 50);
    sfText_setCharacterSize(main_menu->txt_mid_button[2], 50);
    sfText_setColor(main_menu->txt_title, sfWhite);
}

static void create_button_main_menu(main_menu_t *main_menu)
{
    main_menu->texture = sfTexture_createFromFile(MAIN_MENU_TEXTURE, NULL);
    main_menu->texture_hover =
        sfTexture_createFromFile(MAIN_MENU_TEXTURE_HOVER, NULL);
    main_menu->spt_mid_button[0] = sfSprite_create();
    main_menu->spt_mid_button[1] = sfSprite_create();
    main_menu->spt_mid_button[2] = sfSprite_create();
    sfSprite_setTexture(main_menu->spt_mid_button[0], main_menu->texture,
        sfTrue);
    sfSprite_setTexture(main_menu->spt_mid_button[1], main_menu->texture,
        sfTrue);
    sfSprite_setTexture(main_menu->spt_mid_button[2], main_menu->texture,
        sfTrue);
}

static void set_position_main_menu(main_menu_t *main_menu)
{
    sfSprite_setPosition(main_menu->spt_mid_button[0],
        (sfVector2f){MAIN_MENU_PLAY_POS_X, MAIN_MENU_PLAY_POS_Y});
    sfSprite_setPosition(main_menu->spt_mid_button[1],
        (sfVector2f){MAIN_MENU_QUIT_POS_X, MAIN_MENU_QUIT_POS_Y});
    sfSprite_setPosition(main_menu->spt_mid_button[2],
        (sfVector2f){MAIN_MENU_OPTION_POS_X, MAIN_MENU_OPTION_POS_Y});
    sfText_setPosition(main_menu->txt_title,
        (sfVector2f){MAIN_MENU_TITLE_POS_X, MAIN_MENU_TITLE_POS_Y});
    sfText_setPosition(main_menu->txt_mid_button[0], (sfVector2f)
        {MAIN_MENU_PLAY_POS_X + 155 / 2 + 20, MAIN_MENU_PLAY_POS_Y});
    sfText_setPosition(main_menu->txt_mid_button[1], (sfVector2f)
        {MAIN_MENU_QUIT_POS_X + 155 / 2 + 20, MAIN_MENU_QUIT_POS_Y});
    sfText_setPosition(main_menu->txt_mid_button[2], (sfVector2f)
        {MAIN_MENU_OPTION_POS_X + 155 / 2, MAIN_MENU_OPTION_POS_Y});
}

void init_main_menu(main_menu_t *main_menu)
{
    create_back_ground_main_menu(main_menu);
    create_text_main_menu(main_menu);
    create_button_main_menu(main_menu);
    set_position_main_menu(main_menu);
}

void init_music(menu_t *menu, rpg_t *rpg)
{
    menu->background_music = sfMusic_createFromFile(BACK_GROUND_MUSIC);
    sfMusic_setVolume(menu->background_music,
        rpg->window_data->vol_principal * rpg->window_data->vol_music * 100);
    sfMusic_setLoop(menu->background_music, sfTrue);
    sfMusic_play(menu->background_music);
}

void init_menu(menu_t *menu, rpg_t *rpg)
{
    menu->main_menu = malloc(sizeof(main_menu_t));
    init_main_menu(menu->main_menu);
    menu->setting_open = false;
    menu->settings_menu = malloc(sizeof(settings_menu_t));
    init_settings_menu(menu->settings_menu, rpg);
    init_music(menu, rpg);
    init_save_menu(menu);
}
