/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** sub
*/

#include "../../include/corewar.h"

void sub_function(champ_t *champion, corewar_t *corewar)
{
    if (good_arg(corewar, champion))
        return;
    int reg_dst_num = corewar->mem[(champion->pc + 2) % MEM_SIZE];
    int reg_src1_num = corewar->mem[(champion->pc + 2 + 1) % MEM_SIZE];
    int reg_src2_num = corewar->mem[(champion->pc + 2 + 1 + 1) % MEM_SIZE];
    if (reg_dst_num >= 1 && reg_dst_num <= REG_NUMBER &&
        reg_src1_num >= 1 && reg_src1_num <= REG_NUMBER &&
        reg_src2_num >= 1 && reg_src2_num <= REG_NUMBER) {
        champion->reg[reg_dst_num - 1] = champion->reg[reg_src2_num - 1] -
            champion->reg[reg_src1_num - 1];
    }
    if (champion->reg[reg_dst_num - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += 5;
}
