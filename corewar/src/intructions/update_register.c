/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** update_register
*/
#include "../../include/corewar.h"

void update_register(int reg_num, int value, champ_t *champion)
{
    if (reg_num >= 1 && reg_num <= REG_NUMBER) {
        champion->reg[reg_num - 1] = value;
        champion->carry = (value == 0);
    }
}
