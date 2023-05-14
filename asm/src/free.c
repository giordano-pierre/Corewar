/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** free
*/
#include "../include/asm.h"

void free_inst(instruct_t **inst)
{
    if (inst == NULL)
        return;
    for (int i = 0; inst[i] != NULL; i++) {
        if (inst[i]->label)
            free(inst[i]->label);
        free(inst[i]);
    }
    free(inst);
}

void free_asm(asm_t *my_asm)
{
    if (my_asm->old_label)
        free(my_asm->old_label);
    free_array(my_asm->tab_index);
    free_array(my_asm->tab_no_bin);
    free(my_asm);
}

void free_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

void free_label(label_t **labels)
{
    if (labels == NULL)
        return;
    for (int i = 0; labels[i]; i++)
        free(labels[i]);
    free(labels);
}
