/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** struct
*/
#include "../include/corewar.h"

corewar_t *create_base(void)
{
    corewar_t *base = malloc(sizeof(corewar_t));

    base->cycle_to_die = CYCLE_TO_DIE;
    base->dump = -1;
    base->last_live = NULL;
    base->mem = NULL;
    base->nbr_live = NBR_LIVE;
    base->warriors = malloc(sizeof(champ_t *));
    base->warriors[0] = NULL;
    return base;
}
