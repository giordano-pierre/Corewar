/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** zjump
*/

#include "../../include/corewar.h"

void zjump_function(champ_t *champion, corewar_t *corewar)
{
    int pc_size = 2;
    int encoding_byte = corewar->mem[(champion->pc + 1) % MEM_SIZE];
    int arg1_type = (encoding_byte >> 6) & 0b11;
    if (arg1_type != T_DIR)
        return 1;
    int var_1 = get_param_value(corewar, champion, 0, &pc_size);
    if (champion->carry == 0)
        champion->pc += pc_size;
    if (champion->carry == 1)
        champion->pc = var_1;
    return;
}
