/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** recup_flags
*/

#include "../../include/corewar.h"

int dump_flag(char **av, corewar_t *corewar, int i)
{
    if (av[i + 1] != NULL) {
        corewar->dump = my_getnbr(av[i + 1]);
        if (corewar->dump == -1)
            printf("wrong nbr_cycle\n");
        printf("%d\n", corewar->dump);
    }
    return 0;
}

int recup_flags(char **av, corewar_t *corewar, champ_t *champ)
{
    corewar->dump = -1;
    for (int i = 1; av[i] != NULL; i++) {
        if (my_strcmp(av[i], "-dump") == 0) {
            dump_flag(av, corewar, i);
            // if (av[i + 1] != NULL) {
            //     corewar->dump = my_getnbr(av[i + 1]);
            //     if (corewar->dump == -1)
            //         printf("wrong nbr_cycle\n");
            //     printf("%d\n", corewar->dump);
            // }
        }
        if (my_strcmp(av[i], "-n") == 0) {
            if (av[i + 1] != NULL) {
                champ->nb_prog = my_getnbr(av[i + 1]);
                printf("pro : %d\n", champ->nb_prog);
            }
        }
        if (my_strcmp(av[i], "-a") == 0) {
            if (av[i + 1] != NULL) {
                champ->adress = my_getnbr(av[i + 1]);
                printf("%d\n", champ->adress);
            }
        }
    }
    return 0;
}