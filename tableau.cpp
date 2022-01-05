/**
 * @file tableau.cpp
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 8 05/01/2022
 * @brief Projet SDA démineur - Produire et manipuler un conteneur
 * Structures de données et algorithmes - BUT 1 Paris 16
*/
#pragma once
#include <iostream>
#include <cassert>
#include "tableau.h"
using namespace std;


void initialiser(Conteneur& c, const unsigned int capa) {
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


unsigned int lire(const Conteneur& c, const unsigned int i) {
    /** V�rifiez la precondition
    * et retournez l'item � la position i dans le conteneur c */
    assert(i < c.capacite);
    return c.tab[i];
}


void ecrire(Conteneur& c, const unsigned int i, const unsigned int& it) {
    assert(i <= c.capacite);
    c.tab[i] = it;
}