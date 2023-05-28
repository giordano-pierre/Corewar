/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** good_register
*/
#include "../../include/corewar.h"

int good_arg(corewar_t *corewar, champ_t *champion)
{
    int encoding_byte = corewar->mem[(champion->pc + 1) % MEM_SIZE];
    int arg1_type = (encoding_byte >> 6) & 0b11;
    int arg2_type = (encoding_byte >> 4) & 0b11;
    int arg3_type = (encoding_byte >> 2) & 0b11;

    if (arg1_type != T_REG)
        return 1;
    if (arg2_type != T_REG)
        return 1;
    if (arg3_type != T_REG)
        return 1;
    return 0;
}
