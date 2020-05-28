/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** args_func3
*/

#include "tetris.h"

void free_array(char **array)
{
    int y = 0;

    while (array[y] != NULL) {
        free(array[y]);
        y += 1;
    }
    free(array);
}

void func_map_size(args_t *my_args, char *argument)
{
    char **array = my_str_to_word_array(argument, ',');

    if (array[0] == NULL || array[1] == NULL ||
        (array[1][0] < '0' || array[1][0] > '9'))
        return;
    my_args->map_size_row = my_getnbr(array[0]);
    my_args->map_size_col = my_getnbr(array[1]);
    free_array(array);
}

void func_next(args_t *my_args, char *argument)
{
    my_args->next = 1;
}