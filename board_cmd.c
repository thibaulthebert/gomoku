/*
** EPITECH PROJECT, 2018
** Gomokou
** File description:
** Handling the begin cmd, setting the map up
*/

#include <string.h>
#include <stdlib.h>
#include "gomoku.h"

char **set_map()
{
    char **map = NULL;

    if ((map = malloc(sizeof(char *) * 20)) == NULL)
        exit(84);
    for (int i = 0; i < 19; i++) {
        if ((map[i] = malloc(sizeof(char) * 20)) == NULL)
            exit(84);
        memset(map[i], ' ', 19);
        map[i][19] = 0;
    }
    map[19] = NULL;
    return (map);
}

void add_played_move(char **map, char *line)
{
    char *split = strtok(line, ",");
    int x = atoi(split);
    split = strtok(NULL, ",");
    int y = atoi(split);
    split = strtok(NULL, ",");
    map[y][x] = split[0];
}

void recover_map(char **map)
{
    char *line = NULL;

    while (line && strcmp(line, "DONE\n") != 0) {
        add_played_move(map, line);
        free(line);
        line = NULL;
        line = get_server_command();
    }
}

int board_cmd(game_t *game, char *cmd)
{
    (void)cmd;
    if (game->map)
        free_map(game->map);
    game->map = set_map();
    recover_map(game->map);
    gomoku(game);
    return (SUCCESS_CMD);
}

int start_cmd(game_t *game, char *cmd)
{
    if (game->map) {
        free_map(game->map);
        return (END_GAME);
    }
    if (cmd && strcmp(cmd, "START 19\n") == 0) {
        game->map = set_map();
        my_putstr("OK\n");
    } else {
        my_putstr("ERROR Invalid size\n");
    }
    return (SUCCESS_CMD);
}
