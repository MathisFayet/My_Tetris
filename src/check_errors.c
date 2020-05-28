/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** check_errors
*/

#include "tetris.h"

int check_params_line(tetriminos_t *my_tetrimino, char *buffer)
{
    int i = 0;
    int count_line = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            count_line += 1;
        i += 1;
    }
    if (count_line != my_tetrimino->col)
        return (1);
    return (0);
}

static int check_char_file(tetriminos_t *my_tetrimino, char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if ((buffer[i] < '0' || buffer[i] > '9') && (buffer[i] != '*' &&
            buffer[i] != ' ' && buffer[i] != '\n'))
            return (1);
        i += 1;
    }
    return (0);
}

static int check_format_params(tetriminos_t *my_tetrimino, char *buffer)
{
    int i = 0;
    int nb_space = 0;

    while (buffer[i] != '\n' && buffer[i] != '\0') {
        if (buffer[i] == ' ')
            nb_space += 1;
        i += 1;
    }
    if (buffer[i] == '\0' || (nb_space != 2))
        return (1);
    return (0);
}

int check_errors(tetriminos_t *my_tetrimino)
{
    if (check_char_file(my_tetrimino, my_tetrimino->tetrimino) == 1)
        return (1);
    if (check_format_params(my_tetrimino, my_tetrimino->tetrimino) == 1)
        return (1);
    return (0);
}