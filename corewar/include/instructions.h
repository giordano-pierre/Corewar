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
    //ld.c
    void direct_load_fonction(corewar_t *corewar, champ_t *champion);
    //lld.c
    void direct_long_load_fonction(corewar_t *corewar, champ_t *champion);
    //ldi.c
    void indirect_load_fonction(corewar_t *corewar, champ_t *champion);
    //live.c
    int live_fonction(champ_t *champion, corewar_t *corewar);

#endif /* !INSTRUCTIONS_H_ */
