/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** quests
*/

#include "my_rpg.h"

static bool first_quest_completed(rpg_t *game, quest_t *quest)
{
    if (quest->state == IS_ACTIVE) {
        if (game->player->move == UP) {
            quest->state = IS_COMPLETED;
            return true;
        } else {
            return false;
        }
    }
    return false;
}

static bool second_quest_completed(rpg_t *game, quest_t *quest)
{
    if (quest->state == IS_ACTIVE) {
        if (game->player->move == DOWN) {
            quest->state = IS_COMPLETED;
            return true;
        } else {
            return false;
        }
    }
    return false;
}

static bool third_quest_completed(rpg_t *game, quest_t *quest)
{
    if (quest->state == IS_ACTIVE) {
        if (game->player->move >= 9) {
            quest->state = IS_COMPLETED;
            return true;
        } else {
            return false;
        }
    }
    return false;
}

static bool fourth_quest_completed(rpg_t *game, quest_t *quest)
{
    if (quest->state == IS_ACTIVE) {
        if (game->interaction->is_active[0] &&
            game->interaction->is_interacting) {
            get_dialogue(game, 1);
            quest->state = IS_COMPLETED;
            game->quests->display_completed = true;
            return true;
        } else {
            return false;
        }
    }
    return false;
}

static bool fifth_quest_completed(rpg_t *game, quest_t *quest)
{
    if (quest->state == IS_ACTIVE) {
        if (game->interaction->is_active[3] &&
            game->interaction->is_interacting) {
            get_dialogue(game, 2);
            quest->state = IS_COMPLETED;
            return true;
        } else {
            return false;
        }
    }
    return false;
}

static bool sixth_quest_completed(rpg_t *game, quest_t *quest)
{
    if (quest->state == IS_ACTIVE) {
        if (game->interaction->is_active[1] &&
            game->interaction->is_interacting) {
            get_dialogue(game, 0);
            quest->state = IS_COMPLETED;
            return true;
        } else {
            return false;
        }
    }
    return false;
}

static bool seventh_quest_completed(rpg_t *game, quest_t *quest)
{
    if (quest->state == IS_ACTIVE) {
        if (game->interaction->is_active[2] &&
            game->interaction->is_interacting) {
                give_item_in_inventory(game, "Sword");
            quest->state = IS_COMPLETED;
            return true;
        } else {
            return false;
        }
    }
    return false;
}

static bool eighth_quest_completed(rpg_t *game, quest_t *quest)
{
    if (quest->state == IS_ACTIVE) {
        if (game->interaction->is_active[5] &&
            game->interaction->is_interacting) {
            give_item_in_inventory(game, "Shield_2");
            quest->state = IS_COMPLETED;
            return true;
        } else {
            return false;
        }
    }
    return false;
}

static bool ninth_quest_completed(rpg_t *game, quest_t *quest)
{
    if (quest->state == IS_ACTIVE) {
        if (game->interaction->is_active[6] &&
            game->interaction->is_interacting && 
            have_item_in_inventory(game, "Sword")) {
            remove_item_in_inventory(game, "Sword");
            give_item_in_inventory(game, "Sword_2");
            quest->state = IS_COMPLETED;
            return true;
        } else {
            return false;
        }
    }
    return false;
}

static bool tenth_quest_completed(rpg_t *game, quest_t *quest)
{
    if (quest->state == IS_ACTIVE) {
        if (game->interaction->is_active[6] &&
            game->interaction->is_interacting &&
            have_item_in_inventory(game, "Shield_2")) {
            remove_item_in_inventory(game, "Shield_2");
            give_item_in_inventory(game, "Shield");
            quest->state = IS_COMPLETED;
            return true;
        } else {
            return false;
        }
    }
    return false;
}

static bool eleventh_quest_completed(rpg_t *game, quest_t *quest)
{
    if (game->boss->is_dead) {
        quest->state = IS_COMPLETED;
        return true;
    } else {
        return false;
    }
    return false;
}

bool quest_is_completed(rpg_t *game, quest_t *quest)
{
    if (quest->id == 1)
        return first_quest_completed(game, quest);
    if (quest->id == 2)
        return second_quest_completed(game, quest);
    if (quest->id == 3)
        return third_quest_completed(game, quest);
    if (quest->id == 4 && game->interaction->is_interacting)
        return fourth_quest_completed(game, quest);
    if (quest->id == 5 && game->interaction->is_interacting)
        return fifth_quest_completed(game, quest);
    if (quest->id == 6 && game->interaction->is_interacting)
        return sixth_quest_completed(game, quest);
    if (quest->id == 7 && game->interaction->is_interacting)
        return seventh_quest_completed(game, quest);
    if (quest->id == 8 && game->interaction->is_interacting)
        return eighth_quest_completed(game, quest);
    if (quest->id == 9 && game->interaction->is_interacting)
        return ninth_quest_completed(game, quest);
    if (quest->id == 10 && game->interaction->is_interacting)
        return tenth_quest_completed(game, quest);
    if (quest->id == 11 && game->interaction->is_interacting)
        return eleventh_quest_completed(game, quest);
    return false;
}

bool progress_quests_2(rpg_t *game, quest_t *current_quest)
{
    if (current_quest->state == IS_ACTIVE) {
        if (quest_is_completed(game, current_quest)
            && current_quest->next != NULL) {
            current_quest->next->state = IS_ACTIVE;
        }
        return true;
    }
    return false;
}

void progress_quests(rpg_t *game)
{
    quest_t *current_quest = game->quests;
    while (current_quest != NULL) {
        if (progress_quests_2(game, current_quest))
            break;
        current_quest = current_quest->next;
    }
}
