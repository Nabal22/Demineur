/**
 * @file probleme.cpp
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 1 27/11/2021
 * @brief Projet SDA démineur - Exercice 1
 * Structures de donn�es et algorithmes - BUT 1 Paris 16
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cassert>
#include "probleme.h"
#include "tableau.h"

using namespace std;

void Create(unsigned int ligne, unsigned int colonne, unsigned int const nbMine){
    assert((ligne * colonne) > nbMine);
    srand (time(NULL));
    unsigned int i , j=0;
    Conteneur tabMine;

    initialiser(tabMine, nbMine);
    cout << ligne << " " << colonne << " " << nbMine << " ";

    for (i=0 ; i<nbMine ; i++){
        unsigned int tmp = rand() % (colonne*ligne);
        while (j < tabMine.capacite + 1) {
            if (tmp != tabMine.tab[j]) {
                j++;
            }
            else
            {
                j = 0;
                tmp = rand() % (colonne * ligne);
            }
        }
        ecrire(tabMine, i, tmp);
        cout << lire(tabMine,i) << " ";
        j = 0;
    }
    detruire(tabMine);
}
