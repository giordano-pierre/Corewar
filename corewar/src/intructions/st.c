/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** st
*/
#include "../../include/corewar.h"

int read_two_arg_st(unsigned char *memory, int pc)
{
    int encoding_byte = memory[(pc + 1) % MEM_SIZE];
    int arg2_type = (encoding_byte >> 4) & 0b11;

    if (arg2_type == T_IND) {
        return (short)read_memory_value(memory, (pc + 3) % MEM_SIZE, IND_SIZE);
    } else {
        return 0;
    }
}

void write_into_mem_st(corewar_t *corewar, champ_t *champion,
    int r_src, int r_dst)
{
    int reg_src_value = champion->reg[r_src - 1];
    int reg_dst_address = champion->pc + 2 + r_dst;
    write_mem(corewar->mem, reg_dst_address, REG_SIZE, reg_src_value);
}

void use_arg2(corewar_t *corewar, champ_t *champion, int r_src, int arg2_type)
{
    int r_dst;

    if (arg2_type == T_REG) {
        r_dst = corewar->mem[(champion->pc + 2) % MEM_SIZE];
    } else if (arg2_type == T_IND) {
        int arg2_value = read_two_arg_st(corewar->mem, champion->pc);
        int adress = (champion->pc + arg2_value % IDX_MOD) % MEM_SIZE;
        write_mem(corewar->mem, adress, REG_SIZE, champion->reg[r_src - 1]);
        champion->pc += 3;
        champion->carry = (champion->reg[r_src - 1] == 0) ? 1 : 0;
        return;
    } else {
        champion->pc += 2;
        return;
    }
    if (r_src >= 1 && r_src <= REG_NUMBER && r_dst >= 1 && r_dst <= REG_NUMBER)
        write_into_mem_st(corewar, champion, r_src, r_dst);
    champion->pc += 2;
    champion->carry = (champion->reg[r_src - 1] == 0) ? 1 : 0;
}

void direct_store(corewar_t *corewar, champ_t *champion)
{
    int r_src;
    int encoding_byte = corewar->mem[(champion->pc + 1) % MEM_SIZE];
    int arg1_type = (encoding_byte >> 6) & 0b11;
    int arg2_type = (encoding_byte >> 4) & 0b11;

    if (arg1_type == T_REG) {
        r_src = corewar->mem[(champion->pc + 2) % MEM_SIZE];
    } else {
        champion->pc += 2;
        return;
    }
    use_arg2(corewar, champion, r_src, arg2_type);
    champion->pc += 2;
}
