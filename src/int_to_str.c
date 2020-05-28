/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** int_to_str
*/

#include "tetris.h"

static int size_word(int nbr)
{
    int index = 0;

    while (nbr > 0) {
        nbr /= 10;
        index += 1;
    }
    return (index);
}

char *int_to_str(int nbr)
{
    int index = 0;
    int len = size_word(nbr);
    char *str = NULL;

    if (nbr == 0)
        return ("0");
    if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
        return (NULL);
    while (nbr > 0) {
        str[index] = (nbr % 10) + 48;
        nbr /= 10;
        index += 1;
    }
    str[index] = '\0';
    str = my_revstr(str);
    return (str);
}