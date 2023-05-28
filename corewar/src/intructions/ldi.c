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
        *(arg->out_address) = 1;
    } else if (arg->arg_type == T_DIR) {
        value = read_memory_value(arg->memory,
            arg->address % MEM_SIZE, DIR_SIZE);
        *(arg->out_address) = DIR_SIZE;
    } if (arg->arg_type == T_IND) {
        int offset = read_memory_value(arg->memory,
            arg->address % MEM_SIZE, IND_SIZE);
        int effective_address = (arg->champion->pc + offset) % MEM_SIZE;
        value = read_memory_value(arg->memory, effective_address, REG_SIZE);
        *(arg->out_address) = IND_SIZE;
    }
    return value;
}

void indirect_load_fonction(corewar_t *corewar, champ_t *champion)
{
    int address = 0;
    int encod_byte = (unsigned char)corewar->mem[(champion->pc + 1) % MEM_SIZE];
    int arg1_type = (encod_byte >> 6) & 0b11;
    int arg2_type = (encod_byte >> 4) & 0b11;
    int arg3_type = (encod_byte >> 2) & 0b11;

    argument_t arg1 = {corewar->mem, champion->pc + 2, arg1_type,
        &address, champion};
    argument_t arg2 = {corewar->mem, champion->pc + 2 + address,
        arg2_type, &address, champion};
    argument_t arg3 = {corewar->mem, champion->pc + 2 + address,
        arg3_type, &address, champion};
    int val1 = read_argument_value(&arg1);
    int val2 = read_argument_value(&arg2);
    int val3 = read_argument_value(&arg3);
    if (val3 < 1 || val3 > REG_NUMBER) return;
    address = (champion->pc + ((val1 + val2) % IDX_MOD)) % MEM_SIZE;
    champion->reg[val3 - 1] = read_memory_value(corewar->mem, address,REG_SIZE);
    champion->carry = (champion->reg[val3 - 1] == 0);
    champion->pc += 2 + address;
}
