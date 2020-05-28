/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** window
*/

#include "tetris.h"

static void display_informations2(tetris_t *tetris)
{
    infos_t *infos = tetris->infos;
    window_t *win = tetris->window;
    int max_y = tetris->window->height;
    int max_x = tetris->window->width;

    infos->timer = 0;
    mvprintw((max_y / 2) - 1, (max_x / 2) - my_strlen(win->gameboard[0]) - 15,
        "* Level");
    mvprintw((max_y / 2) - 1, (max_x / 2) - my_strlen(win->gameboard[0]) + 5,
        int_to_str(infos->level));
    mvprintw((max_y / 2) + 1, (max_x / 2) - my_strlen(win->gameboard[0]) - 15,
        "* Timer");
    mvprintw((max_y / 2) + 1, (max_x / 2) - my_strlen(win->gameboard[0]) + 5,
        int_to_str(infos->timer));
}

static void display_informations1(tetris_t *tetris)
{
    infos_t *infos = tetris->infos;
    window_t *win = tetris->window;
    int max_y = tetris->window->height;
    int max_x = tetris->window->width;

    mvprintw((max_y / 2) - 5, (max_x / 2) - my_strlen(win->gameboard[0]) - 15,
        "* High Score");
    mvprintw((max_y / 2) - 5, (max_x / 2) - my_strlen(win->gameboard[0]) + 5,
        int_to_str(infos->high_score));
    mvprintw((max_y / 2) - 4, (max_x / 2) - my_strlen(win->gameboard[0]) - 15,
        "* Score");
    mvprintw((max_y / 2) - 4, (max_x / 2) - my_strlen(win->gameboard[0]) + 5,
        int_to_str(infos->score));
    mvprintw((max_y / 2) - 2, (max_x / 2) - my_strlen(win->gameboard[0]) - 15,
        "* Lines");
    mvprintw((max_y / 2) - 2, (max_x / 2) - my_strlen(win->gameboard[0]) + 5,
        int_to_str(infos->lines));
}

static int check_size_window(tetris_t *tetris)
{
    int max_y = tetris->window->height;
    int max_x = tetris->window->width;
    char error_msg[24] = "The window is too small";

    if ((max_y < tetris->args->map_size_col) ||
        (max_x < ((tetris->args->map_size_row * 2) + 30))) {
        mvprintw((max_y / 2), (max_x / 2) - (my_strlen(error_msg) / 2),
            error_msg);
        return (1);
    }
    return (0);
}

void display_all_g_tetri(tetris_t *tetris, g_tetriminos_t *g_tetri)
{
    int y = 0;
    int x = 0;
    g_tetriminos_t *tmp = g_tetri;

    while (tmp != NULL) {
        while (tmp->tetrimino[y] != NULL) {
            mvprintw((tmp->y + ((tetris->window->height / 2) -
                (tetris->args->map_size_col / 2)) + 1) + y,
                tmp->x, tmp->tetrimino[y]);
            y += 1;
        }
        y = 0;
        tmp = tmp->next;
    }
}

void display_elements(tetris_t *tetris)
{
    int y = 0;
    int max_y = tetris->window->height;
    int max_x = tetris->window->width;
    char **board = tetris->window->gameboard;

    if (check_size_window(tetris) == 1)
        return;
    display_informations1(tetris);
    display_informations2(tetris);
    while (board[y] != NULL) {
        mvprintw(((max_y / 2) + y) - (tetris->args->map_size_col / 2),
            (max_x / 2) - (my_strlen(board[y]) / 2), board[y]);
        y += 1;
    }
    display_all_g_tetri(tetris, tetris->game_tetri);
}