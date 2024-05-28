/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** manager
*/

#include "my_rpg.h"

void manage_alpha_item_animation(items_anim_t *anim,
    float seconds)
{
    if (seconds < 5.0) {
        anim->alpha = (int)(255 * (seconds / 5.0));
        if (anim->alpha > 255)
            anim->alpha = 255;
        return;
    }
    if (seconds < 10.0) {
        anim->alpha = 255;
        return;
    }
    if (seconds < 12.0) {
        anim->alpha = (int)(255 * (1.0 - ((seconds - 10.0) / 2.0)));
        if (anim->alpha < 0) {
            anim->alpha = 0;
        }
        return;
    }
    anim->is_anim = false;
    anim->alpha = 0;
}

float get_item_animation_y_position(sfVector2f view, float seconds)
{
    float start_y = view.y - 540 - 300;
    float end_y = view.y - 100;

    if (seconds < 5.0) {
        return start_y + (end_y - start_y) * (seconds / 5.0);
    } else {
        return end_y;
    }
}

void display_item_animation_elements(rpg_t *game, items_anim_t *anim)
{
    sfRenderWindow_drawSprite(game->window_data->window,
        anim->back_sprite, NULL);
    sfRenderWindow_drawSprite(game->window_data->window, anim->sprite, NULL);
    sfRenderWindow_drawText(game->window_data->window, anim->item_name, NULL);
    sfRenderWindow_drawText(game->window_data->window, anim->item_descr, NULL);
}

void update_position_item_animation(rpg_t *game, items_anim_t *anim,
    float seconds)
{
    sfVector2f view =
        (sfVector2f){game->map->map_info->view_x, game->map->map_info->view_y};
    float y_position = get_item_animation_y_position(view, seconds);
    float back_sprite_offset = 0;
    float sprite_offset = 75;
    float item_name_offset = 45;
    float item_descr_offset = 10;
    sfFloatRect name_bounds = sfText_getGlobalBounds(anim->item_name);
    sfFloatRect descr_bounds = sfText_getGlobalBounds(anim->item_descr);
    float item_name_x = view.x - (name_bounds.width / 2);
    float item_descr_x = view.x - (descr_bounds.width / 2);

    sfSprite_setPosition(anim->back_sprite,
        (sfVector2f){view.x, y_position + back_sprite_offset});
    sfSprite_setPosition(anim->sprite,
        (sfVector2f){view.x, y_position - sprite_offset});
    sfText_setPosition(anim->item_name,
        (sfVector2f){item_name_x, y_position - item_name_offset});
    sfText_setPosition(anim->item_descr,
        (sfVector2f){item_descr_x, y_position + item_descr_offset});
}

void display_item_animation(rpg_t *game)
{
    items_anim_t *anim = game->inventory->items_anim;
    sfTime time = sfClock_getElapsedTime(anim->clock);
    float seconds = sfTime_asSeconds(time);
    sfColor color = sfSprite_getColor(anim->sprite);

    manage_alpha_item_animation(anim, seconds);
    color.a = anim->alpha;
    sfSprite_setColor(anim->sprite, color);
    sfSprite_setColor(anim->back_sprite, color);
    sfText_setColor(anim->item_name, color);
    sfText_setColor(anim->item_descr, color);
    update_position_item_animation(game, anim, seconds);
    display_item_animation_elements(game, anim);
}
