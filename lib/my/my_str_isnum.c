/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** returns 1 if string only contains digits and 0 otherwise
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return (1);
    while (str[i] != '\0'){
        if (str[i] >= '0' && str[i] < '9'){
        } else{
            return (0);
        }
        i += 1;
    }
    return (1);
}
