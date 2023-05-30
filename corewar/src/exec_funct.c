/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** exec_funct
*/
#include "../include/corewar.h"

int exec_funct_three(corewar_t *corewar, champ_t *champion)
{
    if (corewar->mem[champion->pc] == 6) {
        and_function(corewar, champion);
        champion->sleep = op_tab[5].nbr_cycles - 1;
        return -1;
    }
    if (corewar->mem[champion->pc] == 7) {
        or_function(corewar, champion);
        champion->sleep = op_tab[6].nbr_cycles - 1;
        return -1;
    }
    if (corewar->mem[champion->pc] == 8) {
        xor_function(corewar, champion);
        champion->sleep = op_tab[7].nbr_cycles - 1;
        return -1;
    }
    if (exec_funct_four(corewar, champion) == -1)
        return -1;
    return 0;
}

int exec_funct_two(corewar_t *corewar, champ_t *champion)
{
    if (corewar->mem[champion->pc] == 3) {
        direct_store(corewar, champion);
        champion->sleep = op_tab[2].nbr_cycles - 1;
        return -1;
    }
    if (corewar->mem[champion->pc] == 4) {
        add_function(champion, corewar);
        champion->sleep = op_tab[3].nbr_cycles - 1;
        return -1;
    }
    if (corewar->mem[champion->pc] == 5) {
        sub_function(champion, corewar);
        champion->sleep = op_tab[4].nbr_cycles - 1;
        return -1;
    }
    if (exec_funct_three(corewar, champion) == -1)
        return -1;
    return 0;
}

void exec_funct(corewar_t *corewar, champ_t *champion)
{
    if (champion->is_alive == -1)
        return;
    if (champion->sleep > 0) {
        champion->sleep--;
        return;
    }
    if (corewar->mem[champion->pc] == 1) {
        live_fonction(champion, corewar);
        champion->sleep = op_tab[0].nbr_cycles - 1;
        return;
    }
    if (corewar->mem[champion->pc] == 2) {
        direct_load_fonction(corewar, champion);
        champion->sleep = op_tab[1].nbr_cycles - 1;
        return;
    }
    if (exec_funct_two(corewar, champion) == -1)
        return;
    champion->is_alive = -1;
}
