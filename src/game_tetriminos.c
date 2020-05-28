/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game_tetriminos
*/

#include "tetris.h"

g_tetriminos_t *empty_g_tetri(tetris_t *tetris, g_tetriminos_t **game_tetri)
{
    g_tetriminos_t *element = malloc(sizeof(g_tetriminos_t));
    tetriminos_t *model = get_random(tetris);
    char **array_model = get_array_model(model->tetrimino);

    if (element == NULL || array_model == NULL)
        return (NULL);
    element->tetrimino = array_model;
    element->x = (tetris->window->width / 2);
    element->y = 0;
    element->gravity = 1;
    element->color = model->color;
    element->next = NULL;
    *game_tetri = element;
    return (*game_tetri);
}

g_tetriminos_t *put_g_tetri(tetris_t *tetris, g_tetriminos_t **game_tetri)
{
    g_tetriminos_t *tmp = *game_tetri;
    g_tetriminos_t *element = malloc(sizeof(g_tetriminos_t));
    tetriminos_t *model = get_random(tetris);
    char **array_model = get_array_model(model->tetrimino);

    if (element == NULL || array_model == NULL)
        return (NULL);
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    element->tetrimino = array_model;
    element->x = (tetris->window->width / 2);
    element->y = 0;
    element->gravity = 1;
    element->color = model->color;
    element->next = NULL;
    tmp->next = element;
    return (*game_tetri);
}

g_tetriminos_t *create_tetrimino_with_model(tetris_t *tetris,
                            g_tetriminos_t **game_tetri)
{
    if (*game_tetri == NULL) {
        empty_g_tetri(tetris, game_tetri);
    } else {
        put_g_tetri(tetris, game_tetri);
    }
    return (*game_tetri);
}
