/*
** EPITECH PROJECT, 2018
** Gomoku
** File description:
** Evaluate a line to know if we need to play the stroke on this box
*/

#include <string.h>
#include <stdbool.h>
#include "gomoku.h"

static int check_game_ending(char line[10])
{
    int i = 3;
    int straight = 0;
    char ref;

    if (line[3] != 'X' && line[3] != 'O' && line[5] != 'X' && line[5] != 'O')
        return (NONE);
    ref = ((line[3] == 'X' || line[3] == 'O') ? line[3] : line[5]);
    while (i >= 0 && line[i] == ref) {
        straight++;
        i--;
    }
    i = 5;
    while (line[i] == ref) {
        straight++;
        i++;
    }
    if (straight >= 4)
        return (ref == 'X' ? A_WIN : E_WIN);
    return (NONE);
}

static bool compare_line(char line[10], const char ref[10])
{
    int i = 0;
    int j = 0;

    for (; line[i]; i++) {
        if (ref[i] != '*' && line[i] != ref[i])
            break ;
    }
    if (i == 9)
        return (true);
    i = 8;
    for (; i >= 0; i--) {
        if (ref[i] != '*' && line[j] != ref[i])
            break ;
        j++;
    }
    return (i == -1 ? true : false);
}

int eval_line(char line[10])
{
    bool adequacy = false;
    int ret = NONE;
    int tmp_ret = NONE;

    for (int i = 0; strlen(STATE_TAB[i].line) != 0; i++) {
        tmp_ret = check_game_ending(line);
        if (tmp_ret != NONE)
            return (tmp_ret);
        adequacy = compare_line(line, STATE_TAB[i].line);
        if (adequacy && STATE_TAB[i].value > ret)
            ret = STATE_TAB[i].value;
    }
    return (ret);
}