/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** concatenates n characters of src string
*/

int my_strlen(char const *);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int len = my_strlen(dest);

    if (nb < 0)
        nb = -nb;
    while (src[i] != '\0' && i < nb){
        dest[len + i] = src[i];
        i += 1;
    }
    dest[len + i] = '\0';
    return (dest);
}
