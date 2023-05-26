/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** champ
*/
#include "../include/corewar.h"

champ_t **create_champ(champ_t **warriors)
{
    warriors = add_tab(warriors, (MEM_SIZE / 2), "abel.cor", 1);
    warriors = add_tab(warriors, 0, "bill.cor", 2);
    return warriors;
}

void print_champ(champ_t **warriors)
{
    for (int i = 0; warriors[i]; i++) {
        my_printf("%s: %d, %d\n", warriors[i]->file, warriors[i]->nb_prog,
        warriors[i]->adress);
    }
}
