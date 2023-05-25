/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** add_tab
*/

#include "../include/corewar.h"

champ_t **add_tab(champ_t **warriors, int adress, char *file, int nb_p)
{
    int taille = 0;
    champ_t **new_warriors = NULL;

    while (warriors[taille] != NULL)
        taille++;
    new_warriors = malloc(sizeof(champ_t *) * (taille + 2));
    new_warriors[0] = malloc(sizeof(champ_t));
    new_warriors[0]->adress = adress;
    new_warriors[0]->file = my_strdup(file);
    new_warriors[0]->nb_prog = nb_p;
    new_warriors[0]->pc = 0;
    new_warriors[0]->carry = 0;
    for (int i = 0; i < taille; i++)
        new_warriors[i + 1] = warriors[i];
    new_warriors[taille + 1] = NULL;
    free(warriors);
    return new_warriors;
}
