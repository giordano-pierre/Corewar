/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** zjump
*/

#include "../../include/corewar.h"

void zjump_function(champ_t *champion, corewar_t *corewar)
{
    int pc_size = 3;
    if (champion->carry == 0) {
        champion->pc = (champion->pc + pc_size) % MEM_SIZE;
        return;
    }
    int var_1 = read_memory_value(corewar->mem, (champion->pc + 1)
    % MEM_SIZE, 2);
    if (champion->carry == 1)
        champion->pc = (champion->pc + (var_1 % IDX_MOD)) % MEM_SIZE;
    return;
}
