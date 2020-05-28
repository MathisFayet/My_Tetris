/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** array_sorted
*/

#include "tetris.h"

void sort_array_by_name(char **array)
{
    int y = 0;
    char *save = NULL;

    while (array[y + 1] != NULL) {
        if (my_strcmp(array[y], array[y + 1]) == 1) {
            save = array[y];
            array[y] = array[y + 1];
            array[y + 1] = save;
            y = 0;
        }
        y += 1;
    }
}

static int len_names(tetriminos_t *tetriminos)
{
    int final_len = 0;
    tetriminos_t *tmp = tetriminos;

    while (tmp != NULL) {
        final_len += my_strlen(tmp->name) + 1;
        tmp = tmp->next;
    }
    return (final_len);
}

static char *get_all_names(tetriminos_t *tetriminos)
{
    char *names = NULL;
    int len = len_names(tetriminos);
    tetriminos_t *tmp = tetriminos;

    if ((names = malloc(sizeof(char) * (len + 1))) == NULL)
        return (NULL);
    while (tmp != NULL) {
        names = my_strcat(names, tmp->name);
        names = my_strcat(names, ";");
        tmp = tmp->next;
    }
    names[len - 1] = '\0';
    return (names);
}

char **get_array_sorted(tetriminos_t *tetriminos)
{
    char **array = NULL;
    char *names = get_all_names(tetriminos);

    if (names == NULL)
        return (NULL);
    array = my_str_to_word_array(names, ';');
    if (array == NULL)
        return (NULL);
    return (array);
}