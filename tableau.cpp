#pragma once
/**
 * @file Conteneur.cpp
 * Projet sem03-tp-Cpp1
 * @author Talagrand Alban - Rengewetter Simon
 * @version 2 18/11/11
 * @brief Caracteristiques d'un tableau
 */

#include <iostream>
#include <cassert>
#include "tableau.h"
using namespace std;


void initialiser(Conteneur& c, unsigned int capa) {
    // V�rifiez la pr�condition
    assert(capa > 0);
        /**L'objectif est d'initialiser tous les attributs du conteneur c
         * de telle sorte que le conteneur soit vide
         * Dans notre cas, le support est un tableau de taille (c.capacite), qui est d' initialiser */
        c.capacite = capa;
        /** On alloue le tableau en mémoire dynamique */
        c.tab = new unsigned int[capa];
}


void detruire(Conteneur& c) {
    delete [] c.tab;
    c.tab = NULL;
    c.capacite = 0;
}


unsigned int lire(const Conteneur& c, unsigned int i) {
    /** V�rifiez la precondition
    * et retournez l'item � la position i dans le conteneur c */
    assert(i < c.capacite);
    return c.tab[i];
}


void ecrire(Conteneur& c, unsigned int i, const unsigned int& it) {
    assert(i <= c.capacite);
    c.tab[i] = it;
}