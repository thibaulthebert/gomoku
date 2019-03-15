/*
** EPITECH PROJECT, 2018
** Gomoku
** File description:
** Usefull functions in gomoku
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "gomoku.h"

char *get_server_command()
{
    char *line = malloc(2);
    int i = 0;

    line[0] = getchar();
    line[1] = '\0';
    while (line[i] != '\n') {
        line = realloc(line, i + 3);
        i++;
        line[i] = getchar();
        line[i + 1] = '\0';
    }
    return (line);
}

void free_map(char **map)
{
    if (!map)
        return ;
    for (int i = 0; map[i]; i++)
        free(map[i]);
    free(map);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putnbr(int nb)
{
    int val = 0;

    if (nb >= 10) {
        val = nb % 10;
        nb = nb / 10;
        my_putnbr(nb);
        my_putchar(val + '0');
    } else {
        my_putchar(nb + '0');
    }
}

void my_putstr(char *str)
{
    write(1, str, strlen(str));
}