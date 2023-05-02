/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** asm
*/
#include "../include/asm.h"

void create_file(char *name, char **text)
{
    int fd = open(name, O_CREAT | O_WRONLY, 0644);

    if (fd == -1) {
        write(2, "asm: fail !\n", 12);
        exit(84);
    }
    size_t len = 0;
    for (int i = 0; text[i] != NULL; i++) {
        len += my_strlen(text[i]);
    }
    for (int i = 0; text[i] != NULL; i++) {
        ssize_t written = write(fd, text[i], my_strlen(text[i]));
        if (written == -1 || written != my_strlen_long(text[i])) {
            write(2, "asm: fail !\n", 12);
            exit(84);
        }
    }
    close(fd);
}

char *name_file_point_core(char *file_name)
{
    size_t len = my_strlen(file_name);
    char *new_name = malloc(len + 2);

    my_strncpy(new_name, file_name, len);
    if (len >= 2 && my_strcmp(new_name + len - 2, ".s") == 0) {
        my_strcpy(new_name + len - 2, ".cor");
    } else {
        free(new_name);
        return NULL;
    }
    return new_name;
}

void asm_main(char **file, char *file_name)
{
    if (have_file_point_s(file_name)) {
        char *new_name = name_file_point_core(file_name);
        create_file(new_name, file);
        free(new_name);
    } else {
        free_array(file);
        print_h();
        exit(84);
    }
}
