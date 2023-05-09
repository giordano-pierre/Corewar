/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** if_name_exists
*/

#include "../../include/asm.h"

int if_name_exists(char **tab)
{
    int i = 0;
    int str;
    char *name = NULL;
    while (tab[i] != NULL) {
        str = my_strncmp(tab[i], ".name", 5);
        if (str == 0) {
            return -1;
        }
        i++;
    }
    // if (name != NULL) {
    //     printf("%s", name);
    //     //     // int i = 0;
    //     //     // while (name[i] != '\n' && name[i] != '\0') {
    //     //     //     i++;
    //     //     // }
    //     //     // name[i] = '\0';
    // } else {
    //     printf("not exist\n");
    // }
    return 0;
}
