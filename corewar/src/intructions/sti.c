/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** sti
*/
#include "../../include/corewar.h"

int arg_val(unsigned char *memory, int address, int arg_type,
    champ_t *champion)
{
    int value = 0;

    if (arg_type == T_REG) {
        int reg_num = (unsigned char)memory[address % MEM_SIZE];
        value = champion->reg[reg_num - 1];
    }
    if (arg_type == T_DIR)
        value = read_memory_value(memory, address % MEM_SIZE, DIR_SIZE);
    if (arg_type == T_IND) {
        int offset = (short)read_memory_value(memory, address %
            MEM_SIZE, IND_SIZE);
        int effective_address = (champion->pc + offset) % MEM_SIZE;
        value = read_memory_value(memory, effective_address, REG_SIZE);
    }
    return value;
}

int get_size(int arg_type)
{
    if (arg_type == T_REG)
        return 1;
    if (arg_type == T_DIR)
        return DIR_SIZE;
    if (arg_type == T_IND)
        return IND_SIZE;
    return 0;
}

void indirect_store(corewar_t *corewar, champ_t *champion)
{
    int reg_src_num;
    int encoding_byte = corewar->mem[(champion->pc + 1) % MEM_SIZE];
    int arg1_type = (encoding_byte >> 6) & 0b11;
    int arg2_type = (encoding_byte >> 4) & 0b11;
    int arg3_type = (encoding_byte >> 2) & 0b11;

    if (arg1_type == T_REG) {
        reg_src_num = corewar->mem[(champion->pc + 2) % MEM_SIZE];
    } else
        return;
    int val1 = arg_val(corewar->mem, champion->pc + 2, arg2_type, champion);
    int val2 = arg_val(corewar->mem, champion->pc + 2 + get_size(arg2_type),
        arg3_type, champion);
    int val3 = arg_val(corewar->mem, champion->pc + 2 + get_size(arg2_type)
        + get_size(arg3_type), T_REG, champion);
    int address = (champion->pc + ((val2 + val3) % IDX_MOD)) % MEM_SIZE;
    write_mem(corewar->mem, address, REG_SIZE, champion->reg[reg_src_num - 1]);
    champion->pc += 2 + get_size(arg2_type) +
        get_size(arg3_type) + get_size(T_REG);
}
