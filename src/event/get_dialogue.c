/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** manager
*/

#include "my_rpg.h"

dialogue_t *choose_list_dialogue(rpg_t *rpg, int id)
{
    dialogue_t *tmp = rpg->dialogue;
    int i = 0;

    while (tmp != NULL) {
        if (i == id)
            return tmp;
        i++;
        tmp = tmp->next;
    }
    return tmp;
}

void get_dialogue(rpg_t *rpg, int id)
{
    rpg->actual_dialogue = choose_list_dialogue(rpg, id);
    if (rpg->actual_dialogue == NULL)
        return;
    rpg->actual_dialogue->activ = true;
    sfClock_restart(rpg->actual_dialogue->clock);
}
