/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** CPE_GETNEXTLINE_2019
*/

#include "get_next_line.h"

static char *my_realloc(char *buffer, int size)
{
    int i = 0;
    char *new_buffer = malloc(sizeof(char) * (size + 1));

    if (new_buffer == NULL)
        return (NULL);
    while (buffer[i] != '\0'){
        new_buffer[i] = buffer[i];
        i += 1;
    }
    free(buffer);
    return (new_buffer);
}

static int make_verification(int fd, int *nb_bytes, char *buffer, int *s_i)
{
    if (*nb_bytes == 0 && (*nb_bytes = read(fd, buffer, READ_SIZE)) != 0)
        *s_i = 0;
    return (0);
}

int other(char *str, int size)
{
    str[size] = '\0';
    if ((str = my_realloc(str, size + READ_SIZE)) == NULL)
        return (1);
    return (0);
}

char *get_next_line(int fd)
{
    int i = 0;
    char buffer[READ_SIZE];
    static int nb_bytes = 0;
    static int s_i = 0;
    char *final_buffer = malloc(sizeof(char) * (READ_SIZE + 1));

    VERIF_MALLOC;
    make_verification(fd, &nb_bytes, buffer, &s_i);
    if (nb_bytes == -1 || nb_bytes == 0) {
        EXIT_PROG;
    }
    while (buffer[s_i] != '\n' && buffer[s_i] != '\0') {
        final_buffer[i++] = buffer[s_i++];
        if ((nb_bytes -= 1) == 0 && (nb_bytes = read(fd, buffer, READ_SIZE)))
            if ((s_i = other(final_buffer, i)) == 1)
                return (NULL);
    }
    final_buffer[i] = '\0';
    s_i += 1;
    nb_bytes -= 1;
    return (final_buffer);
}