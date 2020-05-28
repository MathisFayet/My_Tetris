/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** inputs
*/

#include "tetris.h"

void move_actual_element(tetris_t *tetris, int move_y, int move_x)
{
    g_tetriminos_t *check_gravities = check_all_gravities(tetris->game_tetri);

    if (check_gravities != NULL) {
        check_gravities->x += move_x;
        check_gravities->y += move_y;
    }
}

int get_inputs(tetris_t *tetris, int key)
{
    if (key == tetris->args->key_quit[0])
        return (1);
    if (key == tetris->args->key_right[0])
        move_actual_element(tetris, 0, 1);
    if (key == tetris->args->key_left[0])
        move_actual_element(tetris, 0, -1);
    return (0);
}