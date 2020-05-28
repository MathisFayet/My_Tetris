/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** struct
*/

#include "tetris.h"

infos_t *init_struct_infos(void)
{
    infos_t *infos = malloc(sizeof(infos_t));

    infos->high_score = 0;
    infos->score = 0;
    infos->lines = 0;
    infos->level = 0;
    infos->timer = 0;
    return (infos);
}

window_t *init_struct_window(void)
{
    window_t *window = malloc(sizeof(window_t));

    window->width = 0;
    window->height = 0;
    window->gameboard = '\0';
    window->game_clock = 0;
    return (window);
}

args_t *init_struct_args(void)
{
    args_t *args = malloc(sizeof(args_t));

    args->mode = 0;
    args->level = 1;
    args->key_left = "^EOD";
    args->key_right = "^EOC";
    args->key_turn = "^EOA";
    args->key_drop = "^EOB";
    args->key_quit = "q";
    args->key_pause = " ";
    args->map_size_row = 20;
    args->map_size_col = 10;
    args->next = 0;
    return (args);
}

tetris_t *init_struct_tetris(void)
{
    tetris_t *new_struct = malloc(sizeof(tetris_t));

    new_struct->game_instance = 0;
    new_struct->args = init_struct_args();
    new_struct->tetriminos = NULL;
    new_struct->game_tetri = NULL;
    new_struct->window = init_struct_window();
    new_struct->infos = init_struct_infos();
    return (new_struct);
}