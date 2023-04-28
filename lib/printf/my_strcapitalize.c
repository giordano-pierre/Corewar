/*
** EPITECH PROJECT, 2022
** day07 task01
** File description:
** lib
*/
#include <stdio.h>

char *my_str_remplace_low(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] <= 90 && str[i] >= 65) {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return (str);
}

char *my_strcapitalize(char *str)
{
    my_str_remplace_low(str);
    int i = -1;
    int nina = 1;
    while (str[(i = i + 1)] != '\0') {
        if (str[i] < 123 && str[i] > 96 && nina) {
            nina = 0;
            str[i] = str[i] - 32;
        }
        if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
            nina = 1;
    }
    return (str);
}
