/*
** EPITECH PROJECT, 2023
** GAME-RPG
** File description:
** sprites.c
*/

#include "my_rpg.h"

void sp_and_text_boss(boss_t *boss)
{
    boss->background =
        sfTexture_createFromFile("assets/boss/boss_back.png", NULL);
    boss->back_sp = sfSprite_create();
    sfSprite_setTexture(boss->back_sp, boss->background, sfTrue);
    sfSprite_setPosition(boss->back_sp, boss->pos);
    boss->heart_text =
        sfTexture_createFromFile("assets/boss/heart.png", NULL);
    boss->life_bar_text =
        sfTexture_createFromFile("assets/boss/life_bar.png", NULL);
    for (int i = 0; i < 5; i++) {
        boss->life_bar_sp_pl[i] = sfSprite_create();
        boss->life_bar_sp[i] = sfSprite_create();
        sfSprite_setTexture(boss->life_bar_sp[i], boss->heart_text, sfTrue);
        sfSprite_setTexture(boss->life_bar_sp_pl[i], boss->heart_text, sfTrue);
        sfSprite_setPosition(boss->life_bar_sp_pl[i],
            (sfVector2f){950 + i * 20, 8700});
        sfSprite_setPosition(boss->life_bar_sp[i],
            (sfVector2f){2025 + i * 20, 8700});
    }
}

static boss_sprite_t *create_boss_sprite(char *filepath,
    int frame_width, int num_frames, int max_cycles)
{
    boss_sprite_t *sprite = malloc(sizeof(boss_sprite_t));

    sprite->texture = sfTexture_createFromFile(filepath, NULL);
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setPosition(sprite->sprite, (sfVector2f){1800, 8100});
    sfSprite_setScale(sprite->sprite, (sfVector2f){2, 2});
    sprite->rect = (sfIntRect){0, 0, frame_width, 307};
    sprite->width = frame_width;
    sprite->height = 307;
    sprite->frame_width = frame_width;
    sprite->num_frames = num_frames;
    sprite->current_frame = 0;
    sprite->animation_clock = sfClock_create();
    sprite->current_cycle = 0;
    sprite->max_cycles = max_cycles;
    sprite->animation_finished = false;
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return sprite;
}

void sp_of_boss(boss_t *boss)
{
    boss->idle = create_boss_sprite("assets/boss/idle.png", 315, 5, 1000);
    boss->attack = create_boss_sprite("assets/boss/attack.png", 315, 11, 1);
    boss->death = create_boss_sprite("assets/boss/death.png", 315, 8, 1);
    boss->hurt = create_boss_sprite("assets/boss/hit.png", 315, 6, 1);
    boss->in_combat = create_boss_sprite("assets/boss/fly.png", 315, 5, 1000);
}

static boss_player_t *create_pl_sprite(char *filepath,
    int frame_width, int num_frames, int max_cycles)
{
    boss_player_t *sprite = malloc(sizeof(boss_player_t));

    sprite->texture = sfTexture_createFromFile(filepath, NULL);
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setPosition(sprite->sprite, (sfVector2f){800, 8325});
    sfSprite_setScale(sprite->sprite, (sfVector2f){2, 2});
    sprite->rect = (sfIntRect){0, 0, frame_width, 214};
    sprite->width = frame_width;
    sprite->height = 214;
    sprite->frame_width = frame_width;
    sprite->num_frames = num_frames;
    sprite->current_frame = 0;
    sprite->animation_clock = sfClock_create();
    sprite->current_cycle = 0;
    sprite->max_cycles = max_cycles;
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return sprite;
}

void sp_of_player_boss(boss_t *boss)
{
    boss->idle_pl =
        create_pl_sprite("assets/boss/idle_pl.png", 214, 7, 1000);
    boss->attack_pl =
        create_pl_sprite("assets/boss/attack_pl.png", 214, 7, 1);
    boss->death_pl = create_pl_sprite("assets/boss/die_pl.png", 214, 7, 1);
    boss->protect = create_pl_sprite("assets/boss/protect.png", 214, 7, 1);
}
