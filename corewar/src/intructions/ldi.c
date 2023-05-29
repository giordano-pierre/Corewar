/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** ldi
*/
#include "../../include/corewar.h"

int read_argument_value(argument_t *arg)
{
    int value = 0;

    if (arg->arg_type == T_REG) {
        int reg_num = (unsigned char)arg->memory[arg->address % MEM_SIZE];
        value = arg->champion->reg[reg_num - 1];
        *(arg->out_address) += 1;
    } else if (arg->arg_type == T_DIR) {
        value = read_memory_value(arg->memory,
            arg->address % MEM_SIZE, IND_SIZE);
        *(arg->out_address) += IND_SIZE;
    } if (arg->arg_type == T_IND) {
        int offset = read_memory_value(arg->memory,
            arg->address % MEM_SIZE, IND_SIZE);
        int effective_address = (arg->champion->pc + offset) % MEM_SIZE;
        value = read_memory_value(arg->memory, effective_address, REG_SIZE);
        *(arg->out_address) += IND_SIZE;
    }
    return value;
}

int get_param_value_bis(corewar_t *corewar, champ_t *champion,
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
        res = read_memory_value(corewar->mem,
        (champion->pc + *pc_size) % MEM_SIZE, 2);
        *pc_size = *pc_size + 2;
    } else {
        tmp = read_memory_value(corewar->mem,
        (champion->pc + *pc_size)  % MEM_SIZE, 2);
        res = read_memory_value(corewar->mem,
        (champion->pc + tmp) % MEM_SIZE, 4);
        *pc_size = *pc_size + 2;
    }
    return res;
}

void indirect_load_fonction(corewar_t *corewar, champ_t *champion)
{
    int pc_size = 2;
    int val1 = get_param_value_bis(corewar, champion, 0, &pc_size);
    int val2 = get_param_value_bis(corewar, champion, 1, &pc_size);
    int val3 = corewar->mem[(champion->pc + pc_size) % MEM_SIZE];
    my_printf("%d\n", val1);
    my_printf("%d\n", val2);
    my_printf("%d\n", val3);
    my_printf("%d\n", champion->pc);
    int address = (champion->pc + ((val1 + val2) % IDX_MOD)) % MEM_SIZE;
    champion->reg[val3 - 1] = corewar->mem[address];
    champion->carry = (champion->reg[val3 - 1] == 0);
    champion->pc = champion->pc + pc_size % MEM_SIZE;
}
