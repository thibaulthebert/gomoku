/*
** EPITECH PROJECT, 2018
** Gomoku
** File description:
** Gomoku header
*/

#ifndef GOMOKU_H_
    #define GOMOKU_H_

    #include <stdio.h>

    typedef struct  game_s {
        char        **map;
        int         x;
        int         y;
    }               game_t;

    typedef int (*handle_t)(game_t *game, char *cmd);

    typedef int (*eval_t)(game_t *game, int x, int y);

    typedef struct  cmd_s {
        char        *cmd;
        handle_t    handler;
    }       		cmd_t;

    typedef struct  state_s {
        char        line[10];
        int         value;
    }               state_t;

    extern const cmd_t CMD_TAB[];
    extern const state_t STATE_TAB[];
    extern const eval_t EVAL_TAB[];

    extern const int A_WIN;
    extern const int A_NEXT_WIN;

    extern const int E_WIN;
    extern const int E_NEXT_WIN;

    extern const int NONE;

    extern const int SUCCESS_CMD;
    extern const int END_GAME;

    int evaluate_stroke(game_t *game, int x, int y);
    int eval_diagonal_lr(game_t *game, int x, int y);
    int eval_diagonal_rl(game_t *game, int x, int y);
    int eval_horizontal(game_t *game, int x, int y);
    int eval_vertical(game_t *game, int x, int y);
    int eval_line(char line[10]);
    void find_position(game_t *game);
    void gomoku(game_t *game);
    void my_putchar(char c);
    void my_putstr(char *str);
    void my_putnbr(int nb);
    void free_map(char **map);
    char *get_server_command();
    int begin_cmd(game_t *game, char *cmd);
    int start_cmd(game_t *game, char *cmd);
    int board_cmd(game_t *game, char *cmd);
    int turn_cmd(game_t *game, char *cmd);
    int info_cmd(game_t *game, char *cmd);
    int about_cmd(game_t *game, char *cmd);
    int end_cmd(game_t *game, char *cmd);
    void compute_nb_rows(game_t *game, int *rows_p1, int *rows_p2);

#endif /* !GOMOKU_H_ */
