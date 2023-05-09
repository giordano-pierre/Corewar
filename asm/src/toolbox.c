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
