/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** if_comment_exists
*/

#include "../../include/asm.h"

int if_comment_exists_bis(char **tab_bis)
{
    int len_comment = my_strlen(tab_bis[1]);

    if (tab_bis[1] != NULL) {
        if (tab_bis[1][0] != '"' || tab_bis[1][len_comment - 1] != '"') {
            write(2, "You forgot the '\"' in the comment.\n", 35);
            return 1;
        }
    }

    if ((len_comment - 2) > COMMENT_LENGTH) {
        write(2, "The comment is too long.\n", 25);
        return 1;
    }
    return 0;
}

int if_comment_exists(char **tab)
{
    char **tab_bis = my_str_to_word_array(tab[1]);

    int len_tab = my_arraylen(tab_bis);
    if (len_tab != 2) {
        write(2, "There is more than .comment ", 28);
        write(2, "and the comment on the line.\n", 29);
        return 1;
    }

    if (tab_bis[0] != NULL) {
        if (my_strcmp(tab_bis[0], COMMENT_CMD_STRING) != 0) {
            write(2, ".comment doesn't exist in the file.\n", 36);
            return 1;
        }
    }
    if (if_comment_exists_bis(tab_bis) != 0)
        return 1;

    free_array(tab_bis);
    return 0;
}
