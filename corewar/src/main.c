/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** main
*/
#include "../include/corewar.h"

void print_h(void)
{
    my_printf("USAGE\n./corewar [-dump nbr_cycle] ");
    my_printf("[[-n prog_number] [-a load_address] prog_name] ...\n");
    my_printf("DESCRIPTION\n-dump nbr_cycle dumps the memory ");
    my_printf("after the nbr_cycle execution (if the round isn’t\n");
    my_printf("already over) with the following format: 32 bytes/line\n");
    my_printf("in hexadecimal (A0BCDEFE1DD3...)\n");
    my_printf("-n prog_number sets the next program’s number.");
    my_printf(" By default, the first free number\nin the parameter order\n");
    my_printf("-a load_address sets the next program’s loading address.");
    my_printf(" When no address is\nspecified, optimize the addresses");
    my_printf(" so that the processes are as far\naway from each other");
    my_printf(" as possible. The addresses are MEM_SIZE modulo.\n");
}

size_t count_lines(FILE *file)
{
    size_t lines_count = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        lines_count++;
    }
    fseek(file, 0, SEEK_SET);
    free(line);
    return lines_count;
}

char **read_file_file(const char *file_name)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        write(2, "asm: Bad file", 13);
        return NULL;
    }
    size_t lines_count = count_lines(file);
    char **final_file = malloc((lines_count + 1) * sizeof(char *));
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    size_t i = 0;
    while ((read = getline(&line, &len, file)) != -1) {
        final_file[i] = malloc((read + 1) * sizeof(char));
        my_strcpy(final_file[i], line);
        i++;
    }
    fclose(file);
    free(line);
    final_file[i] = NULL;
    return final_file;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        write(2, "corewar: Bad number of arguments.\n", 34);
        return 84;
    }
    if (my_strcmp(av[1], "-h") == 0) {
        print_h();
        return 0;
    }
    char **file = read_file_file(av[1]);
    if (file == NULL) return 84;
    if (file != NULL) {
        for (size_t i = 0; file[i] != NULL; i++) {
            my_printf("%s", file[i]);
            free(file[i]);
        }
        free(file);
    }
    return 0;
}
