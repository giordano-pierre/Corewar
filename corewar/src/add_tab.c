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
    while (warriors[taille] != NULL) {
        taille++;
    }
    champ_t **new_warriors = malloc((taille + 2) * sizeof(champ_t *));
    new_warriors[0] = sizeof(champ_t *);
    new_warriors[0]->adress = adress;
    new_warriors[0]->code = NULL;
    new_warriors[0]->comment = NULL;
    new_warriors[0]->file = file;
    new_warriors[0]->name = NULL;
    new_warriors[0]->nb_prog = nb_p;
    new_warriors[0]->pc = 0;
    for (int i = 0; i < taille; i++) {
        new_warriors[i + 1] = warriors[i];
    }
    new_warriors[taille + 1] = NULL;
    free(warriors);
    return new_warriors;
}
