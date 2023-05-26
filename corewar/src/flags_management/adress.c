/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** adress
*/

#include "../../include/corewar.h"

int if_load_adress_exists_error(char **av, int i, int adress)
{
    if (my_strcmp(av[i], "-a") == 0) {
        if (av[i + 1] != NULL && is_number(av[i + 1]) != 0) {
            write(2, "The load_adress doesn't ", 24);
            write(2, "exist or is not the number.\n", 28);
            return 1;
        }
        if (adress != -1) {
            write(2, "There is more than one -a flag.\n", 32);
            return 1;
        }
    }
    return 0;
}

int load_adress_flag(char **av, int i, int load_adress)
{
    if (my_strcmp(av[i], "-a") == 0) {
        if (av[i + 1] != NULL) {
            load_adress = my_getnbr(av[i + 1]);
            return load_adress;
        }
    }
    return load_adress;
}

int if_load_adress_exists(char **av, int *i)
{
    if (my_strcmp(av[*i], "-a") == 0) {
        *i = *i + 1;
        if (av[*i] != NULL) {
            return 1;
        }
    }
    return 0;
}
