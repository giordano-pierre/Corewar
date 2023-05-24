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

int bad_enter(char **file)
{
    if (file == NULL)
        return 1;
    if (file[0] == NULL) {
        write(2, "corewar: it's not a file !\n", 27);
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    struct stat info;
    warriors_t *warriors = malloc(sizeof(warriors_t));
    champ_t *champ = malloc(sizeof(champ_t) * 10);
    if (ac == 2)
        if (my_strcmp(av[1], "-h") == 0) {
            print_h();
            return 0;
        }
    if (ac < 3) {
        write(2, "corewar: Bad number of champions.\n", 34);
        return 84;
    }
    char *file = read_file(av[1], &info);
    if (file == NULL)
        return 84;
    char *mem = create_mem();
    free(mem);
    free(file);
    free(champ); free(warriors);
    return 0;
}
