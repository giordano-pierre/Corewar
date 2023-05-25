/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** recover_file
*/
#include "../include/corewar.h"

int error_file(char *file_name, struct stat *info)
{
    int fd;

    if (stat(file_name, info) == -1) {
        write(2, "corewar: No such file.\n", 23);
        return -1;
    }
    if (have_file_point_cor(file_name) != 0) {
        print_h();
        return -1;
    }
    if ((fd = open(file_name, O_RDONLY)) == -1) {
        write(2, "corewar: Cannot open the file.\n", 31);
        return -1;
    }
    return fd;
}

char *read_file(char *file_name)
{
    struct stat info;
    int fd = error_file(file_name, &info);
    char *buffer;

    if (fd == -1)
        return NULL;
    buffer = malloc(sizeof(char) * (info.st_size + 1));
    if (read(fd, buffer, info.st_size) == -1) {
        free(buffer);
        buffer = NULL;
        write(2, "corewar: Bad file.\n", 19);
    } else
        buffer[info.st_size] = '\0';
    close(fd);
    return buffer;
}
