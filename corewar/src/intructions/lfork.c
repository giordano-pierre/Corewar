/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** lfork
*/
#include "../../include/corewar.h"

void lfork_fonction(corewar_t *corewar, champ_t *champion)
{
    int offset = read_memory_value(corewar->mem, (champion->pc + 1) %
        MEM_SIZE, IND_SIZE);
    int new_pc = (champion->pc + offset) % MEM_SIZE;
    champ_t *new_champion = create_champion();

    copy_champion_state(champion, new_champion, new_pc);
    add_warrior(corewar, new_champion);
    load_champ_fork(corewar->mem, champion->adress, new_champion);
    new_champion->pc += 3;
}
