/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** struct
*/
#include "../include/corewar.h"

corewar_t *create_base(void)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    corewar->cycle_to_die = CYCLE_TO_DIE;
    corewar->dump = -1;
    corewar->last_live = -1;
    corewar->mem = NULL;
    corewar->nbr_live = NBR_LIVE;
    corewar->warriors = malloc(sizeof(champ_t *));
    corewar->warriors[0] = NULL;
    corewar->nb_live = 0;
    corewar->nb_cycle = 1;
    return corewar;
}

void print_reg(int reg[REG_NUMBER])
{
    for (int i = 0; i < REG_NUMBER; i++) {
        my_printf("%d : ", reg[i]);
    }
    my_printf("\n");
}

void print_champ(champ_t **warriors)
{
    for (int i = 0; warriors[i]; i++) {
        my_printf("%s: %d, %d\n", warriors[i]->file, warriors[i]->nb_prog,
        warriors[i]->adress);
    }
}
