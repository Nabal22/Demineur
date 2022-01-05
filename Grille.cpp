/**
 * @file Grille.h
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 5 05/01/2022
 * @brief Projet SDA démineur - Fichier relatif à la manipulation de conteneur Grille
 * Structures de donn�es et algorithmes - BUT 1 Paris 16
*/

#pragma once

#include <iostream>
#include <cassert>
#include "Grille.h"
using namespace std;

void initGrille(Grille& g, unsigned int capa) {
    // V�rifiez la pr�condition
    assert(capa > 0);
    /**L'objectif est d'initialiser tous les attributs du Grille c
     * de telle sorte que le Grille soit vide
     * Dans notre cas, le support est un tableau de taille (c.capacite), qui est d' initialiser */
    g.capacite = capa;
    /** On alloue le tableau en mémoire dynamique */
    g.tab = new unsigned char[capa];
}


void detruireGrille(Grille& g) {
    delete[] g.tab;
    g.tab = NULL;
    g.capacite = 0;
}


unsigned char lireGrille(const Grille& g, unsigned int i) {
    /** V�rifiez la precondition
    * et retournez l'item � la position i dans le Grille c */
    assert(i < g.capacite);
    return g.tab[i];
}


void ecrireGrille(Grille& g, unsigned int i, const unsigned char& it) {
    assert(i <= g.capacite);
    g.tab[i] = it;
}