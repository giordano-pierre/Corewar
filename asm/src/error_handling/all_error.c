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
        write(2, ".name doesn't exist or the name is too long\n", 44);
        return -1;
    }
    if (if_comment_exists(tab) != -1) {
        write(2, ".comment doesn't exist or the comment is too long\n", 50);
        return -1;
    }
    return 0;
}
