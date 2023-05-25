/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** live
*/

#include "../../include/corewar.h"

void print_live(champ_t *champion, corewar_t *corewar)
{
    my_printf("The player %d",champion->nb_prog);
    my_printf("(%s) is alive\n", champion->name);
    champion->is_alive = 1;
    if (corewar->last_live == NULL) {
        corewar->last_live = my_strdup(champion->name);
    } else {
        free(corewar->last_live);
        corewar->last_live = my_strdup(champion->name);
    }
}

int get_adrr(champ_t *champion)
{
    int adrr = (champion->adress + champion->pc) % MEM_SIZE;
    if (adrr < 0) {
        adrr += MEM_SIZE;
    }
    return adrr;
}

int live_fonction(champ_t *champion, corewar_t *corewar)
{
    print_live(champion, corewar);
    return 0;
}
