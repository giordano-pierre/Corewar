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

void free_corewar(corewar_t *corwar)
{
    if (corwar == NULL)
        return;
    if (corwar->mem)
        free(corwar->mem);
    if (corwar->warriors)
        free_champ(corwar->warriors);
    free(corwar);
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
