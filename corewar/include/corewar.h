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
#include "instructions.h"

#ifndef SOLVER_H_
    #define SOLVER_H_

    #define CHAMPION_NAME_OFFSET 4
    #define CHAMPION_NAME_LENGTH 128

    // main.c;
    void print_h(void);

    // recover_file.c;
    void print_array(char **array);
    int fill_champ(champ_t **warriors);
    int have_file_point_cor(char *str);

    // array.c;
    int error_file(char *file_name, struct stat *info);
    unsigned char *read_file(char *file_name);

    // mem.c
    unsigned char *create_mem(void);
    void print_good(int i, int *line);
    void print_mem(unsigned char *mem);
    int fill_mem(unsigned char *mem, champ_t **warriors);
    int load_champ(unsigned char *mem, champ_t *champ);

    // flags handling
    int recup_flags(char **av, corewar_t *corewar);
    int if_load_adress_exists(char **av, int *i);
    int load_adress_flag(char **av, int i, int load_adress);
    int prog_number_flag(char **av, int i, int prog_nb);
    int if_prog_number_exists(char **av, int *i);
    int dump_flag(char **av, corewar_t *corewar, int *i);
    int check_file(char **av);
    int check_file_bis(const char *filename);
    int if_prog_number_exists_error(char **av, int i, int prog_nb);
    int if_load_adress_exists_error(char **av, int i, int adress);
    int is_number(char *str);
    int dump_flag_error(char **av, int i);
    int error_file_max(int nb_file);
    int flags_error(char **av, int i, int prog_nb, int adress);

    // add_tab.c
    champ_t **add_tab(champ_t **warriors, int adress, char *file, int nb_p);

    // free.c
    void free_champ(champ_t **warriors);
    void free_array(char **array);
    void free_corewar(corewar_t *corewar);

    // extract_data.c
    char *extract_name(unsigned char *file);
    char *extract_comment(unsigned char *file);
    char *extract_code(unsigned char *file, int size);
    int fill_champ(champ_t **warriors);

    // struct.c
    corewar_t *create_base(void);
    void print_reg(int reg[REG_NUMBER]);
    void print_champ(champ_t **warriors);

    // my_corewar.c
    int my_corewar(corewar_t *corewar);

    // exec_funct.c
    int exec_funct_three(corewar_t *corewar, champ_t *champion);
    int exec_funct_two(corewar_t *corewar, champ_t *champion);
    void exec_funct(corewar_t *corewar, champ_t *champion);

    //exec_funct_bis.c
    int exec_funct_six(corewar_t *corewar, champ_t *champion);
    int exec_funct_five(corewar_t *corewar, champ_t *champion);
    int exec_funct_four(corewar_t *corewar, champ_t *champion);

#endif /* !SOLVER_H_ */
