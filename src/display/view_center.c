/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** view_center
*/

#include "my_rpg.h"


void set_view_center(sfView *view, map_info_t *map_info)
{
    if (map_info->view_x - map_info->window_size.x / 2 < 25)
        map_info->view_x = 25 + map_info->window_size.x / 2;
    if (map_info->view_x + map_info->window_size.x / 2 > map_info->map_width)
        map_info->view_x = map_info->map_width - map_info->window_size.x / 2;
    if (map_info->view_y - map_info->window_size.y / 2 < 0)
        map_info->view_y = map_info->window_size.y / 2;
    if (map_info->view_y + map_info->window_size.y / 2 > map_info->map_height)
        map_info->view_y = map_info->map_height - map_info->window_size.y / 2;
    sfView_setCenter(view, (sfVector2f){map_info->view_x, map_info->view_y});
}
