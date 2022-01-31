/**
 * @file EtatPartie.cpp
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 5 05/01/2022
 * @brief Projet SDA demineur - Fonction relative au commande 3 (game won/not won) et 4 (game lost/not lost)
 * Structures de donnees et algorithmes - BUT 1 Paris 16 - Changement
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cassert>
#include "EtatPartie.h"

using namespace std;

bool estGagne(const Grille grille, const Conteneur mines) {
	bool partieGagne = false;
	for (unsigned int i = 0; i < grille.capacite; i++) {
		if (lireGrille(grille, i) == ' ' || lireGrille(grille, i) == '1' || lireGrille(grille, i) == '2' || lireGrille(grille, i) == '3' || lireGrille(grille, i) == '4'
			|| lireGrille(grille, i) == '5' || lireGrille(grille, i) == '6' || lireGrille(grille, i) == '7' || lireGrille(grille, i) == '8') {
			partieGagne = true;
		}
		else if (lireGrille(grille, i) == '.' && verifCase(i, mines))
		{
			partieGagne = true;
		}
		else {
			partieGagne = false;
			break;
		}
	}
	return partieGagne;
}

bool estPerdu(const Grille grille, const Conteneur mines) {
	bool partiePerdu = false;
	for (unsigned int i = 0; i < grille.capacite; i++) {
		if (lireGrille(grille, i) == 'm') {
			partiePerdu = true;
			break;
		}
	}
	return partiePerdu;
}