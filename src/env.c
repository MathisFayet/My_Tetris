/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** env
*/

#include "tetris.h"

int check_env(char **envp)
{
    int y = 0;

    if (envp == NULL || *envp == NULL) {
        return (1);
    }
    while (envp[y] != NULL) {
        if (my_strncmp("TERM=", envp[y], 4) == 0) {
            return (0);
        }
        y += 1;
    }
    return (1);
}