/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game_instance
*/

#include "tetris.h"

int check_game_status(tetris_t *tetris)
{
    g_tetriminos_t *tmp = tetris->game_tetri;

    if (tmp == NULL)
        return (0);
    while (tmp->next != NULL) {
        if (tmp->y == 0)
            tetris->game_instance = 1;
        tmp = tmp->next;
    }
    return (0);
}