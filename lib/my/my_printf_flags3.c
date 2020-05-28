/*
** EPITECH PROJECT, 2019
** my_printf_flags3
** File description:
** all functions for differents flags
*/

#include "my.h"

int disp_long(va_list list, arg_list_t arg_struct)
{
    my_put_nbr_base_long(va_arg(list, long), "0123456789");
    return (0);
}

int disp_longlong(va_list list, arg_list_t arg_struct)
{
    my_put_nbr_base_long(va_arg(list, long long), "0123456789");
    return (0);
}
