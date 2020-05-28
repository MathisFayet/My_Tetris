/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverses a string
*/

int my_strlen(char const *);

char *my_revstr(char *str)
{
    int i = 0;
    char save;
    int length = my_strlen(str);

    while (i < (length/2)){
        save = str[i];
        str[i] = str[length-1-i];
        str[length-1-i] = save;
        i += 1;
    }
    return (str);
}
