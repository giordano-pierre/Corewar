/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** lldi
*/
#include "../../include/corewar.h"

void long_indirect_load_fonction(corewar_t *corewar, champ_t *champion)
{
    int address;
    int encod_byte = (unsigned char)corewar->mem[(champion->pc + 1) % MEM_SIZE];
    int arg1_type = (encod_byte >> 6) & 0b11;
    int arg2_type = (encod_byte >> 4) & 0b11;
    int arg3_type = (encod_byte >> 2) & 0b11;

    argument_t arg1 = {corewar->mem, champion->pc + 2,
        arg1_type, &address, champion};
    argument_t arg2 = {corewar->mem, champion->pc + 2 +
        address, arg2_type, &address, champion};
    argument_t arg3 = {corewar->mem, champion->pc + 2 +
        address, arg3_type, &address, champion};
    int val1 = read_argument_value(&arg1);
    int val2 = read_argument_value(&arg2);
    int val3 = read_argument_value(&arg3);
    if (val3 < 1 || val3 > REG_NUMBER) return;
    address = (champion->pc + ((val1 + val2) % MEM_SIZE)) % MEM_SIZE;
    champion->reg[val3 - 1] = read_memory_value(corewar->mem,address, REG_SIZE);
    champion->pc += 2 + address;
}
