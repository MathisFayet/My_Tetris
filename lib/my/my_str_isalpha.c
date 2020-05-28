/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** returns 1 if string contains alphabetical char or 0 if contains another
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return (1);
    while (str[i] != '\0'){
        if ((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z')){
        } else {
            return (0);
        }
        i += 1;
    }
    return (1);
}
