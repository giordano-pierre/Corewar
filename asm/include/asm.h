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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../../lib/printf/include/my_printf.h"

#ifndef ASM_H_
    #define ASM_H_

    // main.c
    void print_h(void);

    // recover_file.c;
    void free_array(char **array);
    void print_array(char **array);

    // array.c;
    size_t count_lines(FILE *file);
    char **read_file(const char *file_name);

    // asm.c
    void asm_main(char **file, char *file_name);

    //toolbox.c
    ssize_t my_strlen_long(char const *str);
    int have_file_point_s(const char *str);

    // array.c
    char **my_str_to_word_array(char const *str);

#endif /* !ASM_H_ */
