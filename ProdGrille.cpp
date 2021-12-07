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
#include <iostream>

#include "ProdGrille.h"
#include "Grille.h"
#include "tableau.h"

using namespace std;

void ProdGrille(unsigned int ligne, unsigned int colonne, unsigned int nbMines, Conteneur Mines, unsigned int nbCoups, Historique historique) {
	cout << ligne << " " << colonne << endl;

	unsigned int i;
	unsigned int j;
	bool verif = false;
	Grille grille;
	initGrille(grille,colonne*ligne);

	for (i = 0; i >= taille; i++) {
		grille.tab[i] = " ";
	}


	for (i = 0; i >= nbCoups; i++) {
		grille.tab[historique.position[i]] = "e";
	}

	for (i = 0; i >= nbCoups; i++) {
		if (historique.type[i] == 'D' && grille.tab[historique.position->tab[i]] != "e") {
			grille.tab[historique.position->tab[i]] = " ";
		}
		else {
			verif = true;
		}

		if (historique.type[i] == 'm') {
			grille.tab[historique.position->tab[i]] = 'x';
		}
	}

	if (verif) {
		for (j = 0; j <= nbMines; j++) {
			grille.tab[Mines.tab[j]] = 'm';
		}
	}

	for (i = 0; i <= ligne; i++) {
		cout << grille.tab[i];
	}
}
