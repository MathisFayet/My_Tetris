/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#include "tetris.h"

int launch_game(tetris_t *tetris)
{
    tetris->window->gameboard = create_gameboard(tetris->args->map_size_col,
        tetris->args->map_size_row);
    tetris->infos->level = tetris->args->level;
    if (tetris->window->gameboard == NULL)
        return (1);
    if (main_gameloop(tetris) == 1)
        return (1);
    return (0);
}

int tetris(int argc, char **argv)
{
    tetris_t *tetris = init_struct_tetris();

    if (get_args(argc, argv, tetris->args) == 1)
        return (1);
    if (tetris->args->mode == 1) {
        print_rules(argv[0]);
        return (0);
    }
    if (debug_tetris(tetris, tetris->args->mode) == 1)
        return (1);
    if (launch_game(tetris) == 1)
        return (1);
    return (0);
}