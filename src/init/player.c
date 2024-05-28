/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** player
*/

#include "my_rpg.h"

static player_sprites_t *create_sprite(char *filepath)
{
    player_sprites_t *sprite = malloc(sizeof(player_sprites_t));

    sprite->texture = sfTexture_createFromFile(filepath, NULL);
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sprite->rect = (sfIntRect){0, 0, 76.4, 76};
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return sprite;
}

void init_player(rpg_t *game, player_t *player)
{
    player->type = KN_SH_1;
    player->move = NONE;
    player->kn_btt_sprite = create_sprite(KN_SHEET_BATT);
    player->kn_sh_1__sprite = create_sprite(KN_SHEET_1);
    player->kn_sh_2__sprite = create_sprite(KN_SHEET_2);
    player->kn_sh_3__sprite = create_sprite(KN_SHEET_3);
    player->clock = create_clock();
    player->pos = (sfVector2f){5200, 3900};
    player->speed = 2;
    player->clock_speed_spite = 0.5;
    game->show_death_screen = false;
    player->is_alive = true;
    handle_death(game, player);
}
