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
    corewar->last_live = NULL;
    corewar->mem = NULL;
    corewar->nbr_live = NBR_LIVE;
    corewar->warriors = malloc(sizeof(champ_t *));
    corewar->warriors[0] = NULL;
    return corewar;
}

void print_reg(int reg[REG_NUMBER])
{
    for (int i = 0; i < REG_NUMBER; i++) {
        my_printf("%d : ", reg[i]);
    }
    my_printf("\n");
}
