/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** struct
*/
#include "../include/corewar.h"

corewar_t *create_base(void)
{
    corewar_t *corwar = malloc(sizeof(corewar_t));

    corwar->cycle_to_die = CYCLE_TO_DIE;
    corwar->dump = -1;
    corwar->last_live = NULL;
    corwar->mem = NULL;
    corwar->nbr_live = NBR_LIVE;
    corwar->warriors = malloc(sizeof(champ_t *));
    corwar->warriors[0] = NULL;
    return corwar;
}
