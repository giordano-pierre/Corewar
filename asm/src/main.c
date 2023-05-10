/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** main
*/
#include "../include/asm.h"

void print_h(void)
{
    my_printf("USAGE\n./asm file_name[.s]\nDESCRIPTION\nfile_name file in ");
    my_printf("assembly language to be converted into file_name.cor, an\n");
    my_printf("executable in the Virtual Machine.\n");
}

int main(int ac,char **av)
{
    if (ac != 2) {
        write(2, "asm: Bad number of arguments.\n", 30);
        return 84;
    }
    if (my_strcmp(av[1], "-h") == 0) {
        print_h();
        return 0;
    }
    char **file = recup_file(av[1]);
    if (file == NULL)
        return 84;
    my_asm(file, av[1]);
    free_array(file);
    return 0;
}
