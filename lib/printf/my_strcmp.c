/*
** EPITECH PROJECT, 2022
** day07 task01
** File description:
** lib
*/

int	my_strcmp(char *s1, char const *s2)
{
    int p = 0;
    while ((s1[p] == s2[p]) && (s1[p] != '\0') && (s2[p] != '\0')) {
        p++;
    }
    return (s1[p] - s2[p]);
}
