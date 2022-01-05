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
#include "EtatPartie.h"

using namespace std;

bool estGagne (Grille grille, Conteneur mines) {
	bool partieGagne = false;
	for (unsigned int i = 0 ; i < grille.capacite; i++) {
		if ( lireGrille(grille, i) == ' ' || lireGrille(grille, i) == '1' || lireGrille(grille, i) == '2' || lireGrille(grille, i) == '3' || lireGrille(grille, i) == '4' 
			|| lireGrille(grille, i) == '5'|| lireGrille(grille, i) == '6' || lireGrille(grille, i) == '7' || lireGrille(grille, i) == '8') {
			partieGagne = true;
		}
		else if (lireGrille(grille, i) == '.' && verifCase(i,mines) ) {
			partieGagne = true;
		}
		else {
			partieGagne = false;
			break;
		}
	}
	return partieGagne;
}

bool estPerdu(Grille grille, Conteneur mines) {
	bool partiePerdu = false;
	for (unsigned int i = 0; i < grille.capacite; i++) {
		if (lireGrille(grille, i) == 'm') {
			partiePerdu = true;
			break;
		}
	}
	return partiePerdu;
}