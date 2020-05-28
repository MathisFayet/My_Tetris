/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** manage_g_tetri
*/

#include "tetris.h"

g_tetriminos_t *check_all_gravities(g_tetriminos_t *game)
{
    g_tetriminos_t *tmp = game;

    while (tmp != NULL) {
        if (tmp->gravity == 1)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

static int str_len_tab(char **tab)
{
    int y = 0;

    while (tab[y] != NULL) {
        y += 1;
    }
    return (y);
}

int collision_g_tetri(tetris_t *tetris, g_tetriminos_t *element)
{
    g_tetriminos_t *tmp = tetris->game_tetri;

    while (tmp != NULL) {
        if ((tmp->y - 1) == (element->y + (str_len_tab(tmp->tetrimino))))
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void move_down_element(tetris_t *tetris, g_tetriminos_t *element)
{
    int elem_y_cmp = (element->y + (str_len_tab(element->tetrimino)));
    int elem_x_cmp = (element->x - ((tetris->window->width / 2) -
        my_strlen(tetris->window->gameboard[0]) / 2));

    element->y += 1;
    if ((tetris->window->gameboard[elem_y_cmp + 1][elem_x_cmp] == '-') ||
    collision_g_tetri(tetris, element) == 1) {
        element->gravity = 0;
    }
}

void manage_g_tetri(tetris_t *tetris)
{
    g_tetriminos_t *check_gravities = check_all_gravities(tetris->game_tetri);

    if (check_gravities == NULL) {
        if (check_game_status(tetris) == 1)
            return;
        else
            create_tetrimino_with_model(tetris, &tetris->game_tetri);
    } else {
        move_down_element(tetris, check_gravities);
    }
}