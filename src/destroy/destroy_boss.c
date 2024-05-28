/*
** EPITECH PROJECT, 2023
** GAME-RPG
** File description:
** destroy_boss.c
*/

#include "my_rpg.h"

static void destroy_boss_bis(boss_t *boss)
{
    if (boss->clock)
        free(boss->clock);
    if (boss->idle)
        free(boss->idle);
    if (boss->attack)
        free(boss->attack);
    if (boss->death)
        free(boss->death);
    if (boss->hurt)
        free(boss->hurt);
    if (boss->in_combat)
        free(boss->in_combat);
    if (boss->idle_pl)
        free(boss->idle_pl);
    if (boss->attack_pl)
        free(boss->attack_pl);
    if (boss->death_pl)
        free(boss->death_pl);
    if (boss->protect)
        free(boss->protect);
}

void destroy_boss(boss_t *boss, rpg_t *game)
{
    (void)game;
    if (boss == NULL)
        return;
    if (boss->background)
        sfTexture_destroy(boss->background);
    if (boss->back_sp)
        sfSprite_destroy(boss->back_sp);
    if (boss->life_bar_text)
        sfTexture_destroy(boss->life_bar_text);
    if (boss->heart_text)
        sfTexture_destroy(boss->heart_text);
    for (int i = 0; i < 5; i++)
        if (boss->life_bar_sp[i])
            sfSprite_destroy(boss->life_bar_sp[i]);
    destroy_boss_bis(boss);
    sfMusic_destroy(game->boss->music);
    free(boss);
}
