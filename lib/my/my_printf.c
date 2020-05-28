/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** recode the pri.ntf function
*/

#include "my.h"
#include "my_printf.h"

int put_flags(va_list list, char c, arg_list_t stock_argstruct)
{
    int i = 0;
    char *attribut = "#0-+";
    char precision = '.';
    char *modifier = "lh";
    char *flags = "%diucsboxXpS";

    while (flags[i] != '\0'){
        if (c == attribut[i]){
            stock_argstruct.attribut = attribut[i];
            return (-1);
        } else if (c == modifier[i])
            stock_argstruct.modifier = modifier[i];
        if (c == flags[i]){
            stock_argstruct.indicator = flags[i];
            return (i);
        }
        i += 1;
    }
    return (-1);
}

int check_flags(va_list list, const char *str, arg_list_t args, int *i)
{
    int func_nb = 0;

    func_nb = -1;
    while (func_nb == -1){
        func_nb = put_flags(list, str[*i + 1], args);
        if (func_nb != -1)
            fptr[func_nb](list, args);
        *i += 1;
    }
    return (0);
}

int my_printf(const char *str, ...)
{
    int i = 0;
    int func_nb = 0;
    va_list list;
    arg_list_t argstruct;

    va_start(list, str);
    while (str[i] != '\0'){
        if (str[i] == '%'){
            check_flags(list, str, argstruct, &i);
        } else
            my_putchar(str[i]);
        i += 1;
    }
    va_end(list);
    return (0);
}
