/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** error_flag
*/

#include "../../include/corewar.h"

int flags_error(char **av, int i)
{
    if (dump_flag_error(av, i) != 0)
        return 1;
    if (if_prog_number_exists_error(av, i) != 0)
        return 1;
    if (if_load_adress_exists_error(av, i) != 0)
        return 1;
    return 0;
}

int error_file_max(int nb_file)
{
    if (nb_file > 4) {
        write(2, "There is more than 4 files to fight.\n", 37);
        return 1;
    }
    return 0;
}
