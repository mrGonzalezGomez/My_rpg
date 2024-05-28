/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** my_putstr.c
*/

#include "my_rpg.h"

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
