/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** main
*/
#include "../include/asm.h"

void print_h(void)
{
    my_printf("USAGE\n./asm file_name[.s]\nDESCRIPTION\nfile_name file in ");
    my_printf("assembly language to be converted into file_name.cor, an\n");
    my_printf("executable in the Virtual Machine.\n");
}

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

char **read_file_file(const char *file_name)
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

int bad_enter(char **file)
{
    if (file == NULL)
        return 1;
    if (file[0] == NULL) {
        write(2, "asm: it's not a file !\n", 23);
        return 1;
    }
    return 0;
}

int main(int ac,char **av)
{
    if (ac != 2) {
        write(2, "asm: Bad number of arguments.\n", 30);
        return 84;
    }
    if (my_strcmp(av[1], "-h") == 0) {
        print_h();
        return 0;
    }
    char **file = read_file_file(av[1]);
    if (bad_enter(file))
        return 84;
    if (file != NULL) {
        for (size_t i = 0; file[i] != NULL; i++) {
            my_printf("%s", file[i]);
            free(file[i]);
        }
        free(file);
    }
    return 0;
}
