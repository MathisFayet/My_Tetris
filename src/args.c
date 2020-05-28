/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** args
*/

#include "tetris.h"

const struct option long_opt[] = {
    {"debug", no_argument, NULL, 'D'},
    {"help", no_argument, NULL, 'h'},
    {"level", required_argument, NULL, 'L'},
    {"key-left", required_argument, NULL, 'l'},
    {"key-right", required_argument, NULL, 'r'},
    {"key-turn", required_argument, NULL, 't'},
    {"key-drop", required_argument, NULL, 'd'},
    {"key-quit", required_argument, NULL, 'q'},
    {"key-pause", required_argument, NULL, 'p'},
    {"map-size", required_argument, NULL, 'm'},
    {"without-next", no_argument, NULL, 'w'},
    {NULL, no_argument, NULL, -1}
};

void check_flag_opt(args_t *my_args, func_args_t tab[], int flag)
{
    int i = 0;

    while (tab[i].letter != 0) {
        if (flag == tab[i].letter)
            tab[i].func(my_args, optarg);
        i += 1;
    }
}

int get_args(int argc, char **argv, args_t *my_args)
{
    int i = 0;
    int index = 0;
    const char *short_opt = "DL:l:r:t:d:q:p:w";
    int flag = 0;
    func_args_t tab[] = {{'D', func_debug}, {'h', func_help},
        {'L', func_level}, {'l', func_left}, {'r', func_right},
        {'t', func_turn}, {'d', func_drop}, {'q', func_quit},
        {'p', func_pause}, {'m', func_map_size}, {'w', func_next}, {0, NULL}
    };

    while (flag != -1 && flag != ':' && flag != '?') {
        check_flag_opt(my_args, tab, flag);
        flag = getopt_long(argc, argv, short_opt, long_opt, &index);
    }
    return (0);
}