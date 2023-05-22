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
#include "struct.h"
#include "../../lib/printf/include/my_printf.h"
#include "../../op.h"

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

    // error handling
    int all_error(char **tab);
    int if_name_exists(char **tab);
    int if_comment_exists(char **tab);
    int recover_instruction(char **tab);
    int check_instruction(char *str);
    int check_double_point(char *str);
    int recover_param_number(char **tab);
    int check_num_param(int num_arg, char *str);
    int check_instruction_arg(char *str);

    // array.c
    char **add_line(char **array, char *line);
    int my_arraylen(char **array);
    int my_structlen(instruct_t **array);
    int add_instr(asm_t *my_asm, int code, int inst, int size);
    label_t **add_label(label_t **labels, char *name, int nb);

    // my_str_to_word_array.c
    char **my_str_to_word_array(char const *str);
    int count_word (char const *str);
    int count_char(char const *str, int i);
    void skip_quote(char const *str, int *ind);
    int have_second_quote(char const *str, int ind);

    // free.c
    void free_array(char **array);
    void free_asm(asm_t *my_asm);
    void free_inst(instruct_t **inst);
    void free_label(label_t **labels);

    // my_asm.c
    int get_ind_slash(char *file_name, int len);
    char *name_file_point_core(char *file_name);
    int inverse_magic(int i);
    header_t make_header(char **file);
    void make_asm(char **file, char *filepath);

    // instruction.c
    int get_instruction(char *arg);
    int get_label(asm_t *my_asm, char **line, int *ind);
    void fill_instruct(asm_t *my_asm, char **line);
    instruct_t **get_info(char **file);

    // tools.c
    int find_double_point(char *str);
    int	my_getnbr_ind(char const *str, int indice);
    int my_strlen_hashtag(char const *str);

    // index.c
    char **create_no_bin(void);
    int is_no_bin(char *arg, char **no_bin);
    char **create_index(void);
    int is_index(char *arg, char **index);

    // param.c
    void add_register(asm_t *my_asm, char *arg, int param, int size);
    void add_direct(asm_t *my_asm, char *arg, int param, int size);
    void add_indirect(asm_t *my_asm, char *arg, int param, int size);
    void add_param(asm_t *my_asm, char *arg, int param);

    // print.c
    void print_all_code(instruct_t **info, FILE *fd);
    void print_one_code(int nb, int size, FILE *fd);
    void print_array(char **array);
    void print_label(label_t **labels);
    void print_struct(instruct_t **info);

    // label.c
    int get_label(asm_t *my_asm, char **line, int *ind);
    int is_label_char(char c);
    int label_size(char *label);
    char *extract_label(char *str);
    label_t **create_label(instruct_t **info);

    // label_bis.c
    void fill_label(instruct_t **info, label_t **labels);
    void get_label_code(instruct_t *param, label_t **labels, int line);
    int get_label_line(label_t **labels, char *search);

#endif /* !GENERATOR_H_ */
