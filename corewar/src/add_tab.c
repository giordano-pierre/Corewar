/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** add_tab
*/

#include "../include/corewar.h"

void add_value(champ_t *champion)
{
    for (int i = 0; i < REG_NUMBER; i++)
        champion->reg[i] = 0;
    champion->carry = 0;
    champion->code = NULL;
    champion->comment = NULL;
    champion->name = NULL;
    champion->pc = 0;
    champion->size = 0;
    champion->is_alive = 0;
}

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
    add_value(new_warriors[0]);
    for (int i = 0; i < taille; i++)
        new_warriors[i + 1] = warriors[i];
    new_warriors[taille + 1] = NULL;
    free(warriors);
    return new_warriors;
}
