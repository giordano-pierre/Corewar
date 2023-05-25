/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** my_corewar
*/
#include "../include/corewar.h"

int my_corewar(corewar_t *corewar)
{
    corewar->mem = create_mem();
    if (fill_mem(corewar->mem, corewar->warriors) == -1) {
        write(2, "corewar: Champions are superposed.\n", 35);
        return -1;
    }
    corewar->warriors[0]->pc = 10;
    my_printf("%02x\n", corewar->mem[corewar->warriors[0]->pc]);
    direct_load_fonction(corewar, corewar->warriors[0]);
    print_reg(corewar->warriors[0]->reg);
    my_printf("%d\n", corewar->warriors[0]->pc);
    return 0;
}
