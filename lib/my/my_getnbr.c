/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** returns a number, sent to the function as a string
*/

int my_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int my_sign_str(char const *str)
{
    int i = 0;
    int sign = 1;

    while (str[i] != '\0' && my_isnum(str[i]) == 0){
        if (str[i] == '-'){
            sign = sign * (-1);
        }
        i += 1;
    }
    return (sign);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int result = 0;

    while (str[i] != '\0'){
        if (my_isnum(str[i]) == 1){
            result *= 10;
            result += (str[i] - 48);
            if (result == -2147483648)
                return (2147483648);
            else if (result > 2147483647 || result < 0)
                return (0);
            if (my_isnum(str[i + 1]) == 0){
                return (result * my_sign_str(str));
            }
        }
        i += 1;
    }
    return (0);
}
