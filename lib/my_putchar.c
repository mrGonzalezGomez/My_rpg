/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** my_putchar.c
*/

#include "my_rpg.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
