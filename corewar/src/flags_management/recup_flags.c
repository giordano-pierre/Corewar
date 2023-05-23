/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** recup_flags
*/

#include "../../include/corewar.h"

int recup_flags(char **av)
{
    int nb_c;
    int prog_number;
    for (int i = 1; av[i] != NULL; i++) {
        if (my_strcmp(av[i], "-dump") == 0) {
            if (av[i + 1 != NULL])
                nb_c = my_getnbr(av[i + 1]);
            printf("%d\n", nb_c);
        }
        if (my_strcmp(av[i], "-n") == 0) {
            if (av[i + 1 != NULL])
                prog_number = my_getnbr(av[i + 1]);
            printf("pro : %d\n", prog_number);
        }
        if (my_strcmp(av[i], "-a") == 0) {
            if (av[i + 1 != NULL])
                printf("%s\n", av[i + 1]);
        }
    }
    return 0;
}