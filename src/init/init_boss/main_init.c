/*
** EPITECH PROJECT, 2023
** GAME-RPG
** File description:
** main_init.c
*/

#include "my_rpg.h"

void init_boss(boss_t *boss, rpg_t *game)
{
    (void)game;
    boss->pos = (sfVector2f){525, 7975};
    sp_and_text_boss(boss);
    sp_of_boss(boss);
    sp_of_player_boss(boss);
    sp_and_text_fight(boss);
    boss->clock = create_clock();
    boss->attack_started_pl = false;
    boss->defend_started_pl = false;
    boss->attack_started = false;
    boss->hit_started = false;
    boss->hit_started_pl = false;
    boss->death_started_pl = false;
    boss->death_started = false;
    boss->is_dead = false;
    boss->is_dead_pl = false;
    boss->boss_life = 125;
    boss->boss_max_life = 125;
    boss->player_life = 125;
    boss->player_max_life = 125;
    boss->music = sfMusic_createFromFile("assets/music/boss.ogg");
}
