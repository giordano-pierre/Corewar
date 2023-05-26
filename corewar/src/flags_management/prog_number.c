/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** prog_number
*/

#include "../../include/corewar.h"

int if_prog_number_exists_error(char **av, int i, int prog_nb)
{
    if (my_strcmp(av[i], "-n") == 0) {
        if (av[i + 1] != NULL && is_number(av[i + 1]) != 0) {
            write(2, "The prog number doesn't ", 24);
            write(2, "exist or is not the number.\n", 28);
            return 1;
        }
        if (prog_nb != - 1) {
            write(2, "There is more than one -n.\n", 27);
            return 1;
        }
    }
    return 0;
}

int if_prog_number_exists(char **av, int *i)
{
    if (my_strcmp(av[*i], "-n") == 0) {
        *i = *i + 1;
        if (av[*i] != NULL) {
            return 1;
        }
    }
    return 0;
}

int prog_number_flag(char **av, int i, int prog_nb)
{
    if (my_strcmp(av[i], "-n") == 0) {
        if (av[i + 1] != NULL) {
            prog_nb = my_getnbr(av[i + 1]);
            return prog_nb;
        }
    }
    return prog_nb;
}
