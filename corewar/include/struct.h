/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** struct
*/

#include "../../op.h"

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct corewar {
        char *mem;
        int nbr_live;
        int cycle_to_die;
        int dump;
    } corewar_t;

    typedef struct champion {
        char *file;
        char *name;
        char *comment;
        char *code;
        int nb_prog;
        int adress;
        int pc;
    } champ_t;

    typedef struct warriors {
        champ_t *champ;
    } warriors_t;

#endif /* !STRUCT_H_ */
