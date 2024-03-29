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
    // read_memory_value.c
    int read_memory_value(unsigned char *memory, int address, int size);
    int read_memory_value_bis(unsigned char *memory, int address, int size);

    // update_register.c
    void update_register(int reg_num, int value, champ_t *champion);

    // read_register.c
    int read_register(char *code, int reg_num);

    // write_memory_value.c
    void write_mem(unsigned char *memory, int address, int size, int value);

    // good_register.c
    int good_arg(corewar_t *corewar, champ_t *champion);
    int good_arg_bis(corewar_t *corewar, champ_t *champion);

    //add.c
    void add_function(champ_t *champion, corewar_t *corewar);

    //and.c
    void and_function(corewar_t *corewar, champ_t *champion);
    int get_param_value(corewar_t *corewar, champ_t *champion,
    int param, int *pc_size);

    // or.c
    void or_function(corewar_t *corewar, champ_t *champion);

    // xor.c
    void xor_function(corewar_t *corewar, champ_t *champion);

    //live.c
    int live_fonction(champ_t *champion, corewar_t *corewar);
    int get_adrr(champ_t *champion);

    // ld.c
    void direct_load_fonction(corewar_t *corewar, champ_t *champion);

    // lld.c
    void direct_long_load_fonction(corewar_t *corewar, champ_t *champion);

    // ldi.c
    int get_param_value_bis(corewar_t *corewar, champ_t *champion,
    int param, int *pc_size);
    void indirect_load_fonction(corewar_t *corewar, champ_t *champion);

    // lldi.c
    void long_indirect_load_fonction(corewar_t *corewar, champ_t *champion);

    // sti.c
    void indirect_store(corewar_t *corewar, champ_t *champion);

    //sub.c
    void sub_function(champ_t *champion, corewar_t *corewar);

    // st.c
    void direct_store(corewar_t *corewar, champ_t *champion);

    // zjump.c
    void zjump_function(champ_t *champion, corewar_t *corewar);

    // fork.c
    void fork_fonction(corewar_t *corewar, champ_t *champion);
    void add_warrior(corewar_t *corewar, champ_t *new_champ);
    champ_t *create_champion(void);
    void copy_champion_state(champ_t *src, champ_t *dest, int new_pc);
    int load_champ_fork(unsigned char *mem, int add, champ_t *champ);

    // lfork.c
    void lfork_fonction(corewar_t *corewar, champ_t *champion);

    //aff.c
    void aff_function(champ_t *champion, corewar_t *corewar);

#endif /* !INSTRUCTIONS_H_ */
