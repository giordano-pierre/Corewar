/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** instruction
*/
#include "../include/asm.h"

int get_instruction(char *arg)
{
    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (my_strcmp(op_tab[i].mnemonique, arg) == 0)
            return op_tab[i].code;
    }
    return 0;
}

void fill_instruct(asm_t *my_asm, char **line)
{
    int ind = 0;
    int code;

    if (get_label(my_asm, line, &ind) == -1)
        return;
    code = get_instruction(line[ind]);
    my_asm->ind = add_instr(my_asm, code, 1, 1);
    if (is_index(line[ind], my_asm->tab_index) == 0)
        my_asm->index = 1;
    if (is_no_bin(line[ind], my_asm->tab_no_bin) == 0)
        my_asm->no_bin = 1;
    ind++;
    for (int param = 0; line[ind]; ind++, param++) {
        add_param(my_asm, line[ind], param);
    }
}

instruct_t **get_info(char **file)
{
    instruct_t **tmp;
    char **line;
    asm_t *my_asm = malloc(sizeof(asm_t));

    my_asm->info = malloc(sizeof(instruct_t *));
    my_asm->info[0] = NULL;
    my_asm->old_label = NULL;
    my_asm->tab_index = create_index();
    my_asm->tab_no_bin = create_no_bin();
    for (int i = 2; file[i] != NULL; i++) {
        my_asm->index = 0;
        my_asm->no_bin = 0;
        line = my_str_to_word_array(file[i]);
        fill_instruct(my_asm, line);
        free_array(line);
    }
    tmp = my_asm->info;
    free_asm(my_asm);
    return tmp;
}
