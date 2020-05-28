/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** get_size_color
*/

#include "tetris.h"

int fill_str(tetriminos_t *my_tetrimino, char *buffer, int *final)
{
    int i = 0;
    char *dest = NULL;

    if ((dest = malloc(sizeof(char) * 255)) == NULL)
        return (-1);
    while (buffer[i] != ' ' && buffer[i] != '\n') {
        if (buffer[i] == '\0')
            return (-1);
        dest[i] = buffer[i];
        i += 1;
    }
    dest[i] = '\0';
    *final = my_getnbr(dest);
    free(dest);
    return (i + 1);
}

int get_size_color(tetriminos_t *my_tetrimino, char *buffer)
{
    int i = 0;

    if ((i = fill_str(my_tetrimino, &buffer[i], &(my_tetrimino->row))) == -1)
        return (1);
    if ((i = fill_str(my_tetrimino, &buffer[i], &(my_tetrimino->col))) == -1)
        return (1);
    if ((i = fill_str(my_tetrimino, &buffer[i + 2], &(my_tetrimino->color)))
        == -1)
        return (1);
    i = 0;
    while (buffer[i] != '\n' && buffer[i] != '\0')
        i += 1;
    my_tetrimino->tetrimino = &buffer[i + 1];
    return (0);
}