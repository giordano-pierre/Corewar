/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** find_prog_number
*/

#include "../../include/corewar.h"

int give_prog_number_bis(corewar_t *corewar, int *ind)
{
    int j;
    for (j = 0; corewar->warriors[j] != NULL; j++) {
        if (*ind == corewar->warriors[j]->nb_prog) {
            *ind = *ind + 1;
            break;
        }
    }
    return j;
}

int give_prog_number(corewar_t *corewar)
{
    int i;
    int ind = 1;
    int stop = 0;
    while (stop == 0) {
        i = give_prog_number_bis(corewar, &ind);
        if (corewar->warriors[i] == NULL)
            stop = 1;
    }
    return ind;
}

void find_prog_number(corewar_t *corewar)
{
    for (int i = 0; corewar->warriors[i] != NULL; i++) {
        if (corewar->warriors[i]->nb_prog == -1) {
            corewar->warriors[i]->nb_prog = give_prog_number(corewar);
        }
    }
}
