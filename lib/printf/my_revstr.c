/*
** EPITECH PROJECT, 2022
** day06 task03
** File description:
** reverse a string
*/
#include "include/my_printf.h"

char *my_revstr( char *str )
{
    char a;
    int b;
    int c;
    c = my_strlen(str);
    for (b = 0 ; b < c / 2 ; b++ ) {
    a = *(str + b);
    *(str + b) = *(str + c - b -1);
    *(str + c - b -1) = a;
    }
    return (str);
}
