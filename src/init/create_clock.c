/*
** EPITECH PROJECT, 2024
** GAME-RPG [WSL: Ubuntu-22.04]
** File description:
** create_clock
*/

#include "my_rpg.h"

clock_data_t *create_clock(void)
{
    clock_data_t *clock = malloc(sizeof(clock_data_t));

    clock->clock = sfClock_create();
    clock->time = sfClock_getElapsedTime(clock->clock);
    return clock;
}
