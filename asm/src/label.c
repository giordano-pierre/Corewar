/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** label
*/
#include "../include/asm.h"

int get_label(asm_t *my_asm, char **line, int *ind)
{
    int i = 0;

    if (find_double_point(line[*ind]) == 0) {
        my_asm->old_label = malloc(sizeof(char) * my_strlen(line[*ind]));
        for (; line[*ind][i + 1]; i++) {
            my_asm->old_label[i] = line[*ind][i];
        }
        my_asm->old_label[i] = '\0';
        *ind = *ind + 1;
    }
    if (line[*ind] == NULL)
        return -1;
    return 0;
}

int is_label_char(char c)
{
    for (int i = 0; LABEL_CHARS[i]; i++)
        if (c == LABEL_CHARS[i])
            return 0;
    return -1;
}

int label_size(char *label)
{
    int cmpt = 0;

    for (int i = 0; label[i]; i++) {
        if (is_label_char(label[i]) == 0)
            cmpt++;
    }
    return cmpt;
}

char *extract_label(char *str)
{
    int size = label_size(str);
    char *res = malloc(sizeof(char) * (size + 1));
    int ind = 0;

    for (int i = 0; str[i]; i++) {
        if (is_label_char(str[i]) == 0) {
            res[ind] = str[i];
            ind++;
        }
    }
    res[ind] = '\0';
    return res;
}

label_t **create_label(instruct_t **info)
{
    label_t **labels = malloc(sizeof(label_t *));
    int tmp = 0;
    int line = 0;

    labels[0] = NULL;
    for (int i = 0; info[i]; i++) {
        if (info[i]->inst == 1)
            line = tmp;
        tmp = tmp + info[i]->size;
        if (info[i]->bin != 0)
            tmp++;
        if (info[i]->label && info[i]->inst == 1)
            labels = add_label(labels, info[i]->label, line);
    }
    return labels;
}
