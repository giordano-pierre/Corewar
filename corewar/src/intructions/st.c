/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** st
*/
#include "../../include/corewar.h"

void use_arg2(corewar_t *corewar, champ_t *champion, int reg_src_num)
{
    int reg_dst_nm;
    int encod_byte = (unsigned char)corewar->mem[(champion->pc + 1) % MEM_SIZE];
    int arg2_type = (encod_byte >> 4) & 0b11;

    if (arg2_type == T_REG) {
        reg_dst_nm = (unsigned char)corewar->mem[(champion->pc + 2) % MEM_SIZE];
    } else if (arg2_type == T_IND) {
        int offset = read_memory_value(corewar->mem,
            (champion->pc + 2) % MEM_SIZE, IND_SIZE);
        int address = (champion->pc + offset % IDX_MOD) % MEM_SIZE;
        write_memory_value(corewar->mem, address, REG_SIZE,
            champion->reg[reg_src_num - 1]);
        champion->pc += 2 + IND_SIZE;
        return;
    } else
        return;
    if (reg_src_num >= 1 && reg_src_num <= REG_NUMBER && reg_dst_nm >= 1
        && reg_dst_nm <= REG_NUMBER)
        champion->reg[reg_dst_nm - 1] = champion->reg[reg_src_num - 1];
    champion->pc += 1;
}

void direct_store(corewar_t *corewar, champ_t *champion)
{
    int reg_src_num;
    int encod_byte = (unsigned char)corewar->mem[(champion->pc + 1) % MEM_SIZE];
    int arg1_type = (encod_byte >> 6) & 0b11;

    if (arg1_type == T_REG) {
        reg_src_num = (unsigned char)corewar->mem[(champion->pc + 2)
            % MEM_SIZE];
    } else {
        return;
    }
    use_arg2(corewar, champion, reg_src_num);
    champion->pc += 2 + 1;
}
