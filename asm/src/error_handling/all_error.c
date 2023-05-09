/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** all_error
*/

#include "../../include/asm.h"

int all_error(char **tab)
{
    if (if_name_exists(tab) != -1) {
        write(2, ".name doesn't exist\n", 20);
        return -1;
    }
    return 0;
}
