/*
** EPITECH PROJECT, 2022
** day06 task5
** File description:
** str str
*/
#include <stdio.h>
#include "include/my_printf.h"

char *my_strstr(char const *str, char const *to_find)
{
    int x = my_strlen(to_find);
    while (*str) {
        if (my_strncmp(str, to_find, x) == 0)
            return (char*)str;
        str = str + 1;
    }
    return NULL;
}
