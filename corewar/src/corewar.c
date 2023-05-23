/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/
#include "../include/corewar.h"

char *extract_champion_name(const char *filename)
{
    FILE *file = fopen(filename, "rb");

    if (!file) exit(84);
    fseek(file, CHAMPION_NAME_OFFSET, SEEK_SET);
    char *champion_name = malloc(CHAMPION_NAME_LENGTH + 1);
    if (!champion_name) exit(84);
    size_t read_count = fread(champion_name, 1, CHAMPION_NAME_LENGTH, file);
    if (read_count != CHAMPION_NAME_LENGTH) exit(84);
    champion_name[CHAMPION_NAME_LENGTH] = '\0';
    fclose(file);
    return champion_name;
}

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
    return my_strcmp(str + str_len - ext_len, extension) == 0;
}

void corewar_main(char **file, char **av)
{
    if (have_file_point_cor(av[1])) {
        win_print(av);
    } else {
        free_array(file);
        print_h();
        exit(84);
    }
}
