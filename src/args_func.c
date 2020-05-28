/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** args_func
*/

#include "tetris.h"

void func_debug(args_t *my_args, char *argument)
{
    my_args->mode = 2;
}

void func_help(args_t *my_args, char *argument)
{
    my_args->mode = 1;
}

void func_level(args_t *my_args, char *argument)
{
    my_args->level = my_getnbr(argument);
}

void func_left(args_t *my_args, char *argument)
{
    my_args->key_left = argument;
}

void func_right(args_t *my_args, char *argument)
{
    my_args->key_right = argument;
}