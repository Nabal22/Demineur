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

bool verifCase(unsigned char coup, Conteneur mines) {
	for (unsigned int i = 0; i < mines.capacite; i++) {
		if (coup == mines.tab[i]) {
			return true;
		}
	}
	return false;
}

unsigned int ProdCase(Grille grille, unsigned int i , Conteneur mines, unsigned int ligne, unsigned int colonne) {
	unsigned int mineAlentour = 0;
	unsigned int j;
	if (i == 0) {
		for (j = 0; j <= mines.capacite; j++) {
			if ((i+1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i + colonne) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i + colonne + 1) == mines.tab[j]) {
				++mineAlentour;
			}
		}
	}
	else if (i == colonne - 1) {
		for (j = 0; j <= mines.capacite; j++) {
			if ((i - 1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i + colonne) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i + colonne - 1) == mines.tab[j]) {
				++mineAlentour;
			}
		}
	}
	else if (i == ((ligne*colonne-1)-ligne)) {
		for (j = 0; j <= mines.capacite; j++) {
			if ((i + 1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i - colonne) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i - colonne + 1) == mines.tab[j]) {
				++mineAlentour;
			}
		}
	}
	else if (i == (ligne * colonne - 1)) {
		for (j = 0; j <= mines.capacite; j++) {
			if ((i - 1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i - colonne) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i - colonne - 1) == mines.tab[j]) {
				++mineAlentour;
			}
		}
	}
	else {
		for (j = 0; j <= mines.capacite; j++) {
			if ((i - 1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i - colonne - 1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i - colonne) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i - colonne + 1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i + 1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i + colonne + 1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i + colonne) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i + colonne - 1) == mines.tab[j]) {
				++mineAlentour;
			}
		}
	}
	return mineAlentour;
}

void ProdLigne(unsigned int colonne) {
	unsigned int k;
	for (k = 0; k < colonne; k++) {
		cout << " ___";
	}
	cout << endl;
}

void DemasqueCase(unsigned int idcase, unsigned int ligne, unsigned int colonne, unsigned int mineAutourCase, Conteneur Mines, Grille Grille, Historique historique) {
	cout << idcase << endl;
	mineAutourCase = ProdCase(Grille, historique.position->tab[idcase], Mines, ligne, colonne);
	if (mineAutourCase == 0) {
		ecrireGrille(Grille, historique.position->tab[idcase], ' ');

		// case coin haut gauche
		if (idcase == 0) {
			cout << "test1" << endl;
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, Grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, Grille, historique);
		}
		// case coin bas gauche
		else if ((idcase % colonne == 0) && ((ligne * colonne - colonne) < idcase < (colonne * ligne))) {
			cout << "test2" << endl;
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, Grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, Grille, historique);
		}

		// case coin haut droit
		else if ((((idcase + 1) % colonne) == 0) && (0 < idcase < colonne)) {
			cout << "test3" << endl;
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, Grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, Grille, historique);
		}

		// case coin bas droit
		else if (((ligne * colonne - colonne) < idcase < (colonne * ligne)) && (((idcase + 1) % colonne) == 0)) {
			cout << "test4" << endl;
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, Grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, Grille, historique);
		}

		// case gauche
		else if (idcase % colonne == 0) {
			cout << "test5" << endl;
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, Grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, Grille, historique);
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, Grille, historique);
		}

		// case droite
		else if (((idcase+1)% colonne) == 0) {
			cout << "test6" << endl;
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, Grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, Grille, historique);
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, Grille, historique);
		}

		// case haut
		else if (0 <= idcase < colonne) {
			cout << "test7" << endl;
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, Grille, historique);
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, Grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, Grille, historique);
		}

		// case bas
		else if ((ligne*colonne-colonne) < idcase < (colonne*ligne)) {
			cout << "test8" << endl;
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, Grille, historique);
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, Grille, historique);
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, Grille, historique);
		}
		else {
			cout << "test9" << endl;
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, Grille, historique);
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, Grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, Grille, historique);
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, Grille, historique);
		}
		/*DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, Grille, historique);
		DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, Grille, historique);
		DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, Grille, historique);
		DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, Grille, historique);*/
	}
	else {
		ecrireGrille(Grille, historique.position->tab[idcase], mineAutourCase + 48);
		return;
	}
}

void ProdGrille(unsigned int ligne, unsigned int colonne, unsigned int nbMines, Conteneur Mines, unsigned int nbCoups, Historique historique) {
	cout << ligne << " " << colonne << endl;
	
	unsigned int i, j, k;
	Grille grille;
	unsigned int mineAutourCase;
	initGrille(grille,colonne*ligne);

	for (i = 0; i < grille.capacite; i++) { // On remplit la grille de .
		ecrireGrille(grille, i, '.');
	}
	/* Pour chaque coup,
	on vérifie si c'est une mine 
		si oui : fin, on rentre m
				on rentre m pour les autres mines
		si non : on va compter les mines voisines, 
				si il y en a 0 on rentre " " dans la case et on refait la même chose pour ses cases voisines
				si il y en a 0< on rentre le nombre de mines environnantes "nbmines" et fin
	*/
	for (i = 0; i < nbCoups; i++)
	{
		mineAutourCase = 0;
		/*Cas ou l'on découvre une mine*/
		if (historique.type->tab[i] == 'D' && verifCase(historique.position->tab[i], Mines)) {
			for (j = 0; j < Mines.capacite; j++) {
				ecrireGrille(grille, Mines.tab[j], 'm');
			}
		}
		if (historique.type->tab[i] == 'D' && !verifCase(historique.position->tab[i], Mines)) {
			mineAutourCase = ProdCase(grille, historique.position->tab[i], Mines, ligne, colonne);
			DemasqueCase(historique.position->tab[i], ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
		/*Cas ou l'on marque une case*/
		if (historique.type->tab[i] == 'M') {
			ecrireGrille(grille, historique.position->tab[i], 'x');
		}
	}

	// Affichage de la grille
	ProdLigne(colonne);
	for (i = 0, j=0; i < grille.capacite; i++,j++) {
		if (j == colonne)
		{
			cout <<" |"<< endl;
			ProdLigne(colonne);
			j = 0;
		}
		if (j == 0) {
			cout << "| " << grille.tab[i];
		}
		else {
			cout << " | " << grille.tab[i];
		}
	}
	cout << " |";
	cout << endl;
	ProdLigne(colonne);
}