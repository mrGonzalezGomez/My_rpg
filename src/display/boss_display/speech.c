/*
** EPITECH PROJECT, 2023
** GAME-RPG
** File description:
** speech.c
*/

#include "my_rpg.h"

static void create_background(sfRectangleShape **background, rpg_t *game)
{
    *background = sfRectangleShape_create();
    sfRectangleShape_setFillColor(*background, sfBlack);
    sfRectangleShape_setSize(*background, (sfVector2f){1920, 1080});
    sfRectangleShape_setPosition(*background,
        (sfVector2f){game->boss->pos.x - 500, game->boss->pos.y + 239});
}

static void initialize_text(sfText **text, sfFont **font)
{
    *text = sfText_create();
    *font = sfFont_createFromFile(FONT_PATH);
    sfText_setFont(*text, *font);
    sfText_setCharacterSize(*text, 40);
    sfText_setFillColor(*text, sfWhite);
}

static float calculate_total_height(sfText *text, char **strs, size_t num_strs)
{
    float totalHeight = 0;
    sfFloatRect textRect;

    for (size_t i = 0; i < num_strs; i++) {
        set_string_to_text(text, strs[i]);
        textRect = sfText_getGlobalBounds(text);
        totalHeight += textRect.height + 10;
    }
    totalHeight -= 10;
    return totalHeight;
}

static float calculate_start_y(sfVector2f viewCenter,
    sfText *text, boss_t *boss)
{
    return viewCenter.y - (calculate_total_height(text, boss->speech, 3) / 2);
}

static void display_single_text(text_display_params_t *params)
{
    char str_tmp[256];
    sfFloatRect textRect;
    size_t length = strlen(params->str);

    memset(str_tmp, 0, sizeof(str_tmp));
    for (size_t j = 0; j < length; j++) {
        str_tmp[j] = params->str[j];
        set_string_to_text(params->text, str_tmp);
        textRect = sfText_getGlobalBounds(params->text);
        sfText_setPosition(params->text, (sfVector2f){params->position.x -
            (textRect.width / 2), params->position.y});
        sfRenderWindow_drawRectangleShape(params->window,
            params->background, NULL);
        sfRenderWindow_drawText(params->window, params->text, NULL);
        sfRenderWindow_display(params->window);
        sfSleep(sfMilliseconds(100));
    }
}

static void display_text_with_effect(sfRenderWindow *window, sfText *text,
    sfRectangleShape *background, boss_t *boss)
{
    const sfView *view = sfRenderWindow_getView(window);
    sfVector2f viewCenter = sfView_getCenter(view);
    float startY = calculate_start_y(viewCenter, text, boss);
    sfVector2f position = {viewCenter.x, startY};
    text_display_params_t params =
        { window, text, background, NULL, position };

    for (size_t i = 0; i < 3; i++) {
        params.str = boss->speech[i];
        display_single_text(&params);
        sfSleep(sfSeconds(1.5));
    }
}

void destroy_resources(sfRectangleShape *background,
    sfText *text, sfFont *font)
{
    sfRectangleShape_destroy(background);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void draw_text_with_background(rpg_t *game)
{
    sfRectangleShape *background;
    sfText *text;
    sfFont *font;

    create_background(&background, game);
    initialize_text(&text, &font);
    display_text_with_effect(game->window_data->window, text, background,
        game->boss);
    destroy_resources(background, text, font);
}

void init_speech(rpg_t *game)
{
    game->boss->speech = malloc(sizeof(char *) * 3);
    game->boss->speech[0] = "Welcome in my domain...";
    game->boss->speech[1] = "Prepare for the ultimate challenge.";
    game->boss->speech[2] = "May the best warrior win !";
    draw_text_with_background(game);
    sfMusic_play(game->boss->music);
    sfMusic_setLoop(game->boss->music, sfTrue);
    sfMusic_setVolume(game->boss->music,
        game->window_data->vol_principal * game->window_data->vol_music * 100);
    sfSleep(sfSeconds(4.9));
    free(game->boss->speech);
}
