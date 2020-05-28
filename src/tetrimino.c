/*
** EPITECH PROJECT, 2020
** PSU_bstetris_2019
** File description:
** tetrimino
*/

#include "tetris.h"

int check_line(char *params)
{
    int i = 0;

    if (params == NULL)
        return (1);
    while (params[i] != '\0') {
        if ((params[i] < '0' || params[i] > '9') && params[i] != ' ')
            return (1);
        i += 1;
    }
    return (0);
}

int display_tetrimino(tetriminos_t *my_tetrimino, char *filepath)
{
    while (my_tetrimino->next != NULL)
        my_tetrimino = my_tetrimino->next;
    my_tetrimino->error = get_infos_tetrimino(my_tetrimino, filepath);
    if (my_tetrimino->error == 2)
        return (1);
    return (0);
}

tetriminos_t *get_tetrimino(tetriminos_t *tetriminos)
{
    DIR *dir = opendir("tetriminos");
    struct dirent *read_dir = NULL;
    char *filepath = malloc(sizeof(char) * 255);

    if (dir == NULL || filepath == NULL)
        return (NULL);
    my_strcpy(filepath, "tetriminos/");
    while ((read_dir = readdir(dir)) != NULL) {
        if (read_dir->d_name[0] != '.') {
            if ((tetriminos = create_new_tetrimino(&tetriminos)) == NULL)
                return (NULL);
            filepath = my_strcat(filepath, read_dir->d_name);
            if (display_tetrimino(tetriminos, filepath) == 1)
                return (NULL);
            my_strcpy(filepath, "tetriminos/");
        }
    }
    free(filepath);
    return (tetriminos);
}