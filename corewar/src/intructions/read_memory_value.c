/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** read_memory_value
*/
#include "../../include/corewar.h"
#include "../../include/struct.h"

int read_memory_value(char *memory, int address, int size)
{
    int value = 0;

    for (int i = 0; i < size; i++) {
        value <<= 8;
        value |= (unsigned char)memory[address + i];
    }
    return value;
}
