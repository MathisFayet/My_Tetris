/*
** EPITECH PROJECT, 2019
** my_arraylen
** File description:
** return the length of an array
*/

#include <stddef.h>

int my_arraylen(char **tab)
{
    int i = 0;

    while (tab[i] != NULL){
        i += 1;
    }
    return (i);
}
