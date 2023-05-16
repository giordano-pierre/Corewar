/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** check_instruction
*/

#include "../../include/asm.h"

int check_double_point(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':') {
            return 1;
        }
    }
    return 0;
}

int check_instruction(char *str)
{
    int len = 16;
    for (int i = 0; i < len; i++) {
        op_t tab_bis = op_tab[i];
        if (my_strcmp(str, tab_bis.mnemonique) == 0) {
            return 1;
        }
    }
    return 0;
}

int recover_instruction(char **tab)
{
    int ind = 0;
    for (int i = 2; tab[i] != NULL; i++) {
        ind = 0;
        char **chaine = my_str_to_word_array(tab[i]);
        if (check_double_point(chaine[0]) == 1)
            ind++;
        if (chaine[ind] == NULL)
            continue;
        if (check_instruction(chaine[ind]) != 1)
            return 1;
    }
    return 0;
}
