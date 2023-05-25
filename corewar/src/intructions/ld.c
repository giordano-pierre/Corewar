/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** ld
*/
#include "../../include/corewar.h"
#include "../../include/struct.h"

void direct_load_fonction(corewar_t *corewar, champ_t *champion)
{
    int value;
    int reg_num;
    int encoding = (unsigned char)corewar->mem[champion->pc + 1];

    if (encoding == T_DIR) {
        value = read_memory_value(corewar->mem, champion->pc + 2, DIR_SIZE);
    } else if (encoding == T_IND) {
        int address = read_memory_value(corewar->mem,
            champion->pc + 2, IND_SIZE);
        address %= IDX_MOD;
        value = read_memory_value(corewar->mem, address, DIR_SIZE);
    }
    reg_num = (unsigned char)corewar->mem[champion->pc + 2 +
        encoding == T_DIR ? DIR_SIZE : IND_SIZE];
    update_register(reg_num, value, champion);
    champion->pc += 2 + encoding == T_DIR ? DIR_SIZE : IND_SIZE + 1;
}
