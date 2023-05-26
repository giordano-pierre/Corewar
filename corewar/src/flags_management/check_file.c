/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** check_file
*/

#include "../../include/corewar.h"

int check_file_bis(const char *filename)
{
    struct stat st;
    if (stat(filename, &st) == 0) {
        return S_ISREG(st.st_mode);
    }
    return 0;
}

int check_file(char **av)
{
    int i = 1;
    while (av[i] != NULL) {
        if (check_file_bis(av[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}
