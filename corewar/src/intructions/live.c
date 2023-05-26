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
    corewar->last_live = champion->nb_prog;
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
    corewar->nbr_live++;
    if (corewar->nbr_live >= NBR_LIVE)
        corewar->cycle_to_die -= CYCLE_DELTA;
    champion->pc += 5;
    return 0;
}
