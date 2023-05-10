/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** my_str_to_word_array
*/
#include "../include/asm.h"

int have_second_quote(char const *str, int ind)
{
    for (ind = ind + 1; str[ind] != '\0'; ind++) {
        if (str[ind] == '"')
            return 0;
    }
    return -1;
}

int count_char(char const *str, int i)
{
    int count = 0;

    if (str[i] == '"' && have_second_quote(str, i) == 0) {
        count++;
        for (i = i + 1; str[i] != '"' && str[i] != '\0'; i++)
            count++;
        count++;
    } else {
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
                && str[i] != '\0' && str[i] != COMMENT_CHAR) {
            count++;
            i++;
        }
    }
    return (count);
}

void skip_quote(char const *str, int *ind)
{
    *ind = *ind + 1;
    while (str[*ind] != '"' && str[*ind] != '\0')
        *ind = *ind + 1;
}

int count_word (char const *str)
{
    int nb_word = 0;
    int nb_char = my_strlen (str);
    for (int i = 0; i < nb_char; i++){
        while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            i++;
        if (str[i] == '"' && have_second_quote(str, i) == 0)
            skip_quote(str, &i);
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'
            && str[i] != '\0' && str[i] != COMMENT_CHAR)
            nb_word++;
        while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'
            && str[i] != '\0' && str[i] != COMMENT_CHAR)
            i++;
    }
    return nb_word;
}

char **my_str_to_word_array(char const *str)
{
    int nb_word = count_word (str);
    int n;
    int ind = 0;
    char **tab = malloc (sizeof(char *) * (nb_word + 1));

    for (int i = 0; i < nb_word; i++){
        while (str[ind] == ' ' || str[ind] == '\t' || str[ind] == '\n') {
            ind++;
        }
        n = count_char(str, ind);
        tab[i] = malloc(sizeof(char) * (n + 1));
        for (int j = 0; j < n; j++) {
            tab[i][j] = str[ind];
            ind++;
        }
        tab[i][n] = '\0';
    }
    tab[nb_word] = NULL;
    return (tab);
}
