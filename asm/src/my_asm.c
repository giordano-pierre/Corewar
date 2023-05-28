/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** my_asm
*/
#include "../include/asm.h"

int get_ind_slash(char *file_name, int len)
{
    int i = len;

    for (; i >= 0; i--) {
        if (file_name[i] == '/')
            break;
    }
    return i;
}

char *name_file_point_core(char *file_name)
{
    int len = my_strlen(file_name);
    int len_slash = get_ind_slash(file_name, len);
    int ind = 0;
    char *new_name = malloc(sizeof(char) * (len - (len_slash + 1) + 3));

    for (int i = len_slash + 1; i < len; i++, ind++)
        new_name[ind] = file_name[i];
    new_name[ind - 1] = 'c';
    new_name[ind] = 'o';
    new_name[ind + 1] = 'r';
    new_name[ind + 2] = '\0';
    return new_name;
}

int inverse_magic(int i)
{
    int new = ((i & 0xff) << 24 | (i & 0xff00) << 8 |
    (i & 0xff0000) >> 8 | ((i >> 24) & 0xff));

    return new;
}

header_t make_header(char **file)
{
    header_t header = {0};
    char **name = my_str_to_word_array(file[0]);
    char **my_comment = my_str_to_word_array(file[1]);
    int ind = 0;

    header.magic = inverse_magic(COREWAR_EXEC_MAGIC);
    for (int i = 1; name[1][i + 1] != '\0'; i++, ind++)
        header.prog_name[ind] = name[1][i];
    header.prog_name[ind] = '\0';
    header.prog_name[PROG_NAME_LENGTH - 1] = '\0';
    ind = 0;
    for (int j = 1; my_comment[1][j + 1] != '\0'; j++, ind++)
        header.comment[ind] = my_comment[1][j];
    header.comment[ind] = '\0';
    header.prog_name[COMMENT_LENGTH - 1] = '\0';
    header.prog_size = 0;
    free_array(name);
    free_array(my_comment);
    return header;
}

void make_asm(char **file, char *filepath)
{
    header_t header = make_header(file);
    char *new_name = name_file_point_core(filepath);
    FILE *fd = fopen(new_name, "w");
    instruct_t **info = get_info(file);
    int size = my_structlen(info);
    label_t **labels = create_label(info, file, size);

    header.prog_size = inverse_magic(size);
    fwrite(&header, sizeof(struct header_s), 1, fd);
    fill_label(info, labels);
    print_all_code(info, fd);
    fclose(fd);
    free_inst(info);
    free_label(labels);
    free(new_name);
}
