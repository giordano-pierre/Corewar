/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** lldi
*/
#include "../../include/corewar.h"

void long_indirect_load_fonction(corewar_t *corewar, champ_t *champion)
{
    int value1 = 0;
    int value2 = 0;
    int encoding1 = (unsigned char)corewar->mem[champion->pc + 1];
    int encoding2 = (unsigned char)corewar->mem[champion->pc + 2];

    if (encoding1 == T_DIR)
        value1 = read_memory_value(corewar->mem, champion->pc + 2, DIR_SIZE);
    if (encoding1 == T_IND) {
        int address = read_memory_value(corewar->mem, champion->pc +
            2, IND_SIZE);
        value1 = read_memory_value(corewar->mem, address, DIR_SIZE);
    } if (encoding1 == T_REG) {
        value1 = read_register(champion->code, read_memory_value(corewar->mem,
            champion->pc + 2, 1));
    }
    value2 = param_two(corewar, champion, encoding2, value2);
    update_final_var(corewar, champion, value1, value2);
}
