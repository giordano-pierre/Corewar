/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** lldi
*/
#include "../../include/corewar.h"

void long_indirect_load_fonction(corewar_t *corewar, champ_t *champion)
{
    int pc_size = 2;
    int val1 = get_param_value_bis(corewar, champion, 0, &pc_size);
    int val2 = get_param_value_bis(corewar, champion, 1, &pc_size);
    int val3 = corewar->mem[(champion->pc + pc_size) % MEM_SIZE];
    my_printf("%d\n", val1);
    my_printf("%d\n", val2);
    my_printf("%d\n", val3);
    my_printf("%d\n", champion->pc);
    int address = (champion->pc + (val1 + val2)) % MEM_SIZE;
    champion->reg[val3 - 1] = corewar->mem[address];
    champion->carry = (champion->reg[val3 - 1] == 0);
    champion->pc = champion->pc + pc_size % MEM_SIZE;
}
