/*
** EPITECH PROJECT, 2024
** GAME-RPG [WSL: Ubuntu-22.04]
** File description:
** death
*/

#include "my_rpg.h"

static void play_death_music(sfMusic **music)
{
    *music = sfMusic_createFromFile(DEATH_MUSIC);
    sfMusic_play(*music);
}

static void create_death_screen_elements(death_t *elements)
{
    elements->darken = sfRectangleShape_create();
    elements->text = sfText_create();
    elements->font = sfFont_createFromFile(DEATH_FONT);
    sfText_setFont(elements->text, elements->font);
    sfRectangleShape_setSize(elements->darken, (sfVector2f){10000, 10000});
    sfRectangleShape_setFillColor(elements->darken, (sfColor){139, 0, 0, 0});
    set_string_to_text(elements->text, "YOU DIED");
    sfText_setCharacterSize(elements->text, 100);
    sfText_setColor(elements->text, (sfColor){255, 0, 0, 0});
}

void handle_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void update_alpha(int *alpha, death_t *elements)
{
    if (*alpha <= 255) {
        *alpha += 255 / (2 * 20);
        if (*alpha > 255)
            *alpha = 255;
        sfRectangleShape_setFillColor(elements->darken,
        (sfColor){0, 0, 0, *alpha / 2});
        sfText_setColor(elements->text, (sfColor){255, 0, 0, *alpha});
    }
}

void render_death_screen(rpg_t *game, death_t *elements)
{
    sfVector2f pos = {game->map->map_info->view_x - 225,
    game->map->map_info->view_y - 25};

    sfRenderWindow_clear(game->window_data->window, sfBlack);
    manager_display(game);
    sfText_setPosition(elements->text, pos);
    sfRenderWindow_drawRectangleShape(game->window_data->window,
    elements->darken, NULL);
    sfRenderWindow_drawText(game->window_data->window, elements->text, NULL);
    sfRenderWindow_display(game->window_data->window);
}

static void cleanup_death_screen(death_t *elements)
{
    sfRectangleShape_destroy(elements->darken);
    sfText_destroy(elements->text);
    sfFont_destroy(elements->font);
    sfMusic_stop(elements->music);
    sfMusic_destroy(elements->music);
}

static int check_music_status(sfMusic *music)
{
    return sfMusic_getStatus(music) != sfPlaying;
}

static void process_death_screen(rpg_t *game, death_t *elements, int *alpha)
{
    while (game->show_death_screen) {
        handle_events(game->window_data->window);
        update_alpha(alpha, elements);
        render_death_screen(game, elements);
        if (check_music_status(elements->music)) {
            game->show_death_screen = false;
        }
        sfSleep(sfMilliseconds(50));
    }
}

void handle_death(rpg_t *game, player_t *player)
{
    int alpha = 0;
    death_t elements;

    if (!player->is_alive) {
        game->show_death_screen = true;
        play_death_music(&elements.music);
        create_death_screen_elements(&elements);
        process_death_screen(game, &elements, &alpha);
        cleanup_death_screen(&elements);
        game->show_death_screen = false;
        game->player->pos = (sfVector2f){680, 8754};
        exit(0);
    }
}
