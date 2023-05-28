/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** write_mem
*/
#include "../../include/corewar.h"

void write_mem(unsigned char *memory, int address, int size, int value)
{
    for (int i = size - 1; i >= 0; i--) {
        memory[(address + i) % MEM_SIZE] = (value >> (8 * i)) & 0xFF;
    }
}
