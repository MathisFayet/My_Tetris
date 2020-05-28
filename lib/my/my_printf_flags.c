/*
** EPITECH PROJECT, 2019
** my_printf_flags
** File description:
** all functions for differents flags
*/

#include "my.h"

int disp_percent(va_list list, arg_list_t get_argstruct)
{
    my_putchar('%');
    return (0);
}

int disp_nbr(va_list list, arg_list_t get_argstruct)
{
    int my_arg = va_arg(list, int);

    my_put_nbr_base(my_arg, "0123456789");
    return (0);
}

int disp_char(va_list list, arg_list_t get_argstruct)
{
    int my_arg = va_arg(list, int);

    my_putchar(my_arg);
    return (0);
}

int disp_str(va_list list, arg_list_t get_argstruct)
{
    char *my_arg = va_arg(list, char *);

    if (my_arg == NULL)
        my_putstr("(null)");
    else
        my_putstr(my_arg);
    return (0);
}

int disp_binary(va_list list, arg_list_t get_argstruct)
{
    int my_arg = va_arg(list, int);

    my_put_nbr_base(my_arg, "01");
    return (0);
}
