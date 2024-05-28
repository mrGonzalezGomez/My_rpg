/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** colission
*/

#include "my_rpg.h"

int manage_collisions(parsing_t *parsing, rpg_t *game)
{
    sfRectangleShape* playerPoint =
        create_rectangle_shape((sfVector2f){40, 40},
        (sfVector2f){game->player->pos.x + 13, game->player->pos.y + 30});
    sfFloatRect playerBounds = sfRectangleShape_getGlobalBounds(playerPoint);
    float dx;
    float dy;

    for (int i = 0; parsing->coll_file[i] != NULL; i++) {
        dx = fabs(parsing->coll_file[i][0] - game->player->pos.x);
        dy = fabs(parsing->coll_file[i][1] - game->player->pos.y);
        if (is_within_collision_radius(dx, dy, playerBounds,
            (sfVector2f){parsing->coll_file[i][0],
            parsing->coll_file[i][1]})) {
            return 1;
        }
    }
    return 0;
}
