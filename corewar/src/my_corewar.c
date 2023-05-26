/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** my_corewar
*/
#include "../include/corewar.h"

int all_is_dead(champ_t **warriors)
{
    for (int i = 0; warriors[i]; i++) {
        if (warriors[i]->is_alive != -1)
            return 1;
    }
    return 0;
}

void exec_funct(corewar_t *corewar, champ_t *champion)
{
    if (champion->sleep > 0) {
        champion->sleep--;
        return;
    }
}

void kill_prog(corewar_t *corewar)
{
    corewar->nb_cycle = 0;
    for (int i = 0; corewar->warriors[i]; i++) {
        if (corewar->warriors[i]->is_alive != 1)
            corewar->warriors[i]->is_alive = -1;
    }
}

void print_winner(corewar_t *corewar)
{
    for (int i = 0; corewar->warriors[i]; i++) {
        if (corewar->warriors[i]->nb_prog == corewar->last_live) {
            my_printf("The player %d(%s) has won.\n",
            corewar->warriors[i]->nb_prog, corewar->warriors[i]->name);
            return;
        }
    }
    my_printf("Nobody won the fight !\n");
}

int my_corewar(corewar_t *corewar)
{
    corewar->mem = create_mem();
    if (fill_mem(corewar->mem, corewar->warriors) == -1) {
        write(2, "corewar: Champions are superposed.\n", 35);
        return -1;
    }
    while (all_is_dead(corewar->warriors)) {
        if (corewar->nb_cycle > corewar->cycle_to_die)
            kill_prog(corewar);
        for (int i = 0; corewar->warriors[i]; i++) {
            exec_funct(corewar, corewar->warriors[i]);
        }
        corewar->nb_cycle++;
    }
    print_winner(corewar);
    return 0;
}
