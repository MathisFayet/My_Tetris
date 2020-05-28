/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** rules
*/

#include "tetris.h"

void print_rules(char *binary)
{
    if (binary == NULL)
        return;
    my_printf("Usage:\t%s [options]\nOptions:\n  --help", binary);
    my_putstr("\t\tDisplay this help\n  ");
    my_putstr("-L --level={num}\tStart Tetris at level num (def: 1)\n  ");
    my_putstr("-l --key-left={K}\tMove the tetrimino LEFT using the K key ");
    my_putstr("(def: left arrow)\n  -r --key-rigth={K}\tMove the tetrimino ");
    my_putstr("RIGTH using the K key (def: right arrow)\n  -t --key-turn ");
    my_putstr("={K}\tTURN the tetrimino clockvise 90d using the K key");
    my_putstr("(def: top");
    my_putstr("arrows)\n  -d --key-drop={K}\tDROP the tetrimino ");
    my_putstr("using the K key (def: down arrow)\n  -q --key-quit={K}\t");
    my_putstr("QUIT the game using the K key (def: 'q' key)\n  -p --key-paus");
    my_putstr("e ={K}\tPAUSE/RESTART the game using the K key (def: ");
    my_putstr("space bar)\n  --map-size={row,col}\tSet the numbers of rows");
    my_putstr(" and columns of the map (def: 20,10)\n  -w --without-next\t");
    my_putstr("Hide next tetrimino (def: false)\n  ");
    my_putstr("-D --debug\t\tDebug mode (def: false)\n");
}