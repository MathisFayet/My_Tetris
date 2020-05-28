/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** random_tetriminos
*/

#include <time.h>
#include "tetris.h"

static int count_nb_tetriminos(tetriminos_t *tetriminos)
{
    int count = 0;
    tetriminos_t *tmp = tetriminos;

    while (tmp != NULL) {
        count += 1;
        tmp = tmp->next;
    }
    return (count - 1);
}

tetriminos_t *get_random(tetris_t *tetris)
{
    int i = 0;
    int count = count_nb_tetriminos(tetris->tetriminos);
    int random_nbr = -1;
    tetriminos_t *model = tetris->tetriminos;

    while (random_nbr < 0) {
        random_nbr = (rand() % (count - 1));
        while (i < random_nbr) {
            model = model->next;
            i += 1;
        }
        if (model->error != 0) {
            random_nbr = -1;
            model = tetris->tetriminos;
        }
        i = 0;
    }
    return (model);
}

char **get_array_model(char *model)
{
    char **array = NULL;

    if (model == NULL)
        return (NULL);
    array = my_str_to_word_array(model, '\n');
    if (array == NULL)
        return (NULL);
    return (array);
}