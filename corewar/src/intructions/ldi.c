/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** ldi
*/
#include "../../include/corewar.h"

void update_final_var(corewar_t *corewar, champ_t *champion,
    int value1, int value2)
{
    int address = (champion->pc + value1 + value2) % MEM_SIZE;
    int reg_num;
    int final_value = read_memory_value(corewar->mem, address, REG_SIZE);

    reg_num = (unsigned char)corewar->mem[champion->pc + 6];
    if (reg_num >= 1 && reg_num <= REG_NUMBER) {
        int reg_address = (reg_num - 1) * REG_SIZE;
        for (int i = 0; i < REG_SIZE; i++) {
            champion->code[reg_address + i] =
                (final_value >> ((REG_SIZE - 1 - i) * 8)) & 0xFF;
        }
    }
    champion->pc += 7;
}

int param_two(corewar_t *corewar, champ_t *champion, int encoding2, int value2)
{
    if (encoding2 == T_DIR) {
        return value2 = read_memory_value(corewar->mem, champion->pc +
            4, DIR_SIZE);
    } else if (encoding2 == T_REG) {
        return value2 = read_register(champion->code,
            read_memory_value(corewar->mem, champion->pc + 4, 1));
    }
    return 0;
}

void indirect_load_fonction(corewar_t *corewar, champ_t *champion)
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
        address %= IDX_MOD;
        value1 = read_memory_value(corewar->mem, address, DIR_SIZE);
    } if (encoding1 == T_REG) {
        value1 = read_register(champion->code, read_memory_value(corewar->mem,
            champion->pc + 2, 1));
    }
    value2 = param_two(corewar, champion, encoding2, value2);
    update_final_var(corewar, champion, value1, value2);
}
