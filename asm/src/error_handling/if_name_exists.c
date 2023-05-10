/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** if_name_exists
*/

#include "../../include/asm.h"

int if_name_exists(char **tab)
{
    char **tab_bis = my_str_to_word_array(tab[0]);
    int len_tab = my_arraylen(tab_bis);
    if (len_tab != 2) {
        return 1;
    }

    if (tab_bis[0] != NULL) {
        if (my_strcmp(tab_bis[0], NAME_CMD_STRING) != 0) {
            return 1;
        }
    }

    int len_name = my_strlen(tab_bis[1]);

    if ((len_name - 2) > PROG_NAME_LENGTH) {
        return 1;
    }
    return 0;
}
