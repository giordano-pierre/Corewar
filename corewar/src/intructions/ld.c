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
        value = read_memory_value(corewar->mem, champion->pc + 2, 4);
    } else if (encoding == T_IND) {
        int address = read_memory_value(corewar->mem, champion->pc + 2, 2);
        value = read_memory_value(corewar->mem, address, 4);
    }
    reg_num = (unsigned char)corewar->mem[champion->pc + 6];
    if (reg_num >= 1 && reg_num <= champion->nb_prog) {
        int reg_address = (reg_num - 1) * 4;
        for (int i = 0; i < 4; i++) {
            champion->code[reg_address + i] = (value >> ((3 - i) * 8)) & 0xFF;
        }
        champion->carry = (value == 0) ? 1 : 0;
    }
    champion->pc += 7;
}
