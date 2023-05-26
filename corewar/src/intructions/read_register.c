/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** read_register
*/
#include "../../include/corewar.h"

int read_register(char *code, int reg_num)
{
    if (reg_num >= 1 && reg_num <= REG_NUMBER) {
        int reg_address = (reg_num - 1) * REG_SIZE;
        return read_memory_value((unsigned char *)code, reg_address, REG_SIZE);
    } else {
        return 0;
    }
}
