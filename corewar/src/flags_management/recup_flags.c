/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** recup_flags
*/

#include "../../include/corewar.h"

int dump_flag(char **av, corewar_t *corewar, int i)
{
    if (my_strcmp(av[i], "-dump") == 0) {
        if (av[i + 1] != NULL) {
            corewar->dump = my_getnbr(av[i + 1]);
            if (corewar->dump == -1)
                printf("wrong nbr_cycle\n");
            printf("%d\n", corewar->dump);
        }
    }
    return 0;
}

int prog_number_flag(char **av, warriors_t *warriors, int j, int i)
{
    if (my_strcmp(av[i], "-n") == 0) {
        if (av[i + 1] != NULL) {
            warriors->champ[j].nb_prog = my_getnbr(av[i + 1]);
            printf("pro : %d\n", warriors->champ[j].nb_prog);
        }
    }
    return 0;
}

int load_adress_flag(char **av, warriors_t *warriors, int i, int j)
{
    if (my_strcmp(av[i], "-a") == 0) {
        if (av[i + 1] != NULL) {
            warriors->champ[j].adress = my_getnbr(av[i + 1]);
            printf("%d\n", warriors->champ[j].adress);
        }
    }
    return 0;
}

int recup_flags(char **av, corewar_t *corewar, warriors_t *warriors)
{
    corewar->dump = -1;
    int j = 0;
    for (int i = 1; av[i] != NULL && j != 10; i++, j++) {
        dump_flag(av, corewar, i);
        prog_number_flag(av, warriors, j, i);
        load_adress_flag(av, warriors, i, j);
    }
    return 0;
}
