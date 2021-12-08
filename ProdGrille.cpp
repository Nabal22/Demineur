#pragma once
/**
 * @file probleme.cpp
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 1 27/11/2021
 * @brief Projet SDA démineur - Exercice 1
 * Structures de donn�es et algorithmes - BUT 1 Paris 16
*/
#include "ProdGrille.h"
#include "Grille.h"
using namespace std;

void ProdGrille(unsigned int ligne, unsigned int colonne, unsigned int nbMines, Conteneur Mines, unsigned int nbCoups, Historique historique) {
	cout << ligne << " " << colonne << endl;
	
	unsigned int i, j;
	bool verif = false;
	Grille grille;

	
	initGrille(grille,colonne*ligne);

	for (i = 0; i < grille.capacite; i++) { // On remplit la grille de .
		ecrireGrille(grille, i, '.');
	}
	
	for (i = 0; i < nbCoups; i++) { // coup joué par l'utilsateur
		ecrireGrille(grille, historique.position->tab[i], 'e');
	}

	for (i = 0; i < nbCoups; i++) {
		if (historique.type->tab[i] == 'D' && historique.position->tab[i] == Mines.tab[i]) {
			verif = true;
		}
		else {
			ecrireGrille(grille, historique.position->tab[i], ' ');
		}

		if (historique.type->tab[i] == 'M') {
			ecrireGrille(grille, historique.position->tab[i], 'x');
		}
	}
	cout << endl;
	cout << "valeur verif" << verif;
	/*
	if (verif) {
		for (j = 0; j < nbMines; j++) {
			ecrireGrille(grille, Mines.tab[j], 'm');
		}
	}
	*/
	// affichage temp
	for (i = 0, j=0; i < grille.capacite; i++,j++) {
		if (j == colonne) {
			cout << endl;
			j = 0;
		}
		cout << "| " << grille.tab[i] << " |";
	}
}