/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** reproduce strncmp functionn
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int diff = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i <= (n - 1)){
        i += 1;
    }
    if (s1[i] > s2[i]){
        diff = s1[i] - s2[i];
        return (diff);
    } else if (s2[i] > s1[i]){
        diff = s1[i] - s2[i];
        return (diff);
    }
    return (0);
}
