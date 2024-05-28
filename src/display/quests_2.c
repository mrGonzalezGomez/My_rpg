/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** manager
*/

#include "my_rpg.h"

void display_quest_completed_3(rpg_t *game, sfSprite *sprite, sfColor color,
    float elapsed)
{
    sfSprite_setColor(sprite, color);
    sfRenderWindow_drawSprite(game->window_data->window, sprite, NULL);
    if (elapsed >= 6.0)
        game->quests->display_completed = false;
}

sfColor get_color_quest_from_time(float elapsed)
{
    sfColor new_color;
    int opacity;

    if (elapsed < 3.0) {
        opacity = elapsed / 3.0 * 255;
    } else
        opacity = (6.0 - elapsed) / 1.5 * 255;
    if (opacity < 0)
        opacity = 0;
    if (opacity > 255)
        opacity = 255;
    new_color = (sfColor){255, 255, 255, opacity};
    return new_color;
}

void display_quest_completed_2(rpg_t *game, float elapsed)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(PATH_QUEST_COMPLETE, NULL);
    sfVector2f scale = {1.5, 1.5};
    sfVector2f pos = {game->map->map_info->view_x - 615,
        (game->map->map_info->view_y - 173.25) - 400};
    sfColor color;

    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    color = get_color_quest_from_time(elapsed);
    display_quest_completed_3(game, sprite, color, elapsed);
}

void display_quest_completed(rpg_t *game)
{
    static sfClock *clock = NULL;
    static sfTime time = {0};
    static float elapsed = 0;

    if (game->quests->display_completed) {
        if (!clock) {
            clock = sfClock_create();
        } else {
            time = sfClock_getElapsedTime(clock);
            elapsed = sfTime_asSeconds(time);
        }
    } else {
        if (clock) {
            sfClock_destroy(clock);
            clock = NULL;
            elapsed = 0;
        }
        return;
    }
    display_quest_completed_2(game, elapsed);
}
