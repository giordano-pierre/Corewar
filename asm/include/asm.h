/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** asm
*/
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../op.h"
#include "../../lib/printf/include/my_printf.h"

#ifndef ASM_H_
    #define ASM_H_

    // main.c
    void print_h(void);

    // recover_file.c
    int skip_line(char *line);
    int verif_file(char *filename, FILE *fd);
    int file_empty(char **file);
    char **recup_file(char *filename);
    int have_file_point_s(const char *str);

    // array.c
    char **add_line(char **array, char *line);
    void print_array(char **array);
    void free_array(char **array);
    int my_arraylen(char **array);

    //my_str_to_word_array.c
    char **my_str_to_word_array(char const *str);
    int count_word (char const *str);
    int count_char(char const *str, int i);
    void skip_quote(char const *str, int *ind);
    int have_second_quote(char const *str, int ind);

    void my_asm(char **file, char *filepath);
    char *name_file_point_core(char *file_name);
    void write_instruction(char **file, FILE *fd);
    int inverse_magic(int i);

#endif /* !ASM_H_ */
