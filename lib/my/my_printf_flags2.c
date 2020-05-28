/*
** EPITECH PROJECT, 2019
** my_printf_flags2
** File description:
** all functions for differents flags
*/

#include "my.h"

int disp_octal(va_list list, arg_list_t arg_struct)
{
    my_put_nbr_base(va_arg(list, int), "01234567");
    return (0);
}

int disp_hexa(va_list list, arg_list_t arg_struct)
{
    int nb = va_arg(list, int);
    my_put_nbr_base(nb, "0123456789abcdef");
    return (0);
}

int disp_hexamaj(va_list list, arg_list_t arg_struct)
{
    my_put_nbr_base(va_arg(list, int), "0123456789ABCDEF");
    return (0);
}

int disp_ptr(va_list list, arg_list_t arg_struct)
{
    my_putstr("0x");
    my_put_nbr_base_long(va_arg(list, long), "0123456789abcdef");
    return (0);
}

int disp_nprint(va_list list, arg_list_t arg_struct)
{
    return (0);
}
