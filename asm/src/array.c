/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** array
*/
#include "../include/asm.h"

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

int my_structlen(instruct_t **info)
{
    int size = 0;

    for (int i = 0; info[i] != NULL; i++) {
        size = size + info[i]->size;
        if (info[i]->bin != 0)
            size++;
    }
    return size;
}

int my_arraylen(char **array)
{
    int row = 0;

    for (int i = 0; array[i] != NULL; i++)
        row++;
    return row;
}

int add_instr(asm_t *my_asm, int code, int inst, int size)
{
    int len = 0;
    instruct_t **new = NULL;

    while (my_asm->info[len] != NULL)
        len++;
    new = malloc(sizeof(instruct_t *) * (len + 2));
    for (int i = 0; i < len; i++)
        new[i] = my_asm->info[i];
    new[len] = malloc(sizeof(instruct_t));
    new[len]->code = code;
    new[len]->inst = inst;
    new[len]->size = size;
    new[len]->label = my_asm->old_label;
    new[len]->bin = 0;
    my_asm->old_label = NULL;
    new[len + 1] = NULL;
    free(my_asm->info);
    my_asm->info = new;
    return len;
}

label_t **add_label(label_t **labels, char *name, int nb)
{
    int len = 0;
    label_t **new = NULL;

    while (labels[len] != NULL)
        len++;
    new = malloc(sizeof(label_t *) * (len + 2));
    for (int i = 0; i < len; i++)
        new[i] = labels[i];
    new[len] = malloc(sizeof(label_t));
    new[len]->name = name;
    new[len]->nb = nb;
    new[len + 1] = NULL;
    free(labels);
    return new;
}
