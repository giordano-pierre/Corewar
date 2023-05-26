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
        my_printf("lfork\n");
        champion->sleep = op_tab[14].nbr_cycles - 1;
        return -1;
    }
    if (corewar->mem[champion->pc] == 16) {
        my_printf("aff\n");
        champion->sleep = op_tab[15].nbr_cycles - 1;
        return -1;
    }
    return 0;
}

int exec_funct_five(corewar_t *corewar, champ_t *champion)
{
    if (corewar->mem[champion->pc] == 12) {
        my_printf("fork\n");
        champion->sleep = op_tab[11].nbr_cycles - 1;
        return -1;
    }
    if (corewar->mem[champion->pc] == 13) {
        my_printf("lld\n");
        champion->sleep = op_tab[12].nbr_cycles - 1;
        return -1;
    }
    if (corewar->mem[champion->pc] == 14) {
        my_printf("lldi\n");
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
        my_printf("zjump\n");
        champion->sleep = op_tab[8].nbr_cycles - 1;
        return -1;
    }
    if (corewar->mem[champion->pc] == 10) {
        my_printf("ldi\n");
        champion->sleep = op_tab[9].nbr_cycles - 1;
        return -1;
    }
    if (corewar->mem[champion->pc] == 11) {
        my_printf("sti\n");
        champion->sleep = op_tab[10].nbr_cycles - 1;
        return -1;
    }
    if (exec_funct_five(corewar, champion) == -1)
        return -1;
    return 0;
}
