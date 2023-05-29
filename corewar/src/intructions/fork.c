/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** fork
*/
#include "../../include/corewar.h"

void add_warrior(corewar_t *corewar, champ_t *new_champ)
{
    int i;
    champ_t **new_warriors;

    int new_size = 1;
    if (corewar->warriors != NULL) {
        while (corewar->warriors[new_size - 1] != NULL) {
            new_size++;
        }
    }
    new_warriors = malloc((new_size + 1) * sizeof(champ_t *));
    new_warriors[0] = new_champ;
    for (i = 0; i < new_size - 1; i++)
        new_warriors[i + 1] = corewar->warriors[i];
    if (corewar->warriors != NULL)
        free(corewar->warriors);
    corewar->warriors = new_warriors;
}

champ_t *create_champion(void)
{
    champ_t *champion = malloc(sizeof(champ_t));

    champion->file = NULL;
    champion->name = NULL;
    champion->comment = NULL;
    champion->code = NULL;
    champion->size = 0;
    champion->nb_prog = 0;
    champion->adress = 0;
    champion->pc = 0;
    champion->carry = 0;
    champion->is_alive = 0;
    champion->sleep = 0;
    for (int i = 0; i < REG_NUMBER; i++) {
        champion->reg[i] = 0;
    }
    return champion;
}

void copy_champion_state(champ_t *src, champ_t *dest, int new_pc)
{
    dest->file = my_strdup(src->file);
    dest->name = my_strdup(src->name);
    dest->comment = my_strdup(src->comment);
    dest->code = my_strdup(src->code);
    dest->size = src->size;
    dest->nb_prog = src->nb_prog;
    dest->adress = new_pc;
    dest->pc = src->pc;
    dest->carry = src->carry;
    dest->is_alive = src->is_alive;
    dest->sleep = src->sleep;

    for (int i = 0; i < REG_NUMBER; i++) {
        dest->reg[i] = src->reg[i];
    }
}

int load_champ_fork(unsigned char *mem, champ_t *champ)
{
    int ind = champ->adress;

    for (int i = 0; i < champ->size; i++, ind++) {
        mem[ind % MEM_SIZE] = champ->code[i];
    }
    return 0;
}

void fork_fonction(corewar_t *corewar, champ_t *champion)
{
    int offset = read_memory_value(corewar->mem, (champion->pc + 1) %
        MEM_SIZE, IND_SIZE);
    int new_pc = (champion->pc + (offset % IDX_MOD)) % MEM_SIZE;
    champ_t *new_champion = create_champion();

    copy_champion_state(champion, new_champion, new_pc);
    add_warrior(corewar, new_champion);
    load_champ_fork(corewar->mem, new_champion);
    new_champion->pc += 3;
}
