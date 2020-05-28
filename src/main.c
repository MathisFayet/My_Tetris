/*
** EPITECH PROJECT, 2020
** PSU_bstetris_2019
** File description:
** main
*/

#include "tetris.h"

int main(int argc, char **argv, char **envp)
{
    if (check_env(envp) == 1)
        return (84);
    if (tetris(argc, argv) == 1)
        return (84);
    return (0);
}