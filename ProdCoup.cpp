/**
 * @file probleme.cpp
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 1 27/11/2021
 * @brief Projet SDA démineur - Exercice 1
 * Structures de donn�es et algorithmes - BUT 1 Paris 16
 */

#include <iostream>
#include <time.h>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Grille.h"
#include "ProdGrille.h"





void prodCoup(Grille partie, unsigned int colonne, unsigned int ligne) {
	srand(time(NULL));
    unsigned int tmp = rand() % (colonne * ligne);
    bool coupPlace = false;
    while (coupPlace) {
        if (partie.tab[tmp] == '.') {
            ecrireGrille(partie, tmp, ' ');
            //faire en sorte que la grille s'actualise par rapport à ce nouveau coup
            coupPlace = true;
        }
        else
        {
            tmp = rand() % (colonne * ligne);
        }
    }

}