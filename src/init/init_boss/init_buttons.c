/*
** EPITECH PROJECT, 2023
** GAME-RPG
** File description:
** init_buttons.c
*/

#include "my_rpg.h"

static fight_sprite_t *create_button(sfVector2f pos,
    char *str, char *path, sfFont *font)
{
    fight_sprite_t *button = malloc(sizeof(fight_sprite_t));
    sfVector2f text_pos;
    sfFloatRect sprite_bounds;
    sfFloatRect text_bounds;

    button->texture = sfTexture_createFromFile(path, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setPosition(button->sprite, pos);
    sfSprite_setScale(button->sprite, (sfVector2f){0.2, 0.2});
    button->text = sfText_create();
    set_string_to_text(button->text, str);
    sfText_setCharacterSize(button->text, 30);
    sfText_setFont(button->text, font);
    sprite_bounds = sfSprite_getGlobalBounds(button->sprite);
    text_bounds = sfText_getGlobalBounds(button->text);
    text_pos = (sfVector2f){pos.x + (sprite_bounds.width / 2) -
		(text_bounds.width / 2), pos.y + sprite_bounds.height};
    sfText_setPosition(button->text, text_pos);
    return button;
}

void sp_and_text_fight(boss_t *boss)
{
    sfFont *font = sfFont_createFromFile(FONT_PATH);

	boss->defend_button = create_button((sfVector2f){boss->pos.x
        + 840, boss->pos.y + 100},
		"Protection", "assets/boss/protect_but.png", font);
	boss->attack_button = create_button((sfVector2f){boss->pos.x
        + 1040, boss->pos.y + 100},
		"Attack", "assets/boss/attack_but.png", font);
	boss->heal_button = create_button((sfVector2f){boss->pos.x
        + 640, boss->pos.y + 100},
		"Heal", "assets/boss/heal.png", font);
	boss->run_button = create_button((sfVector2f){boss->pos.x
        + 1240, boss->pos.y + 100},
		"Run", "assets/boss/run.png", font);
}
