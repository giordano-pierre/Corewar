/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** or
*/

#include "../../include/corewar.h"

void or_function(corewar_t *corewar, champ_t *champion)
{
    int pc_size = 2;
    if (good_arg_bis(corewar, champion))
        return;
    int var_1 = get_param_value(corewar, champion, 0, &pc_size);
    int var_2 = get_param_value(corewar, champion, 1, &pc_size);
    int reg_dst_num = corewar->mem[(champion->pc + pc_size) % MEM_SIZE];
    if (reg_dst_num >= 1 && reg_dst_num <= REG_NUMBER)
        champion->reg[reg_dst_num - 1] = var_1 | var_2;
    if (champion->reg[reg_dst_num - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += pc_size;
}
