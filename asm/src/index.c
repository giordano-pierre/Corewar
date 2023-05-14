/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** index
*/
#include "../include/asm.h"

char **create_no_bin(void)
{
    char **no_bin = malloc(sizeof(char *) * 5);

    no_bin[0] = my_strdup("live");
    no_bin[1] = my_strdup("zjmp");
    no_bin[2] = my_strdup("fork");
    no_bin[3] = my_strdup("lfork");
    no_bin[4] = NULL;
    return no_bin;
}

int is_no_bin(char *arg, char **no_bin)
{
    for (int i = 0; no_bin[i]; i++) {
        if (my_strcmp(no_bin[i], arg) == 0)
            return 0;
    }
    return -1;
}

char **create_index(void)
{
    char **index = malloc(sizeof(char *) * 7);

    index[0] = my_strdup("zjmp");
    index[1] = my_strdup("ldi");
    index[2] = my_strdup("sti");
    index[3] = my_strdup("fork");
    index[4] = my_strdup("lldi");
    index[5] = my_strdup("lfork");
    index[6] = NULL;
    return index;
}

int is_index(char *arg, char **index)
{
    for (int i = 0; index[i]; i++) {
        if (my_strcmp(index[i], arg) == 0)
            return 0;
    }
    return -1;
}
