/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** free
*/
#include "../include/corewar.h"

void free_champ(champ_t **warriors)
{
    if (warriors == NULL)
        return;
    for (int i = 0; warriors[i] != NULL; i++) {
        if (warriors[i]->file)
            free(warriors[i]->file);
        if (warriors[i]->name)
            free(warriors[i]->name);
        if (warriors[i]->comment)
            free(warriors[i]->comment);
        if (warriors[i]->code)
            free(warriors[i]->code);
        free(warriors[i]);
    }
    free(warriors);
}

void free_base(corewar_t *base)
{
    if (base == NULL)
        return;
    if (base->mem)
        free(base->mem);
    if (base->last_live)
        free(base->last_live);
    if (base->warriors)
        free_champ(base->warriors);
    free(base);
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
