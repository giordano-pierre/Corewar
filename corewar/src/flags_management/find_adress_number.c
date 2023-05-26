/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** find_adress_number
*/

#include "../../include/corewar.h"

int find_adress_number(corewar_t *corewar)
{
    int fill = 0;
    int empty = 0;
    for (int i = 0; corewar->warriors[i] != NULL; i++) {
        if (corewar->warriors[i]->adress == -1)
            empty++;
        else
            fill++;
    }
    if (empty != 0 && fill != 0) {
        write(2, "The adress -a is missing.\n", 26);
        return 1;
    }
    return 0;
}

void fill_adress_number(corewar_t *corewar, int nb_f)
{
    if (corewar->warriors[0]->adress != -1)
        return;
    for (int i = 0; corewar->warriors[i] != NULL; i++) {
        corewar->warriors[i]->adress = (MEM_SIZE / nb_f) * i;
    }
}
