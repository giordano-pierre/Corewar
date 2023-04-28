/*
** EPITECH PROJECT, 2022
** day 4 task02
** File description:
** ounts and returns the number of characters found in the string
*/
#include "include/my_printf.h"

int my_putstr(char const *str)
{
    int nina = 0;
    while (str[nina] != '\0') {
        my_putchar(str[nina]);
        nina++;
    }
    return (0);
}
