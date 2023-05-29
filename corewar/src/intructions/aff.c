/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** lfork
*/

#include "../../include/corewar.h"

void aff_function(champ_t *champion, corewar_t *corewar)
{
    int re = read_register(corewar->mem[(champion->pc + 2) % MEM_SIZE], T_REG);
    char c = re % 256;
    my_printf("%c\n", c);

    if (c == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
    champion->pc += 3;
}
