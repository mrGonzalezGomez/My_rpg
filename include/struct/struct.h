/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** structure
*/

#pragma once

#include "csfml_lib.h"
#include "utils.h"
#include "player.h"
#include "map.h"
#include "interaction.h"
#include "menu.h"
#include "quests.h"
#include "inventory.h"
#include "boss.h"
#include "death.h"
#include "pnj.h"
#include "dialogue.h"
#include <stdbool.h>

/*
Structure of the window
*/
typedef struct windows_s {
    sfRenderWindow* window;
    clock_data_t *clock;
    sfTime time;
    sfEvent event;
    float vol_principal;
    float vol_music;
    float vol_effets;
    bool fullscreen;
} windows_t;

/*
Principal structure of the game
*/
typedef struct s_rpg {
    windows_t *window_data;
    player_t *player;
    map_t *map;
    bool in_game;
    bool in_save;
    bool in_boss;
    int save;
    menu_t *menu;
    interaction_t *interaction;
    escape_menu_t *escape_menu;
    quest_t *quests;
    inventory_t *inventory;
    items_t *items;
    boss_t *boss;
    boss_speech_t *boss_speech;
    bool show_death_screen;
    pnj_t *pnj;
    pnj_t *king;
    dialogue_t *dialogue;
    dialogue_t *actual_dialogue;
    bool collision;
} rpg_t;
