/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** label_bis
*/
#include "../include/asm.h"

int get_label_line(label_t **labels, char *search)
{
    for (int i = 0; labels[i]; i++) {
        if (my_strcmp(labels[i]->name, search) == 0)
            return labels[i]->nb;
    }
    return -1;
}

void get_label_code(instruct_t *param, label_t **labels, int line)
{
    int line_l = get_label_line(labels, param->label);

    param->code = line_l - line;
}

void fill_label(instruct_t **info, label_t **labels)
{
    int tmp = 0;
    int line = 0;

    for (int i = 0; info[i]; i++) {
        if (info[i]->inst == 1)
            line = tmp;
        tmp = tmp + info[i]->size;
        if (info[i]->bin != 0)
            tmp++;
        if (info[i]->inst == 0 && info[i]->label)
            get_label_code(info[i], labels, line);
    }
}

int finish_label(char **last_line)
{
    if (last_line[1] != NULL)
        return -1;
    if (find_double_point(last_line[0]) == 0)
        return 0;
    return -1;
}
