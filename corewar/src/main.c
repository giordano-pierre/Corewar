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

int verif_arg(int ac, char **av)
{
    if (ac == 2)
        if (my_strcmp(av[1], "-h") == 0) {
            print_h();
            return 0;
        }
    if (ac < 3) {
        write(2, "corewar: Bad number of champions.\n", 34);
        return 84;
    }
    return -1;
}

int main(int ac, char **av)
{
    corewar_t *base = NULL;
    int err;

    if ((err = verif_arg(ac, av)) != -1)
        return err;
    base = create_base();
    base->warriors = create_champ(base->warriors);
    fill_champ(base->warriors);
    print_champ(base->warriors);
    free_champ(base->warriors);
    free(base);
    return 0;
}
    // function Patoche a la place de create_champ()
