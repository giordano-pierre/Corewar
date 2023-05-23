/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** mem
*/
#include "../include/corewar.h"

char *create_mem(void)
{
    char *mem = malloc(sizeof(char) * MEM_SIZE);

    for (int i = 0; i < MEM_SIZE; i++)
        mem[i] = 0;
    return mem;
}

void print_good(int i, int *line)
{
    if (i == 0) {
        write(1, "0    : ", 7);
        *line = *line + 1;
    }
    if (i != 0) {
        if ((i % 32) == 0) {
            write(1, "\n", 1);
            my_printf("%-5X: ", *line * 32);
            *line = *line + 1;
        } else
            write(1, " ", 1);
    }
}

void print_mem(char *mem)
{
    int line = 0;

    for (int i = 0; i < MEM_SIZE; i++) {
        print_good(i, &line);
        my_printf("%02x", (int)mem[i]);
    }
    write(1, "\n", 1);
}
