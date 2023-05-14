/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** print
*/
#include "../include/asm.h"

void print_one_code(int nb, int size, FILE *fd)
{
    int new = inverse_magic(nb);
    new = new >> ((4 - size) * 8);
    fwrite(&new, 1, size, fd);
}

void print_all_code(instruct_t **info, FILE *fd)
{
    for (int i = 0; info[i] != NULL; i++) {
        print_one_code(info[i]->code, info[i]->size, fd);
        if (info[i]->bin != 0)
            print_one_code(info[i]->bin, info[i]->size, fd);
    }
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

void print_label(label_t **labels)
{
    for (int i = 0; labels[i]; i++)
        my_printf("\nlabel: %s\nnb: %d\n", labels[i]->name, labels[i]->nb);
}

void print_struct(instruct_t **info)
{
    for (int i = 0; info[i]; i++) {
        my_printf("\ninst: %d\ncode: %d\n", info[i]->inst, info[i]->code);
        my_printf("size: %d\n", info[i]->size);
        if (info[i]->label)
            my_printf("label: %s\n", info[i]->label);
        if (info[i]->bin != 0)
            my_printf("bin: %d\n", info[i]->bin);
    }
}
