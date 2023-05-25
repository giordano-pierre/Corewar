/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** array
*/
#include "../include/corewar.h"

void print_array(char **array)
{
    if (array == NULL)
        return;
    int i = 0;
    for (; array[i + 1] != NULL; i++) {
        write(1, array[i], my_strlen(array[i]));
        write(1, "\n", 1);
    }
    write(1, array[i], my_strlen(array[i]));
}
