/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** recover_file
*/
#include "../include/asm.h"

size_t count_lines(FILE *file)
{
    size_t lines_count = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        lines_count++;
    }
    fseek(file, 0, SEEK_SET);
    free(line);
    return lines_count;
}

char **read_file(const char *file_name)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        write(2, "asm: Bad file\n", 14);
        return NULL;
    }
    size_t lines_count = count_lines(file);
    char **final_file = malloc((lines_count + 1) * sizeof(char *));
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    size_t i = 0;
    while ((read = getline(&line, &len, file)) != -1) {
        final_file[i] = malloc((read + 1) * sizeof(char));
        my_strcpy(final_file[i], line);
        i++;
    }
    fclose(file);
    free(line);
    final_file[i] = NULL;
    return final_file;
}
