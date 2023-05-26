/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** dump
*/

#include "../../include/corewar.h"

int dump_flag_error(char **av, int i)
{
    if (my_strcmp(av[i], "-dump") == 0) {
        if (av[i + 1] != NULL && is_number(av[i + 1]) != 0) {
            write(2, "The dump number doesn't ", 24);
            write(2, "exist or is not the number.\n", 28);
            return 1;
        }
    }
    return 0;
}

int dump_flag(char **av, corewar_t *corewar, int *i)
{
    if (my_strcmp(av[*i], "-dump") == 0) {
        *i = *i + 1;
        if (av[*i] != NULL) {
            corewar->dump = my_getnbr(av[*i]);
            return 1;
        }
    }
    return 0;
}
