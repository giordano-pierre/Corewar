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

int bad_enter(char **file)
{
    if (file == NULL)
        return 1;
    if (file[0] == NULL) {
        write(2, "asm: it's not a file !\n", 23);
        return 1;
    }
    return 0;
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
    char **file = read_file(av[1]);
    if (bad_enter(file))
        return 84;
    asm_main(file, av[1]);
    if (file != NULL) {
        for (size_t i = 0; file[i] != NULL; i++) {
            my_printf("%s", file[i]);
            free(file[i]);
        }
        free(file);
    }
    return 0;
}
