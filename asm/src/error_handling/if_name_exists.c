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
        write(2, "there is more than .name and the name on the line.\n", 51);
        return 1;
    }

    if (tab_bis[0] != NULL) {
        if (my_strcmp(tab_bis[0], NAME_CMD_STRING) != 0) {
            write(2, ".name doesn't exist in the file.\n", 33);
            return 1;
        }
    }


    int len_name = my_strlen(tab_bis[1]);
    if(tab_bis[1] != NULL) {
        if(tab_bis[1][0] != '"' || tab_bis[1][len_name - 1] != '"') {
            write(2, "You forgot the '\"' in the name.\n", 32);
            return 1;
        }
    }

    if ((len_name - 2) > PROG_NAME_LENGTH) {
        write(2, "The name is too long.\n", 22);
        return 1;
    }
    return 0;
}
