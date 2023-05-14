/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** param
*/
#include "../include/asm.h"

void add_param(asm_t *my_asm, char *arg, int param)
{
    if (arg[0] == 'r')
        add_register(my_asm, arg, param, 1);
    else if (arg[0] == '%' && my_asm->index == 0)
        add_direct(my_asm, arg, param, DIR_SIZE);
    else
        add_indirect(my_asm, arg, param, IND_SIZE);
}

void add_register(asm_t *my_asm, char *arg, int param, int size)
{
    add_instr(my_asm, my_getnbr_ind(arg, 1), 0, size);
    if (my_asm->no_bin == 0) {
        my_asm->info[my_asm->ind]->bin = my_asm->info[my_asm->ind]->bin + \
        my_compute_power_rec(2, (6 - (param * 2)));
    }
}

void add_direct(asm_t *my_asm, char *arg, int param, int size)
{
    if (arg[1] == ':') {
        my_asm->old_label = extract_label(arg);
        add_instr(my_asm, 0, 0, size);
    } else
        add_instr(my_asm, my_getnbr_ind(arg, 1), 0, size);
    if (my_asm->no_bin == 0) {
        my_asm->info[my_asm->ind]->bin = my_asm->info[my_asm->ind]->bin + \
        my_compute_power_rec(2, (7 - (param * 2)));
    }
}

void add_indirect(asm_t *my_asm, char *arg, int param, int size)
{
    if (arg[0] == '%') {
        add_direct(my_asm, arg, param, size);
        return;
    }
    if (arg[0] == ':') {
        my_asm->old_label = extract_label(arg);
        add_instr(my_asm, 0, 0, size);
    } else
        add_instr(my_asm, my_getnbr_ind(arg, 0), 0, size);
    if (my_asm->no_bin == 0) {
        my_asm->info[my_asm->ind]->bin = my_asm->info[my_asm->ind]->bin + \
        my_compute_power_rec(2, (7 - (param * 2)));
        my_asm->info[my_asm->ind]->bin = my_asm->info[my_asm->ind]->bin + \
        my_compute_power_rec(2, (6 - (param * 2)));
    }
}
