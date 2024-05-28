/*
** EPITECH PROJECT, 2023
** GAME-RPG
** File description:
** manager_bis.c
*/

#include "my_rpg.h"

sfRectangleShape* create_rectangle_shape(sfVector2f size,
    sfVector2f position)
{
    sfRectangleShape* shape = sfRectangleShape_create();

    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setPosition(shape, position);
    return shape;
}

int check_collision(sfFloatRect playerBounds, sfVector2f collPos)
{
    sfRectangleShape* collisionArea =
        create_rectangle_shape((sfVector2f){48.0f, 48.0f}, collPos);
    sfFloatRect collisionBounds =
        sfRectangleShape_getGlobalBounds(collisionArea);
    int result = sfFloatRect_intersects(&playerBounds, &collisionBounds, NULL);

    sfRectangleShape_destroy(collisionArea);
    return result;
}

int is_within_collision_radius(float dx, float dy,
    sfFloatRect playerBounds, sfVector2f collPos)
{
    if (dx <= COLLISION_CHECK_RADIUS && dy <= COLLISION_CHECK_RADIUS)
        return check_collision(playerBounds, collPos);
    return 0;
}
