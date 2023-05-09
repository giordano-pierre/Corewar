/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** if_comment_exists
*/

#include "../../include/asm.h"

int if_comment_exists(char **tab)
{
    char **tab_bis = my_str_to_word_array(tab[1]);

    if (tab_bis[0] != NULL) {
        if (my_strcmp(tab_bis[1], COMMENT_CMD_STRING) == 0) {
            return -1;
        }
    }

    int len_comment = my_strlen(tab_bis[1]);

    if (len_comment > COMMENT_LENGTH) {
        return -1;
    }
    return 0;
}
