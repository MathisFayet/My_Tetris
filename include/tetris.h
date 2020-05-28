/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <curses.h>
#include <getopt.h>
#include <time.h>

#include "my.h"

typedef struct s_args {
    int mode;
    int level;
    char *key_left;
    char *key_right;
    char *key_turn;
    char *key_drop;
    char *key_quit;
    char *key_pause;
    int map_size_row;
    int map_size_col;
    int next;
} args_t;

typedef struct s_func_args {
    char letter;
    void (*func)(args_t *, char *);
} func_args_t;

typedef struct s_tetriminos {
    char *tetrimino;
    char *name;
    int error;
    int row;
    int col;
    int color;
    struct s_tetriminos *next;
} tetriminos_t;

typedef struct s_g_tetriminos {
    char **tetrimino;
    int x;
    int y;
    int gravity;
    int color;
    struct s_g_tetriminos *next;
} g_tetriminos_t;

typedef struct s_window {
    int width;
    int height;
    char **gameboard;
    clock_t game_clock;
} window_t;

typedef struct s_infos {
    int high_score;
    int score;
    int lines;
    int level;
    clock_t timer;
} infos_t;

typedef struct s_tetris {
    int game_instance;
    args_t *args;
    tetriminos_t *tetriminos;
    g_tetriminos_t *game_tetri;
    window_t *window;
    infos_t *infos;
} tetris_t;

/* tetris.c */
int tetris(int, char **);
tetris_t *init_struct_tetris(void);

/* args.c */
int get_args(int, char **, args_t *);

/* args_func.c */
void func_debug(args_t *, char *);
void func_help(args_t *, char *);
void func_level(args_t *, char *);
void func_left(args_t *, char *);
void func_right(args_t *, char *);
void func_turn(args_t *, char *);
void func_drop(args_t *, char *);
void func_quit(args_t *, char *);
void func_pause(args_t *, char *);
void func_map_size(args_t *, char *);
void func_next(args_t *, char *);

/* debug.c */
int debug_tetris(tetris_t *, int);

/* check_errors.c */
int check_env(char **);
int check_errors(tetriminos_t *);
int check_params_line(tetriminos_t *, char *);

/* tetrimino.c */
tetriminos_t *get_tetrimino(tetriminos_t *);
int tetrimino(char *);

/* game.c */
int main_gameloop(tetris_t *);
int check_game_status(tetris_t *);

/* game_tetriminos */
char **get_array_model(char *);
tetriminos_t *get_random(tetris_t *);
g_tetriminos_t *create_tetrimino_with_model(tetris_t *, g_tetriminos_t **);

/* manage_g_tetri.c */
g_tetriminos_t *check_all_gravities(g_tetriminos_t *);
void manage_g_tetri(tetris_t *);

/* others */
char **create_gameboard(int, int);
int get_inputs(tetris_t *, int);
void create_colors(tetris_t *);
char *int_to_str(int);

/* window.c */
void display_elements(tetris_t *);

/* dir_tetriminos */
tetriminos_t *create_new_tetrimino(tetriminos_t **);
int get_infos_tetrimino(tetriminos_t *, char *);
int get_size_color(tetriminos_t *, char *);

void sort_array_by_name(char **);
char **get_array_sorted(tetriminos_t *);

/* rules.c */
void print_rules(char *);

#endif /* !TETRIS_H_ */