/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** manager
*/

#include "my_rpg.h"

void update_display_princiapl_volume(rpg_t *game)
{
    char *vol_principal = malloc(sizeof(char) * 23);

    snprintf(vol_principal, 23, "Volume principal : %.1f",
        game->window_data->vol_principal);
    set_string_to_text(game->menu->settings_menu->compenant[0]->txt_compenant,
        vol_principal);
    free(vol_principal);
    if (game->menu->setting_open)
        sfMusic_setVolume(game->menu->background_music,
            game->window_data->vol_principal * game->window_data->vol_music *
                100);
}

void update_display_music_volume(rpg_t *game)
{
    char *vol_music = malloc(sizeof(char) * 23);

    snprintf(vol_music, 23, "Volume musique : %.1f",
        game->window_data->vol_music);
    set_string_to_text(game->menu->settings_menu->compenant[1]->txt_compenant,
        vol_music);
    free(vol_music);
    sfMusic_setVolume(game->menu->background_music,
        game->window_data->vol_principal * game->window_data->vol_music * 100);
}

void update_display_effect_volume(rpg_t *game)
{
    char *vol_effect = malloc(sizeof(char) * 23);

    snprintf(vol_effect, 23, "Volume effets : %.1f",
        game->window_data->vol_effets);
    set_string_to_text(game->menu->settings_menu->compenant[2]->txt_compenant,
        vol_effect);
    free(vol_effect);
}

sfFloatRect *get_compenant(rpg_t *game)
{
    sfFloatRect *compenant = malloc(sizeof(sfFloatRect) * 6);

    compenant[0] = sfSprite_getGlobalBounds(
        game->menu->settings_menu->compenant[0]->add_button);
    compenant[1] = sfSprite_getGlobalBounds(
        game->menu->settings_menu->compenant[0]->sub_button);
    compenant[2] = sfSprite_getGlobalBounds(
        game->menu->settings_menu->compenant[1]->add_button);
    compenant[3] = sfSprite_getGlobalBounds(
        game->menu->settings_menu->compenant[1]->sub_button);
    compenant[4] = sfSprite_getGlobalBounds(
        game->menu->settings_menu->compenant[2]->add_button);
    compenant[5] = sfSprite_getGlobalBounds(
        game->menu->settings_menu->compenant[2]->sub_button);
    return compenant;
}
