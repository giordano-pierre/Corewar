/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** and
*/

#include "../../include/corewar.h"

int get_param_value(corewar_t *corewar, champ_t *champion,
int param, int *pc_size)
{
    int encoding_byte = corewar->mem[(champion->pc + 1) % MEM_SIZE];
    int res;
    int tmp;

    if (((encoding_byte >> (6 - (2 * param))) & 0b11) == T_REG) {
        tmp = corewar->mem[(champion->pc + *pc_size) % MEM_SIZE];
        res = champion->reg[tmp - 1];
        *pc_size = *pc_size + 1;
    } else if (((encoding_byte >> (6 - (2 * param))) & 0b11) == T_DIR) {
        res = read_memory_value(corewar->mem, champion->pc + *pc_size, 4);
        *pc_size = *pc_size + 4;
    } else {
        tmp = read_memory_value(corewar->mem, champion->pc + *pc_size, 2);
        res = read_memory_value(corewar->mem, champion->pc + tmp, 4);
        *pc_size = *pc_size + 2;
    }
    return res;
}

void and_function(corewar_t *corewar, champ_t *champion)
{
    int pc_size = 2;
    if (good_arg_bis(corewar, champion))
        return;
    int var_1 = get_param_value(corewar, champion, 0, &pc_size);
    int var_2 = get_param_value(corewar, champion, 1, &pc_size);
    my_printf("%d - %d\n", var_1, var_2);
    int reg_dst_num = corewar->mem[(champion->pc + pc_size) % MEM_SIZE];
    if (reg_dst_num >= 1 && reg_dst_num <= REG_NUMBER)
        champion->reg[reg_dst_num - 1] = var_1 && var_2;
    if (champion->reg[reg_dst_num - 1] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += pc_size;
}
