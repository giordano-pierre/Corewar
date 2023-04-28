/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** asm
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../../lib/printf/include/my_printf.h"

#ifndef GENERATOR_H_
    #define GENERATOR_H_

    typedef struct asmstruct {
    } asm_t;

    void free_array(char **array);
    void print_array(char **array);

#endif /* !GENERATOR_H_ */
