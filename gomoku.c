/*
** EPITECH PROJECT, 2018
** Gomoku
** File description:
** Gomoku algorithm main file
*/

#include "gomoku.h"

void play_stroke(game_t *game)
{
    if ((game->map)[game->x][game->y] == ' ') {
        my_putnbr(game->y);
        my_putchar(',');
        my_putnbr(game->x);
        my_putchar('\n');
        (game->map)[game->x][game->y] = 'X';
    } else {
        for (int i = 0; (game->map)[i]; i++) {
            for (int j = 0; (game->map)[i][j]; j++) {
                if ((game->map)[i][j] == ' ') {
                    my_putnbr(j);
                    my_putchar(',');
                    my_putnbr(i);
                    my_putchar('\n');
                    (game->map)[i][j] = 'X';
                    return ;
                }
            }
        }
    }
}

void find_position(game_t *game)
{
    int better_stroke = 0;
    int tmp_stroke = 0;

    for (int x = 0; (game->map)[x]; x++) {
        for (int y = 0; (game->map)[x][y]; y++) {
            tmp_stroke = (game->map)[x][y] == ' ' ? evaluate_stroke(game, x, y) : tmp_stroke;
            if (tmp_stroke > better_stroke) {
                game->x = x;
                game->y = y;
                better_stroke = tmp_stroke;
            }
        }
    }
}

void gomoku(game_t *game)
{
    find_position(game);
    play_stroke(game);
    game->x = 0;
    game->y = 0;
}