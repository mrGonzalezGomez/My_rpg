/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** update_mouvement_ped
*/

#include "my_rpg.h"

static int is_up_mouvement(enum player_move move,
    rpg_t *game, int speed)
{
    if (move == UP) {
        game->player->pos.y -= 1 * speed;
        return 1;
    }
    if (move == UP_LEFT) {
        game->player->pos.y -= 1 * speed;
        game->player->pos.x -= 1 * speed;
        return 1;
    }
    if (move == UP_RIGHT) {
        game->player->pos.y -= 1 * speed;
        game->player->pos.x += 1 * speed;
        return 1;
    }
    return 0;
}

static int is_down_mouvement(enum player_move move,
    rpg_t *game, int speed)
{
    if (move == DOWN) {
        game->player->pos.y += 1 * speed;
        return 1;
    }
    if (move == DOWN_LEFT) {
        game->player->pos.y += 1 * speed;
        game->player->pos.x -= 1 * speed;
        return 1;
    }
    if (move == DOWN_RIGHT) {
        game->player->pos.y += 1 * speed;
        game->player->pos.x += 1 * speed;
        return 1;
    }
    return 0;
}

static int is_up_speed_mouvement(enum player_move move,
    rpg_t *game, int speed)
{
    if (move == SPEED_UP) {
        game->player->pos.y -= 4 * speed;
        return 1;
    }
    if (move == SPEED_UP_LEFT) {
        game->player->pos.y -= 4 * speed;
        game->player->pos.x -= 4 * speed;
        return 1;
    }
    if (move == SPEED_UP_RIGHT) {
        game->player->pos.y -= 4 * speed;
        game->player->pos.x += 4 * speed;
        return 1;
    }
    return 0;
}

static int is_down_speed_mouvement(enum player_move move,
    rpg_t *game, int speed)
{
    if (move == SPEED_DOWN) {
        game->player->pos.y += 4 * speed;
        return 1;
    }
    if (move == SPEED_DOWN_LEFT) {
        game->player->pos.y += 4 * speed;
        game->player->pos.x -= 4 * speed;
        return 1;
    }
    if (move == SPEED_DOWN_RIGHT) {
        game->player->pos.y += 4 * speed;
        game->player->pos.x += 4 * speed;
        return 1;
    }
    return 0;
}

static int is_basic_mouvement(enum player_move move,
    rpg_t *game, int speed)
{
    if (move == LEFT) {
        game->player->pos.x -= 1 * speed;
        return 1;
    }
    if (move == RIGHT) {
        game->player->pos.x += 1 * speed;
        return 1;
    }
    if (move == SPEED_LEFT) {
        game->player->pos.x -= 4 * speed;
        return 1;
    }
    if (move == SPEED_RIGHT) {
        game->player->pos.x += 4 * speed;
        return 1;
    }
    return 0;
}

static void call_management(rpg_t *game, sfVector2f originalPosition)
{
    if (game->in_boss == false && game->collision)
        if (manage_collisions(game->map->parsing, game))
            game->player->pos = originalPosition;
}

void update_position(enum player_move move, rpg_t *game, int speed)
{
    sfVector2f originalPosition = game->player->pos;

    if (game->in_boss == false)
        if (is_basic_mouvement(move, game, speed) ||
            is_up_mouvement(move, game, speed) ||
            is_down_mouvement(move, game, speed) ||
            is_up_speed_mouvement(move, game, speed) ||
            is_down_speed_mouvement(move, game, speed)) {
            call_management(game, originalPosition);
            return;
    }
}
