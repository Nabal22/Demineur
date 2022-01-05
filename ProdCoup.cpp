/**
 * @file probleme.cpp
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 1 27/11/2021
 * @brief Projet SDA démineur - Produire un coup - commande 5
 * Structures de donn�es et algorithmes - BUT 1 Paris 16
 */

#include <iostream>
#include <time.h>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ProdGrille.h"
#include "ProdCoup.h"

using namespace std;

void prodCoup(const Grille partie, const unsigned int colonne, const unsigned int ligne) {
	srand(time(NULL));
    unsigned int tmpPosition = rand() % (colonne * ligne), tmpType = tmpPosition % 2;
    bool coupPlace = false;

    while (!coupPlace) {
        if(partie.tab[tmpPosition] == '.') {
            coupPlace = true;
        }
        else
        {
            tmpPosition = rand() % (colonne * ligne);
        }
    }

    if (tmpType) {
        cout << 'D';
    }
    else
    {
        cout << 'M';
    }
    cout << tmpPosition << endl;
}