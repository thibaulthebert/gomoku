/*
** EPITECH PROJECT, 2018
** Gomoku
** File description:
** Global variables instantiation
*/

#include <stdlib.h>
#include "gomoku.h"

const cmd_t CMD_TAB[] = {
    {"BEGIN", &begin_cmd}, {"TURN", &turn_cmd},
    {"BOARD", &board_cmd}, {"INFO", &info_cmd},
    {"END", &end_cmd}, {"ABOUT", &about_cmd},
    {"START", &start_cmd}, {NULL, NULL}
};

const eval_t EVAL_TAB[] = {
    &eval_diagonal_lr, &eval_diagonal_rl, &eval_horizontal, &eval_vertical
};

const int A_WIN = 1000000001;
const int A_NEXT_WIN = 1000000;

const int E_WIN = 1000000000;
const int E_NEXT_WIN = 1000001;

const int NONE = 0;

const state_t STATE_TAB[] = {
    {"* OO O **\0", 1000001},
    {" OOO  ***\0", 1000001},
    {" XXX  ***\0", 1000000},
    {"* XX X **\0", 1000000},
    {"* XX  **\0", 100000},
    {"**** XX**\0", 100},
    {"***X X***\0", 100},
    {"**** X***\0", 2},
    {"**** O***\0", 1},
    {"\0", 0}
};

const int SUCCESS_CMD = 0;
const int END_GAME = 1;

const int NO_WIN = 0;
const int WIN_P1 = 1;
const int WIN_P2 = 2;
const int DRAW = 3;
