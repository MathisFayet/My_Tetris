/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** linked_tetriminos
*/

#include "tetris.h"

tetriminos_t *put_list_tetrimino(tetriminos_t **list_tetriminos)
{
    tetriminos_t *tmp = *list_tetriminos;
    tetriminos_t *new_tetrimino = malloc(sizeof(tetriminos_t));

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    new_tetrimino->tetrimino = NULL;
    new_tetrimino->name = NULL;
    new_tetrimino->error = 0;
    new_tetrimino->row = 0;
    new_tetrimino->col = 0;
    new_tetrimino->color = 0;
    new_tetrimino->next = NULL;
    tmp->next = new_tetrimino;
    return (*list_tetriminos);
}

tetriminos_t *put_empty_list_tetrimino(tetriminos_t **list_tetriminos)
{
    tetriminos_t *new_tetrimino = malloc(sizeof(tetriminos_t));

    new_tetrimino->tetrimino = NULL;
    new_tetrimino->name = NULL;
    new_tetrimino->error = 0;
    new_tetrimino->row = 0;
    new_tetrimino->col = 0;
    new_tetrimino->color = 0;
    new_tetrimino->next = NULL;
    *list_tetriminos = new_tetrimino;
    return (*list_tetriminos);
}

tetriminos_t *create_new_tetrimino(tetriminos_t **list_tetriminos)
{
    if (*list_tetriminos == NULL)
        put_empty_list_tetrimino(list_tetriminos);
    else
        put_list_tetrimino(list_tetriminos);
    return (*list_tetriminos);
}