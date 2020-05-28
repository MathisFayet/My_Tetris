/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** debug
*/

#include "tetris.h"

void display_arguments(args_t *my_args)
{
    my_printf("*** DEBUG MODE ***\n");
    my_printf("Key Left : %s\n", my_args->key_left);
    my_printf("Key Right : %s\n", my_args->key_right);
    my_printf("Key Turn : %s\n", my_args->key_turn);
    my_printf("Key Drop : %s\n", my_args->key_drop);
    my_printf("Key Quit : %s\n", my_args->key_quit);
    my_printf("Key Pause : %s\n", my_args->key_pause);
    my_printf("Next : %s\n", my_args->next == 0 ? "Yes" : "No");
    my_printf("Level : %d\n", my_args->level);
    my_printf("Size : %d*%d\n", my_args->map_size_row, my_args->map_size_col);
}

static int get_nb_tetriminos(char *filepath)
{
    DIR *dir = opendir(filepath);
    struct dirent *read_dir = NULL;
    int count = 0;

    if (dir == NULL)
        return (-1);
    while ((read_dir = readdir(dir)) != NULL) {
        if (read_dir->d_name[0] != '.') {
            count += 1;
        }
    }
    return (count);
}

void display_sorted_list(tetriminos_t *tmp, char *name)
{
    if (my_strcmp(name, tmp->name) != 0)
        return;
    my_printf("Tetriminos : Name %s : ", tmp->name);
    if (tmp->error == 1) {
        my_printf("Error\n");
    } else {
        my_printf("Size %d*%d : Color %d :\n%s", tmp->row,
        tmp->col, tmp->color, tmp->tetrimino);
    }
}

static int display_tetriminos(tetriminos_t *tetriminos)
{
    int y = 0;
    int total_tetriminos = get_nb_tetriminos("tetriminos");
    tetriminos_t *tmp = tetriminos;
    char **sorted_array = get_array_sorted(tetriminos);

    if (tetriminos == NULL || sorted_array == NULL || total_tetriminos == -1)
        return (1);
    sort_array_by_name(sorted_array);
    my_printf("Tetriminos : %d\n", total_tetriminos);
    while (sorted_array[y] != NULL) {
        while (tmp != NULL) {
            display_sorted_list(tmp, sorted_array[y]);
            tmp = tmp->next;
        }
        tmp = tetriminos;
        y += 1;
    }
    return (0);
}

int debug_tetris(tetris_t *tetris, int mode)
{
    char *key = NULL;

    if ((tetris->tetriminos = get_tetrimino(tetris->tetriminos)) == NULL)
        return (1);
    if (mode == 2) {
        display_arguments(tetris->args);
        if (display_tetriminos(tetris->tetriminos) == 1)
            return (1);
        my_printf("Press any key to start Tetris\n");
        while (read(0, key, 1) != -1) {
        }
    }
    return (0);
}