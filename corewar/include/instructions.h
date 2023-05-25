/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instructions
*/
#include "struct.h"

#ifndef INSTRUCTIONS_H_
    #define INSTRUCTIONS_H_

    //intructions/
    // memory_value.c
    int read_memory_value(char *memory, int address, int size);

    //update_register.c
    void update_register(int reg_num, int value, champ_t *champion);

    //read_register.c
    int read_register(char *code, int reg_num);

    //live.c
    int live_fonction(champ_t *champion, corewar_t *corewar);
    int get_adrr(champ_t *champion);

    //ld.c
    void direct_load_fonction(corewar_t *corewar, champ_t *champion);

    //lld.c
    void direct_long_load_fonction(corewar_t *corewar, champ_t *champion);

    //ldi.c
    void indirect_load_fonction(corewar_t *corewar, champ_t *champion);
    void update_final_var(corewar_t *corewar, champ_t *champion,
    int value1, int value2);
    int param_two(corewar_t *corewar, champ_t *champion,
        int encoding2, int value2);

    // lldi.c
    void long_indirect_load_fonction(corewar_t *corewar, champ_t *champion);

#endif /* !INSTRUCTIONS_H_ */
