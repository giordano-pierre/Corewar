/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** toolbox
*/
#include "../include/asm.h"

ssize_t my_strlen_long(char const *str)
{
    ssize_t cpt;
    cpt = 0;

    while (str[cpt] != '\0') {
        cpt++;
    }
    return cpt;
}

int have_file_point_s(const char *str)
{
    while (*str != '\0') {
        if (*str == '.' && *(str + 1) == 's') {
            return 1;
        }
        str++;
    }
    return 0;
}
