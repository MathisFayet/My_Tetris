/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#include "tetris.h"

int main_gameloop(tetris_t *tetris)
{
    int i = 0;

    srand(time(NULL));
    create_colors(tetris);
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    while (tetris->game_instance == 0) {
        clear();
        getmaxyx(stdscr, tetris->window->height, tetris->window->width);
        manage_g_tetri(tetris);
        display_elements(tetris);
        refresh();
        if (get_inputs(tetris, getch()) == 1)
            break;
    }
    endwin();
    return (0);
}