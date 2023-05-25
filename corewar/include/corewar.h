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
    int fill_champ(champ_t **warriors);

    // array.c;
    int error_file(char const *file_name, struct stat *info);
    char *read_file(const char *file_name);

    // corewar.c
    void corewar_main(char **file, char **av);

    // mem.c
    char *create_mem(void);
    void print_good(int i, int *line);
    void print_mem(char *mem);

    // add_tab.c
    champ_t **add_tab(champ_t **warriors, int adss, char *file, int nb_p);

    // free.c
    void free_champ(champ_t **warriors);

    //intructions/memory_value.c
    int read_memory_value(char *memory, int address, int size);

    //intructions/ld.c
    void direct_load_fonction(corewar_t *corewar, champ_t *champion);

#endif /* !SOLVER_H_ */
