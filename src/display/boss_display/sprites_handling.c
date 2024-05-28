/*
** EPITECH PROJECT, 2023
** GAME-RPG
** File description:
** sprites_handling.c
*/

#include "my_rpg.h"

void update_boss_animation(boss_sprite_t *sprite)
{
    sfTime time = sfClock_getElapsedTime(sprite->animation_clock);
    float seconds = sfTime_asSeconds(time);

    if (seconds > 0.1) {
        sprite->current_frame = (sprite->current_frame + 1)
            % sprite->num_frames;
        if (sprite->current_frame == 0) {
            sprite->current_cycle++;
        }
        if (sprite->current_cycle < sprite->max_cycles) {
            sprite->rect.left = sprite->current_frame * sprite->frame_width;
            sfSprite_setTextureRect(sprite->sprite, sprite->rect);
        } else
            sprite->animation_finished = true;
        sfClock_restart(sprite->animation_clock);
    }
}

void update_boss_animation_pl(boss_player_t *sprite)
{
    sfTime time = sfClock_getElapsedTime(sprite->animation_clock);
    float seconds = sfTime_asSeconds(time);

    if (seconds > 0.1) {
        sprite->current_frame = (sprite->current_frame + 1)
            % sprite->num_frames;
        if (sprite->current_frame == 0) {
            sprite->current_cycle++;
        }
        if (sprite->current_cycle < sprite->max_cycles) {
            sprite->rect.left = sprite->current_frame * sprite->frame_width;
            sfSprite_setTextureRect(sprite->sprite, sprite->rect);
        } else
            sprite->animation_finished = true;
        sfClock_restart(sprite->animation_clock);
    }
}
