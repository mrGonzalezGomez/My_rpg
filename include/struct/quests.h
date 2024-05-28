/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** main_menu
*/

#pragma once

#include "csfml_lib.h"
#include "utils.h"

//enum for the different buttons
enum quests {
    IS_ACTIVE,
    IS_COMPLETED,
    IS_NOT_ACTIVE
};

typedef struct quest_s {
    char *name;
    char *description;
    enum quests state;
    int id;
    bool display_completed;
    struct quest_s *next;
} quest_t;
