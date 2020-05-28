/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** splits a string into words, into array
*/

#include <stdlib.h>
#include "my.h"

int nb_words(char const *str, char delimiter)
{
    int i = 0;
    int nb_words = 0;

    while (str[i] != 0){
        if (str[i] == delimiter)
            nb_words += 1;
        i += 1;
    }
    return (i);
}

char **my_str_to_word_array(const char *str, char delimiter)
{
    int i = 0;
    int x = 0;
    int y = 0;
    char **array = malloc(sizeof(char *) * (nb_words(str, delimiter) + 1));

    array[y] = malloc(sizeof(char) * my_strlen(str) + 1);
    while (str[i] != '\0') {
        if (str[i] == delimiter){
            array[y][x] = '\0';
            x = 0;
            y += 1;
            array[y] = malloc(sizeof(char) * my_strlen(str) + 1);
        } else{
            array[y][x] = str[i];
            x += 1;
        }
        i += 1;
    }
    array[y][x] = '\0';
    array[y + 1] = NULL;
    return (array);
}