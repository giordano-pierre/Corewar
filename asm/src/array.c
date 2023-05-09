/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** array
*/
#include "../include/asm.h"

void free_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

void print_array(char **array)
{
    if (array == NULL)
        return;
    int i = 0;
    for (; array[i] != NULL; i++) {
        write(1, array[i], my_strlen(array[i]));
    }
}

char **add_line(char **array, char *line)
{
    int size = 0;
    char **new = NULL;

    while (array[size] != NULL)
        size++;
    new = malloc(sizeof(char *) * (size + 2));
    for (int i = 0; i < size; i++)
        new[i] = array[i];
    new[size] = my_strdup(line);
    new[size + 1] = NULL;
    free(array);
    return new;
}

int my_arraylen (char **array)
{
    int row = 0;
    for (int i = 0; array[i] != NULL; i++)
        row++;
    return row;
}
