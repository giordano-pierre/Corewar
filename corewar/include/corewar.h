/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** corewar
*/
#include <sys/types.h>
#include <stdio.h>
#include <stdint.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../lib/printf/include/my_printf.h"
#include "../../op.h"
#include "struct.h"

#ifndef SOLVER_H_
    #define SOLVER_H_

    #define CHAMPION_NAME_OFFSET 4
    #define CHAMPION_NAME_LENGTH 128

    // main.c
    void print_h(void);

    // recover_file.c;
    void free_array(char **array);
    void print_array(char **array);

    // array.c;
    int error_file(char const *file_name, struct stat *info);
    char *read_file(const char *file_name, struct stat *info);
    // corewar.c
    void corewar_main(char **file, char **av);

    // mem.c
    char *create_mem(void);
    void print_good(int i, int *line);
    void print_mem(char *mem);

    // flags handling
    int recup_flags(char **av, corewar_t *corewar, champ_t **warriors);

    // add_tab.c
    champ_t **add_tab(champ_t **warriors, int adress, char *file, int nb_p);

    // free.c
    void free_champ(champ_t **warriors);

#endif /* !SOLVER_H_ */
