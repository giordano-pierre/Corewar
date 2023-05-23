/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** check_num_param
*/

#include "../../include/asm.h"

int check_instruction_arg(char *str)
{
    int len = 16;
    for (int i = 0; i < len; i++) {
        op_t tab_bis = op_tab[i];
        if (my_strcmp(str, tab_bis.mnemonique) == 0) {
            return tab_bis.nbr_args; 
        }
    }
    return 0;
}

int check_num_param(int num_arg, char *str)
{
    check_instruction_arg(str);
    if (check_instruction_arg(str) == num_arg) {
        return 1;
    }
    return 0;
}

int recover_param_number(char **tab)
{
    int ind = 0;
    int len;
    for (int i = 2; tab[i] != NULL; i++) {
        ind = 0;
        char **chaine = my_str_to_word_array(tab[i]);
        if (check_double_point(chaine[0]) == 1)
            ind++;
        if (chaine[ind] == NULL)
            continue;
        if (check_instruction(chaine[ind]) != 1)
            return 1;
        len = my_arraylen(&chaine[ind]) - 1;
        if (check_num_param(len, chaine[ind]) != 1)
            return 1;
    }
    return 0;
}
