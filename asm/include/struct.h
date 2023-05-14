/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct instruct {
        int inst;
        int code;
        int size;
        char *label;
        int bin;
    } instruct_t;

    typedef struct my_asm {
        instruct_t **info;
        char *old_label;
        char **tab_index;
        char **tab_no_bin;
        int index;
        int no_bin;
        int ind;
    } asm_t;

    typedef struct label {
        char *name;
        int nb;
    } label_t;

#endif /* !STRUCT_H_ */
