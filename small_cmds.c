/*
** EPITECH PROJECT, 2018
** Gomoku
** File description:
** Small commands to handle during protocol
*/

#include "gomoku.h"

int info_cmd(game_t *game, char *cmd)
{
    (void)game;
    (void)cmd;
    return (SUCCESS_CMD);
}

int about_cmd(game_t *game, char *cmd)
{
    (void)game;
    (void)cmd;
    my_putstr("name=\"TBR\", version=\"1.0\", ");
    my_putstr("author=\"Hebert T. Medica B. Otal R.\", country=\"FR\"\n");
    return (SUCCESS_CMD);
}

int end_cmd(game_t *game, char *cmd)
{
   (void)cmd;
    if (!(game->map))
        return (END_GAME);
    free_map(game->map);
    return (END_GAME);
}
