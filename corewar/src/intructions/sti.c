/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** sti
*/
#include "../../include/corewar.h"

void indirect_store(corewar_t *corewar, champ_t *champion)
{
    int pc_size = 3;
    int num_reg = corewar->mem[(champion->pc + 2) % MEM_SIZE];
    int res = champion->reg[num_reg - 1];
    int var_1 = get_param_value_bis(corewar, champion, 1, &pc_size);
    int var_2 = get_param_value_bis(corewar, champion, 2, &pc_size);
    int adress = (champion->pc + ((var_1 + var_2) % IDX_MOD)) % MEM_SIZE;
    write_mem(corewar->mem, adress, 4, res);
    if (num_reg == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc = (champion->pc + pc_size) % MEM_SIZE;
}
