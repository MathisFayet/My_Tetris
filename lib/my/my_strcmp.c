/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare a string to another, character by character
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'){
        i += 1;
    }
    if (s1[i] > s2[i]){
        return (1);
    } else if (s2[i] > s1[i]){
        return (-1);
    }
    return (0);
}
