/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** get_infos_tetrimino
*/

#include "tetris.h"

int get_buffer_file(tetriminos_t *my_tetrimino, char *filepath)
{
    int fd = 0;
    int read_bytes = 0;
    struct stat my_stats;
    char *buffer = NULL;

    if (filepath == NULL)
        return (1);
    if ((fd = open(filepath, O_RDONLY)) < 0)
        return (1);
    if ((stat(filepath, &my_stats)) < 0)
        return (1);
    if ((buffer = malloc(sizeof(char) * (my_stats.st_size + 1))) == NULL)
        return (1);
    if ((read_bytes = read(fd, buffer, my_stats.st_size)) <= 0)
        return (1);
    buffer[read_bytes] = '\0';
    my_tetrimino->tetrimino = buffer;
    return (0);
}

int get_name(tetriminos_t *my_tetrimino, char *filepath)
{
    int i = 0;
    int j = 0;
    char *name = malloc(sizeof(char) * 255);

    while (filepath[i] != '/' && filepath[i] != '\0')
        i += 1;
    i += 1;
    while (filepath[i] != '.' && filepath[i] != '\0') {
        name[j] = filepath[i];
        i += 1;
        j += 1;
    }
    name[j] = '\0';
    my_tetrimino->name = name;
    return (0);
}

int get_infos_tetrimino(tetriminos_t *my_tetrimino, char *filepath)
{
    if (get_name(my_tetrimino, filepath) == 1)
        return (1);
    if (get_buffer_file(my_tetrimino, filepath) == 1)
        return (1);
    if (check_errors(my_tetrimino) == 1)
        return (1);
    if (get_size_color(my_tetrimino, my_tetrimino->tetrimino) == 1)
        return (1);
    if (check_params_line(my_tetrimino, my_tetrimino->tetrimino) == 1)
        return (1);
    return (0);
}