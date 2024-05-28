/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** main.c
*/

#include "my_rpg.h"
#include <locale.h>

void set_string_to_text(sfText *text, const char *string)
{
    sfUint32 *unicode;
    size_t len = strlen(string);
    char buffer[512];

    if (len > 512)
        fprintf(stderr, "String too long\n");
    wchar_t ws[len + 1];
    strcpy(buffer, string);
    if (setlocale(LC_CTYPE, "") == NULL)
        perror("setlocale");
    mbstowcs(ws, buffer, len + 1);
    ws[len] = L'\0';
    unicode = (sfUint32 *)ws;
    sfText_setUnicodeString(text, unicode);
}

int main(int, char **)
{
    rpg_t *game = malloc(sizeof(rpg_t));

    mkdir("saves_file", 0777);
    init_struct(game);
    game->collision = true;
    game_loop(game);
    destroy(game);
    return 0;
}
