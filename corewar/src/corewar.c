/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/
#include "../include/corewar.h"

void win_print(char **av)
{
    char *champion_name = extract_champion_name(av[1]);
    my_printf("The player 1(%s) has won.\n", champion_name);
}

int have_file_point_cor(char *str)
{
    const char *extension = ".cor";
    size_t ext_len = my_strlen(extension);
    size_t str_len = my_strlen(str);

    if (str_len < ext_len) {
        return 0;
    }
    return my_strcmp(str + str_len - ext_len, extension);
}
