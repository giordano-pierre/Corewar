/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** corewar
*/
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../lib/printf/include/my_printf.h"

#ifndef SOLVER_H_
    #define SOLVER_H_

    typedef struct corewar {
    } corewar_t;

    // recover_file.c;
    void free_array(char **array);
    void print_array(char **array);

    // array.c;
    size_t count_lines(FILE *file);
    char **read_file(const char *file_name);

#endif /* !SOLVER_H_ */
