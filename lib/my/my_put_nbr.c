/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** displays all the possibilities values
*/

void my_putchar(char);

void my_putstr(char *);

int my_length_nb(int);

int my_pow(int, int);

int my_length_nb(int nb)
{
    int i = 0;

    while (nb != 0){
        nb /= 10;
        i += 1;
    }
    return (i);
}

int my_pow(int nb, int pow)
{
    int i = 0;
    int result = 1;

    while (i < pow){
        result *= nb;
        i += 1;
    }
    return (result);
}

int display_nbr(int nb)
{
    int i = 0;
    int length = my_length_nb(nb);
    int div = my_pow(10, (length - 1));
    int rest = nb;

    if (length == 0)
        my_putchar(48);
    while (i != length){
        my_putchar((rest / div) + 48);
        rest = (nb % div);
        div = div / 10;
        i += 1;
    }
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648){
        my_putstr("-2147483648");
        return (0);
    } else if (nb < 0){
        nb = -nb;
        my_putchar('-');
    }
    display_nbr(nb);
    return (0);
}
