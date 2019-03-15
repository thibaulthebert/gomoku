/*
** EPITECH PROJECT, 2018
** Gomoku
** File description:
** Main project file
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "gomoku.h"

int handle_command(game_t *game, char *line)
{
    int i = 0;
    int ret = 0;

    while ((CMD_TAB[i]).cmd && strncmp(line, (CMD_TAB[i]).cmd, strlen((CMD_TAB[i]).cmd)) != 0)
        i++;
    if (!(CMD_TAB[i]).cmd)
        return (END_GAME);
    ret = (CMD_TAB[i]).handler(game, line);
    return (ret);
}

int handle_connection(game_t *game)
{
    char *line = malloc(1);
    int ret = SUCCESS_CMD;

    while (line && ret == SUCCESS_CMD) {
        free(line);
        line = NULL;
        line = get_server_command();
        ret = handle_command(game, line);
    }
    return (0);
}

int main()
{
    game_t game;
    int ret = 0;

    game.map = NULL;
    game.x = 0;
    game.y = 0;
    ret = handle_connection(&game);
    return (ret);
}