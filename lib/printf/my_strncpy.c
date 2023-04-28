/*
** EPITECH PROJECT, 2022
** day06 task2
** File description:
** choose the number of charactere in the str chain
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int p = 0;
    while (src[p] != '\0' && p < n) {
        dest[p] = src[p];
        p = p + 1;
    }
    if (p == n) {
        dest[p] = '\0';
    }
return (dest);
}
