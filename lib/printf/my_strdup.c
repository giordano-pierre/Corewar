/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** task01
*/

#include "include/my_printf.h"

char *my_strdup(char const *src)
{
    int i = 0;
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * (len + 1));

    for (i = 0; src[i] != '\0'; i++) {
        str[i] = src[i];
    }
    str[i] = '\0';
    return (str);
}
