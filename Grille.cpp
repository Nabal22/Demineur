#pragma once

#include <assert>
#include "Grille.h"

void initGrille(Grille& c, unsigned int capa) {
    // V�rifiez la pr�condition
    assert(capa > 0);
    /**L'objectif est d'initialiser tous les attributs du Grille c
     * de telle sorte que le Grille soit vide
     * Dans notre cas, le support est un tableau de taille (c.capacite), qui est d' initialiser */
    c.capacite = capa;
    /** On alloue le tableau en mémoire dynamique */
    c.tab = new unsigned char[capa];
}


void detruireGrille(Grille& c) {
    delete[] c.tab;
    c.tab = NULL;
    c.capacite = 0;
}


unsigned char lireGrille(const Grille& c, unsigned int i) {
    /** V�rifiez la precondition
    * et retournez l'item � la position i dans le Grille c */
    assert(i < c.capacite);
    return c.tab[i];
}


void ecrireGrille(Grille& c, unsigned int i, const unsigned char& it) {
    assert(i <= c.capacite);
    c.tab[i] = it;
}