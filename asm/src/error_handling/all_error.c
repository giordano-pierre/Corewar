/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** all_error
*/

#include "../../include/asm.h"

int all_error(char **tab)
{
    if (if_name_exists(tab) != 0) {
        return -1;
    }
    if (if_comment_exists(tab) != 0) {
        return -1;
    }
    return 0;
}
