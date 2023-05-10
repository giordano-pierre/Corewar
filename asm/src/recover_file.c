/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** recover_file
*/
#include "../include/asm.h"

int have_file_point_s(const char *str)
{
    int ind = 0;

    while (str[ind + 1] != '\0') {
        if (str[ind] == '.' && str[ind + 1] == 's') {
            return 0;
        }
        ind++;
    }
    return -1;
}

int skip_line(char *line)
{
    for (int i = 0; line[i] != COMMENT_CHAR && line[i] != '\n'
    && line[i]; i++) {
        if (line[i] != '\t' && line[i] != ' ')
            return 0;
    }
    return -1;
}

int verif_file(char *filename, FILE *fd)
{
    if (fd == NULL) {
        write(2, "asm: No such file.\n", 19);
        return -1;
    }
    if (have_file_point_s(filename) == -1) {
        print_h();
        return -1;
    }
    return 0;
}

int file_empty(char **file)
{
    if (file[0] == NULL) {
        free(file);
        write(2, "asm: File is empty.\n", 20);
        return -1;
    }
    return 0;
}

char **recup_file(char *filename)
{
    char **file;
    char *line = NULL;
    size_t len = 0;
    FILE *fd = fopen(filename, "r");

    if (verif_file(filename, fd))
        return NULL;
    file = malloc(sizeof(char *) * 1);
    file[0] = NULL;
    while ((getline(&line, &len, fd) != -1)) {
        if (skip_line(line) == -1)
            continue;
        file = add_line(file, line);
    }
    free(line);
    fclose(fd);
    if (file_empty(file) == -1)
        return NULL;
    return file;
}
