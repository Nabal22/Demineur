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
#include "PartieGagne.h"
#include "Grille.h"
#include "ProdGrille.h"
using namespace std;

bool estGagne (Grille grille, Conteneur mines){
	bool partieGagne = false;
	for (unsigned int i = 0 ; i < grille.capacite; i++) {
		if ( lireGrille(grille, i) == ' ' || lireGrille(grille, i) == '1' || lireGrille(grille, i) == '2' || lireGrille(grille, i) == '3' || lireGrille(grille, i) == '4' 
			|| lireGrille(grille, i) == '5'|| lireGrille(grille, i) == '6' || lireGrille(grille, i) == '7' || lireGrille(grille, i) == '8') {
			partieGagne = true;
			cout << i << " - " << lireGrille(grille, i) << endl;
		}
		else if (lireGrille(grille, i) == '.' && verifCase(i,mines) )
		{
			cout << "mine en : " << i << endl;
			partieGagne = true;
		}
		else {
			cout << endl << i;
			partieGagne = false;
			break;
		}
	}
	return partieGagne;
}