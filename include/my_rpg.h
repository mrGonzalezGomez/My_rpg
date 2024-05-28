/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** my_rpg.h
*/

#pragma once
#include "lib.h"
#include "struct/struct.h"
#include "define.h"

// C
#include <stddef.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/// --- INIT --- ///
void init_struct(rpg_t *game);
void init_game(rpg_t *game, int save);
//window.c
void init_window(windows_t *window);
// create_clock.c
clock_data_t *create_clock(void);
//player.c
void init_player(rpg_t *game, player_t *player);
void move_player_sprite(enum player_move move, player_sprites_t *sprite,
    player_t *player);
void move_sprite(player_sprites_t *sprite, int height, int width, int skip_md);
//map.c
void init_map(map_t *map, rpg_t *game);
//menu.c
void init_menu(menu_t *menu, rpg_t *game);

void init_king(pnj_t *king);
void display_menu(rpg_t *game, menu_t *menu);
//save_menu.c
void init_save_menu(menu_t *menu);
void display_save_buttons(rpg_t *game, menu_t *menu, save_menu_t *save_menu);
// escape_menu.c
escape_menu_t *init_escape_menu(void);
// pnj.c
void init_pnjs(pnj_t *pnj);
// dialogue.c
void init_dialogue(rpg_t *rpg);

/// --- LOOP --- ///
void game_loop(rpg_t *game);

/// --- DESTROY --- ///
// destroy.c
void destroy(rpg_t *game);
// destroy_map.c
void destroy_map(map_t *map);
// destroy_player.c
void destroy_player(player_t *player);
// destroy_menu.c
void destroy_menu(menu_t *menu);
void destroy_loading_screen(loading_menu_t *loading_menu);
// destroy_loading.c
void destroy_loading_screen(loading_menu_t *loading_menu);
// destroy_pnjs.c
void destroy_pnjs(pnj_t *pnj);

/// --- DISPLAY --- ///
void manager_display(rpg_t *game);
// player.c
void display_player(rpg_t *game, player_sprites_t *sprite);
void manage_display_player(rpg_t *game);
// menu.c
void display_main_menu(rpg_t *game, menu_t *menu);
void display_settings_menu(rpg_t *game, menu_t *menu);
// menu_settings.c
void init_settings_menu(settings_menu_t *settings_menu, rpg_t *game);
sfRectangleShape* create_rectangle_shape(sfVector2f size,
    sfVector2f position);
int is_within_collision_radius(float dx, float dy,
    sfFloatRect playerBounds, sfVector2f collPos);
int check_collision(sfFloatRect playerBounds, sfVector2f collPos);
void display_menu_escape(rpg_t *game, escape_menu_t *menu);
// pnj.c
void manage_display_pnjs(rpg_t *game);
// manage_diaogue_display.c
void manage_dialogue_display(rpg_t *rpg);

// display_item_animation.c
void display_item_animation(rpg_t *game);
/// --- EVENT --- ///
// manager.c
void manager_event(rpg_t *game);
void manage_click_menu(rpg_t *game);
// loading_screen.c
void loadin_screen(menu_t *menu, rpg_t *game);
void display_loading_screen(menu_t *menu, rpg_t *game);
// update_mouvement_ped.c
void update_position(enum player_move move, rpg_t *game, int speed);
// main_menu.c
sfFloatRect *get_compenant(rpg_t *game);
void update_display_princiapl_volume(rpg_t *game);
void update_display_music_volume(rpg_t *game);
void update_display_effect_volume(rpg_t *game);
// update_down_volume.c | update_up_volume
void up_volume_principal(rpg_t *game, bool display_update);
void down_volume_principal(rpg_t *game, bool display_update);
void up_volume_music(rpg_t *game, bool display_update);
void down_volume_music(rpg_t *game, bool display_update);
void up_volume_effect(rpg_t *game, bool display_update);
void down_volume_effect(rpg_t *game, bool display_update);
// main_menu_hover.c
void manage_hover_button(rpg_t *game);
void manage_hover_button_escape(rpg_t *game);
// main_menu_click.c
void manage_click(rpg_t *game);
void manage_click_settings(sfVector2f mouse_pos, rpg_t *game);
void manage_click_menu_escape(rpg_t *game);
// get_dialogue.c
void get_dialogue(rpg_t *rpg, int id);

/// --- PARSING --- ///
int **open_coll_file_as_ints(char *filepath);
void init_parsing(parsing_t *parsing);
int manage_collisions(parsing_t *parsing, rpg_t *game);

/// --- INTERACTION --- ///
void init_interaction(interaction_t *door);

// --- SAVE --- ///
void choose_save(rpg_t *game, int save);
void save_data(rpg_t *game, int save);

/// --- QUEST --- ///
void init_quests(quest_t *quests);
void display_quest_completed(rpg_t *game);
void display_quests(rpg_t *game);
void progress_quests(rpg_t *game);

/// --- INVENTORY --- ///
void init_inventory(inventory_t *inventory);
void init_items_animation(items_anim_t *items_anim);
void create_animation_item(rpg_t *game, char *name);
void init_items(items_t *items);
void give_item_in_inventory(rpg_t *game, char *name);
void manage_inventory(rpg_t *game);
bool have_item_in_inventory(rpg_t *game, char *name);
void remove_item_in_inventory(rpg_t *game, char *name);
void change_inventory(rpg_t *game);
// --- BOSS --- ///
void init_boss(boss_t *boss, rpg_t *game);
void destroy_boss(boss_t *boss, rpg_t *game);
void manage_boss(rpg_t *game);
void display_boss(rpg_t *game);
void update_boss_animation(boss_sprite_t *sprite);
void init_speech(rpg_t *game);
void update_boss_animation_pl(boss_player_t *sprite);
void sp_of_player_boss(boss_t *boss);
void sp_of_boss(boss_t *boss);
void sp_and_text_boss(boss_t *boss);
void manage_boss_sprite(rpg_t *game);
void manage_boss_pl_sprite(rpg_t *game);
void sp_and_text_fight(boss_t *boss);
void sp_and_text_fight(boss_t *boss);
void handle_buttons_and_text(rpg_t *game);
void life_bar_animation_pl(boss_t *boss, rpg_t *game);
void life_bar_animation(boss_t *boss, rpg_t *game);
/// --- DEATH --- ///
void handle_death(rpg_t *game, player_t *player);

/// --- VIEW --- ///
void set_view_center(sfView *view, map_info_t *map_info);

/// --- COLLISION --- ///
int manage_collisions(parsing_t *parsing, rpg_t *game);

/// --- DIALOGUE --- ///
void set_string_to_text(sfText *text, const char *string);
