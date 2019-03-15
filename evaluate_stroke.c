/*
** EPITECH PROJECT, 2018
** Gomoku
** File description:
** Stroke evaluation function
*/

#include "gomoku.h"

int eval_diagonal_lr(game_t *game, int x, int y)
{
    char line[10] = "";
    int i = 0;
    int tmp_x = x - 4;
    int tmp_y = y - 4;

    while ((tmp_x <= x + 4) && (tmp_y <= y + 4)) {
        if (tmp_x < 0 || tmp_y < 0 || tmp_x > 18 || tmp_y > 18)
            line[i] = 'W';
        else
            line[i] = (game->map)[tmp_x][tmp_y];
        i++;
        tmp_x++;
        tmp_y++;
    }
    line[i] = '\0';
    return (eval_line(line));
}

int eval_diagonal_rl(game_t *game, int x, int y)
{
    char line[10] = "";
    int i = 0;
    int tmp_x = x + 4;
    int tmp_y = y - 4;

    while ((tmp_x >= x - 4) && (tmp_y <= y + 4)) {
        if (tmp_x < 0 || tmp_y < 0 || tmp_x > 18 || tmp_y > 18)
            line[i] = 'W';
        else
            line[i] = (game->map)[tmp_x][tmp_y];
        i++;
        tmp_x--;
        tmp_y++;
    }

    line[i] = '\0';
    return (eval_line(line));
}

int eval_horizontal(game_t *game, int x, int y)
{
    char line[10] = "";
    int i = 0;

    for (int tmp_y = y - 4; tmp_y <= y + 4; tmp_y++)
        line[i++] = (tmp_y < 0 || tmp_y > 18 ? 'W' : (game->map)[x][tmp_y]);
    line[i] = '\0';
    if (x == 7 && y == 9)
        (void)i;
    return (eval_line(line));
}

int eval_vertical(game_t *game, int x, int y)
{
    char line[10] = "";
    int i = 0;

    for (int tmp_x = x - 4; tmp_x <= x + 4; tmp_x++)
        line[i++] = (tmp_x < 0 || tmp_x > 18 ? 'W' : (game->map)[tmp_x][y]);
    line[i] = '\0';
    return (eval_line(line));
}

int evaluate_stroke(game_t *game, int x, int y)
{
    int val = 0;
    int tmp_val = 0;

    for (int i = 0; i < 4; i++) {
           tmp_val = EVAL_TAB[i](game, x, y);
           val = (tmp_val > val ? tmp_val : val);
    }
    return (val);
}
