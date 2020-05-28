/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** allocates memory and copies string given into another
*/

#include <stdlib.h>

int my_strlen(char const *);

char *my_strdup(char const *src)
{
    int i = 0;
    int len = my_strlen(src);
    char *result = malloc(sizeof(char) * (len + 1));

    if (result == NULL){
        return (NULL);
    }
    while (src[i] != '\0') {
        result[i] = src[i];
        i += 1;
    }
    result[i] = '\0';
    return (result);
}
