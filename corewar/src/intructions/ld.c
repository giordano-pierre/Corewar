/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** ld
*/
#include "../../include/corewar.h"

void direct_load_fonction(corewar_t *corewar, champ_t *champion)
{
    int value;
    int reg_num;
    int encoding2 = (unsigned char)corewar->mem[(champion->pc + 1) % MEM_SIZE];

    if (encoding2 == T_DIR) {
        value = read_memory_value(corewar->mem,
            (champion->pc + 2) % MEM_SIZE, DIR_SIZE);
        reg_num = (unsigned char)corewar->mem[(champion->pc + 6) % MEM_SIZE];
        champion->pc += 7;
    } else if (encoding2 == T_IND) {
        int address = read_memory_value(corewar->mem,
            (champion->pc + 2) % MEM_SIZE, IND_SIZE);
        address = (champion->pc + (address % IDX_MOD)) % MEM_SIZE;
        value = read_memory_value(corewar->mem, address, REG_SIZE);
        reg_num = (unsigned char)corewar->mem[(champion->pc + 4) % MEM_SIZE];
        champion->pc += 5;
    }
    update_register(reg_num, value, champion);
}
