/*
** EPITECH PROJECT, 2023
** Corewar
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
        free(warriors[i]);
    }
    free(warriors);
}
