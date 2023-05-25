/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** lld
*/
#include "../../include/corewar.h"

void direct_long_load_fonction(corewar_t *corewar, champ_t *champion)
{
    int value;
    int reg_num;
    int arg_type = (unsigned char)corewar->mem[(champion->pc + 1) % MEM_SIZE];

    if (arg_type == T_DIR) {
        value = read_memory_value(corewar->mem,
            (champion->pc + 2) % MEM_SIZE, DIR_SIZE);
        reg_num = (unsigned char)corewar->mem[(champion->pc + 6) % MEM_SIZE];
        champion->pc += 7;
    } else if (arg_type == T_IND) {
        int address = read_memory_value(corewar->mem,
            (champion->pc + 2) % MEM_SIZE, IND_SIZE);
        value = read_memory_value(corewar->mem,
            (champion->pc + address) % MEM_SIZE, REG_SIZE);
        reg_num = (unsigned char)corewar->mem[(champion->pc + 2 + IND_SIZE) %
            MEM_SIZE];
        champion->pc += 3 + IND_SIZE;
    }
    update_register(reg_num, value, champion);
}
