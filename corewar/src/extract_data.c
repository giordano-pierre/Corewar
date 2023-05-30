/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** extract_data
*/
#include "../include/corewar.h"

char *extract_name(unsigned char *file)
{
    char *name = malloc(sizeof(char) * (PROG_NAME_LENGTH + 1));

    for (int i = 4; i < PROG_NAME_LENGTH; i++) {
        name[i - 4] = file[i];
    }
    name[PROG_NAME_LENGTH] = '\0';
    return name;
}

char *extract_comment(unsigned char *file)
{
    char *comment = malloc(sizeof(char) * (COMMENT_LENGTH + 1));

    for (int i = 12 + PROG_NAME_LENGTH; i < COMMENT_LENGTH; i++) {
        comment[i - (12 + PROG_NAME_LENGTH)] = file[i];
    }
    comment[COMMENT_LENGTH] = '\0';
    return comment;
}

char *extract_code(unsigned char *file, int size)
{
    int tmp = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
    char *code = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++) {
        code[i] = file[i + tmp];
    }
    code[size] = '\0';
    return code;
}

int fill_champ(champ_t **warriors)
{
    unsigned char *file;
    int i = 0;

    for (; warriors[i]; i++) {
        file = read_file(warriors[i]->file);
        if (file == NULL)
            return -1;
        warriors[i]->name = extract_name(file);
        warriors[i]->comment = extract_comment(file);
        warriors[i]->size = read_memory_value_bis(file, PROG_NAME_LENGTH + 8, 4);
        warriors[i]->code = extract_code(file, warriors[i]->size);
        warriors[i]->pc = warriors[i]->adress;
        free(file);
    }
    if (i == 0) {
        write(2, "corewar: There is no champion.\n", 31);
        return -1;
    }
    return 0;
}
