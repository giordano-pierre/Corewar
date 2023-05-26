/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** sub
*/

#include "../../include/corewar.h"

int sub_funtion(champ_t *champion, corewar_t *corewar)
{
    int adress;
    int encod_byt = (unsigned char)corewar->mem[(champion->pc + 1) % MEM_SIZE];
    int arg1_type = (encod_byt >> 6) & 0b11;
    int arg2_type = (encod_byt >> 4) & 0b11;
    int arg3_type = (encod_byt >> 2) & 0b11;
    argument_t arg1 = {corewar->mem, champion->pc + 2, arg1_type,
        &adress, champion};
    argument_t arg2 = {corewar->mem, champion->pc + 2 + adress,
        arg2_type, &adress, champion};
    argument_t arg3 = {corewar->mem, champion->pc + 2 + adress,
        arg3_type, &adress, champion};
    int frst_arg = read_argument_value(&arg1);
    int secnd_arg = read_argument_value(&arg2);
    int thrd_arg = read_argument_value(&arg3);
    int res = secnd_arg - frst_arg;
    if (res == 0) champion->carry = 1;
    else
        champion->carry = 0;
    adress = (champion->pc + ((frst_arg + secnd_arg) % IDX_MOD)) % MEM_SIZE;
    champion->pc += 5 + adress;
}