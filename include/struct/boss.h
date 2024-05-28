/*
** EPITECH PROJECT, 2023
** GAME-RPG
** File description:
** boss.h
*/

#pragma once
#include "csfml_lib.h"

typedef struct boss_speech_s {
    sfTexture *background_texture;
    sfSprite *background_sprite;
    sfFont *font;
    sfText *text;
    bool is_displayed;
} boss_speech_t;

typedef struct boss_player_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int width;
    int height;
    int frame_width;
    int num_frames;
    int current_frame;
    sfClock *animation_clock;
    int current_cycle;
    int max_cycles;
    bool animation_finished;
} boss_player_t;

typedef struct boss_sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int width;
    int height;
    int frame_width;
    int num_frames;
    int current_frame;
    sfClock *animation_clock;
    int current_cycle;
    int max_cycles;
    bool animation_finished;
} boss_sprite_t;

typedef struct text_display_params_s {
    sfRenderWindow *window;
    sfText *text;
    sfRectangleShape *background;
    const char *str;
    sfVector2f position;
} text_display_params_t;

typedef struct fight_sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfFont *font;
    sfText *text;
    bool is_displayed;
} fight_sprite_t;

typedef struct boss_s {
    boss_sprite_t *idle;
    boss_sprite_t *attack;
    boss_sprite_t *death;
    boss_sprite_t *hurt;
    boss_sprite_t *in_combat;
    boss_player_t *idle_pl;
    boss_player_t *attack_pl;
    boss_player_t *death_pl;
    boss_player_t *protect;
    sfTexture *heart_text;
    sfTexture *background;
    sfTexture *life_bar_text;
    sfSprite *back_sp;
    sfSprite *life_bar_sp[5];
    sfSprite *life_bar_sp_pl[5];
    sfVector2f pos;
    clock_data_t *clock;
    bool death_started;
    bool death_started_pl;
    bool attack_started_pl;
    bool attack_started;
    bool hit_started_pl;
    bool hit_started;
    bool defend_started_pl;
    bool is_dead;
    bool is_dead_pl;
    int boss_life;
    int boss_max_life;
    int player_life;
    int player_max_life;
    int damage;
    int protection;
    sfMusic *music;
    char **speech;
    fight_sprite_t *attack_button;
    fight_sprite_t *defend_button;
    fight_sprite_t *heal_button;
    fight_sprite_t *run_button;
} boss_t;
