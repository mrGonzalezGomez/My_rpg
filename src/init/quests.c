/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** player
*/

#include "my_rpg.h"

static void create_quest(quest_t *quests, char *name, char *description, int id)
{
    quests->name = name;
    quests->description = description;
    quests->state = IS_NOT_ACTIVE;
    quests->id = id;
    quests->next = malloc(sizeof(quest_t));
}

void init_quests(quest_t *quests)
{
    quests->display_completed = false;
    create_quest(quests, "Walk Up", "Read the note in the south of the village", 1);
    quests->state = IS_ACTIVE;
    create_quest(quests->next, "Walk Down", "Find the shield in the forest", 2);
    create_quest(quests->next->next, "Run 10 steps", "Run 10 steps", 3);
    create_quest(quests->next->next->next, "Talk to the King", "Talk to the King close to you", 4);
    create_quest(quests->next->next->next->next, "Read The Note", "Read the note in the south of the village", 5);
    create_quest(quests->next->next->next->next->next, "Talk to the Archer", "Talk to the Archer in the yellow forest", 6);
    create_quest(quests->next->next->next->next->next->next, "Pick up the sword", "Pick up the sword in the little castle", 7);
    create_quest(quests->next->next->next->next->next->next->next, "Pick up the shield", "Pick up the shield in the labyrinth", 8);
    create_quest(quests->next->next->next->next->next->next->next->next, "Repare your Sword", "Repare your Sword in the blacksmith", 9);
    create_quest(quests->next->next->next->next->next->next->next->next->next, "Repare Your Shield", "Repare your shield in the blacksmith", 10);
    create_quest(quests->next->next->next->next->next->next->next->next->next->next, "Kill the boss", "Kill the boss in the big black castle", 11);
    quests->next->next->next->next->next->next->next->next->next->next->next = NULL;
}