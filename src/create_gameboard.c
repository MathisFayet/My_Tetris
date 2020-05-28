/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** create_gameboard
*/

#include "tetris.h"

static char **fill_my_board(char **board, int y, int x)
{
    int lines = 0;
    int col = 0;

    for (lines = 0; board[lines] != NULL; lines++) {
        board[lines][0] = '|';
        for (col = 1; col < (x - 1); col++)
            board[lines][col] = ' ';
        board[lines][col] = '|';
        board[lines][col + 1] = '\0';
    }
    for (col = 0; board[y - 1][col] != '\0'; col++) {
        board[0][col] = '-';
        board[y - 1][col] = '-';
    }
    board[0][0] = '+';
    board[0][x - 1] = '+';
    board[y - 1][0] = '+';
    board[y - 1][x - 1] = '+';
    return (board);
}

char **create_gameboard(int y, int x)
{
    int index = 0;
    char **gameboard = malloc(sizeof(char *) * (y + 1));

    while (index < y) {
        if ((gameboard[index] = malloc(sizeof(char) * (x + 1))) == NULL) {
            return (NULL);
        }
        index += 1;
    }
    gameboard[index] = NULL;
    gameboard = fill_my_board(gameboard, y, x);
    return (gameboard);
}