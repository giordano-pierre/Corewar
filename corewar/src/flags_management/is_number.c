/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** is_number
*/

#include "../../include/corewar.h"

int is_number(char *str)
{
    int i = 0;

    for (; str[i]; i++) {
        if (str[i] > '9' || str[i] < '0') {
            return 1;
        }
    }

    return 0;
}
