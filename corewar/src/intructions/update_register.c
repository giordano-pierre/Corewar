/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** update_register
*/
#include "../../include/corewar.h"
#include "../../include/struct.h"

void update_register(int reg_num, int value, champ_t *champion)
{
    if (reg_num >= 1 && reg_num <= REG_NUMBER) {
        int reg_address = (reg_num - 1) * REG_SIZE;
        for (int i = 0; i < REG_SIZE; i++) {
            champion->code[reg_address + i] =
            (value >> ((REG_SIZE - 1 - i) * 8)) & 0xFF;
        }
        champion->carry = (value == 0) ? 1 : 0;
    }
}
