/*
** EPITECH PROJECT, 2019
** my_put_nbr_base
** File description:
** change base of an int
*/

#include <stdlib.h>
#include "my.h"

int	my_put_nbr_base(int nb, char const *base)
{
    int	final_result = 0;
    int	modulo = 0;

    if (nb < 0){
        my_putchar('-');
        nb = -nb;
    }
    final_result = nb / my_strlen(base);
    modulo = nb % my_strlen(base);
    if (final_result > 0)
        my_put_nbr_base(final_result, base);
    my_putchar(base[modulo]);
    return (0);
}

int	my_put_nbr_base_long(long nb, char const *base)
{
    long result = 0;
    long rest = 0;

    if (nb < 0){
        my_putchar('-');
        nb = -nb;
    }
    result = nb / my_strlen(base);
    rest = nb % my_strlen(base);
    if (result > 0)
        my_put_nbr_base(result, base);
    my_putchar(base[rest]);
    return (0);
}

int	my_put_nbr_base_longlong(long long nb, char const *base)
{
    long long result = 0;
    long long rest = 0;

    if (nb < 0){
        my_putchar('-');
        nb = -nb;
    }
    result = nb / my_strlen(base);
    rest = nb % my_strlen(base);
    if (result > 0)
        my_put_nbr_base(result, base);
    my_putchar(base[rest]);
    return (0);
}