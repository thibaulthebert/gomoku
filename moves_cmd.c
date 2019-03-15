/*
** EPITECH PROJECT, 2018
** Gomoku
** File description:
** Commands leading to moves
*/

#include <stdlib.h>
#include "gomoku.h"

int begin_cmd(game_t *game, char *cmd)
{
    (void)game;
    (void)cmd;
    my_putstr("9,9\n");
    (game->map)[9][9] = 'X';
    return (SUCCESS_CMD);
}

int turn_cmd(game_t *game, char *cmd)
{
    char *x_part = cmd + 5;
    char *y_part = cmd + 5;
    int x, y;
    for (; (*y_part) != ',' ; y_part++);
    *y_part = '\0';
    y_part++;
    x = atoi(x_part);
    y = atoi(y_part);
    *(y_part - 1) = ',';
    (game->map)[y][x] = 'O';
    gomoku(game);
    return (SUCCESS_CMD);
}