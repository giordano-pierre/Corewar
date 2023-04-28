/*
** EPITECH PROJECT, 2022
** day06 task01
** File description:
** str
*/

char *my_strcpy(char *dest, char const *src)
{
    int p = 0;
    while (src[p] != '\0') {
        dest[p] = src[p];
        p++;
    }
    dest[p] = '\0';
    return (dest);
}
