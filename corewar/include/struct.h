/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** struct
*/

#include "../../op.h"

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct champion {
        char *file;
        char *name;
        char *comment;
        char *code;
        int size;
        int nb_prog;
        int adress;
        int pc;
        int carry;
        int reg[REG_NUMBER];
    } champ_t;

    typedef struct corewar {
        unsigned char *mem;
        int nbr_live;
        int cycle_to_die;
        char *last_live;
        int dump;
        champ_t **warriors;
    } corewar_t;

#endif /* !STRUCT_H_ */
