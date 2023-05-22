/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-pierre.giordano
** File description:
** tools
*/
#include "../include/asm.h"

int find_double_point(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == ':')
            return 0;
    }
    return -1;
}

int	my_getnbr_ind(char const *str, int indice)
{
    int	nb = 0;
    int	signe = 1;

    while (str[indice] == '+' || str[indice] == '-'){
        if (str[indice] == '-')
            signe = signe * (-1);
        indice = indice + 1;
    }
    while (str[indice] != '\0'){
        if (str[indice] >= '0' && str[indice] <= '9'){
            nb = nb * 10;
            nb = nb + str[indice] - '0';
            indice = indice + 1;
        } else
            return (nb * signe);
    }
    return (nb * signe);
}

int my_strlen_hashtag(char const *str)
{
    int cmpt = 0;

    for (int i = 0; str[i] != '\0' && str[i] != '#'; i++)
        cmpt++;
    return cmpt;
}
