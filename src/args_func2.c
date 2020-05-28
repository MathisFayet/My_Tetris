/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** args_func2
*/

#include "tetris.h"

void func_turn(args_t *my_args, char *argument)
{
    my_args->key_turn = argument;
}

void func_drop(args_t *my_args, char *argument)
{
    my_args->key_drop = argument;
}

void func_quit(args_t *my_args, char *argument)
{
    my_args->key_quit = argument;
}

void func_pause(args_t *my_args, char *argument)
{
    my_args->key_pause = argument;
}