/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** exec_funct_bis
*/
#include "../include/corewar.h"

int exec_funct_six(corewar_t *corewar, champ_t *champion)
{
    if (corewar->mem[champion->pc] == 15) {
        lfork_fonction(corewar, champion);
        champion->sleep = op_tab[14].nbr_cycles - 1;
        return -1;
    }
    if (corewar->mem[champion->pc] == 16) {
        aff_function(champion, corewar);
        champion->sleep = op_tab[15].nbr_cycles - 1;
        return -1;
    }
    return 0;
}

int exec_funct_five(corewar_t *corewar, champ_t *champion)
{
    if (corewar->mem[champion->pc] == 12) {
        fork_fonction(corewar, champion);
        champion->sleep = op_tab[11].nbr_cycles - 1;
        return -1;
    }
    if (corewar->mem[champion->pc] == 13) {
        direct_long_load_fonction(corewar, champion);
        champion->sleep = op_tab[12].nbr_cycles - 1;
        return -1;
    }
    if (corewar->mem[champion->pc] == 14) {
        long_indirect_load_fonction(corewar, champion);
        champion->sleep = op_tab[13].nbr_cycles - 1;
        return -1;
    }
    if (exec_funct_six(corewar, champion) == -1)
        return -1;
    return 0;
}

int exec_funct_four(corewar_t *corewar, champ_t *champion)
{
    if (corewar->mem[champion->pc] == 9) {
        zjump_function(champion, corewar);
        champion->sleep = op_tab[8].nbr_cycles - 1;
        return -1;
    }
    if (corewar->mem[champion->pc] == 10) {
        indirect_load_fonction(corewar, champion);
        champion->sleep = op_tab[9].nbr_cycles - 1;
        return -1;
    }
    if (corewar->mem[champion->pc] == 11) {
        indirect_store(corewar, champion);
        champion->sleep = op_tab[10].nbr_cycles - 1;
        return -1;
    }
    if (exec_funct_five(corewar, champion) == -1)
        return -1;
    return 0;
}
