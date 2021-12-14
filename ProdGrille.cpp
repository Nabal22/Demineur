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

//2 4 6 5 1 5 12 7 19 3 D15 M5 D0
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
	//gauche
	else if (i % colonne == 0) {
		for (j = 0; j <= mines.capacite; j++) {
			if ((i + 1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i + colonne) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i - colonne) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i - colonne + 1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i + colonne + 1) == mines.tab[j]) {
				++mineAlentour;
			}
		}
	}
	//droite
	else if (((i + 1) % colonne) == 0) {
		cout << "TEEEESSSSTTTT" << endl;
		for (j = 0; j <= mines.capacite; j++) {
			if ((i - 1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i + colonne) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i - colonne) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i - colonne - 1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i + colonne - 1) == mines.tab[j]) {
				++mineAlentour;
			}
		}
	}
	//haut
	else if (i < colonne) {
		for (j = 0; j <= mines.capacite; j++) {
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
			if ((i - 1) == mines.tab[j]) {
				++mineAlentour;
			}
		}
	}
	//bas
	else if (i >= (colonne * ligne - colonne) && i < grille.capacite) {
		for (j = 0; j <= mines.capacite; j++) {

			if ((i + 1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i - colonne + 1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i - colonne) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i - colonne - 1) == mines.tab[j]) {
				++mineAlentour;
			}
			if ((i - 1) == mines.tab[j]) {
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

void DemasqueCase(unsigned int idcase, unsigned int ligne, unsigned int colonne, unsigned int mineAutourCase, Conteneur Mines, Grille grille, Historique historique) {
	mineAutourCase = ProdCase(grille, idcase, Mines, ligne, colonne);
	cout <<"ID :  " << idcase << " | Mine autour de case : " << mineAutourCase << endl;
	if (mineAutourCase == 0 && grille.tab[idcase]=='.' && idcase < grille.capacite) {
		ecrireGrille(grille, idcase, ' ');
		// case coin haut gauche
		if (idcase == 0) {
			cout << "case coin haut gauche" << endl;
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
		// case coin bas gauche
		else if (((ligne * colonne - 1) - ligne) == idcase) {
			cout << "case coin bas gauche" << endl;
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}

		// case coin haut droit
		else if (colonne - 1 == 0) {
			cout << "case coin haut droit" << endl;
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}

		// case coin bas droit
		else if ((ligne * colonne - 1) == idcase) {
			cout << "case coin bas droit" << endl;
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
		// case haut
		else if (idcase < colonne) {
			cout << " case haut" << endl;
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + 1 , ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
		// case gauche
		else if (idcase % colonne == 0) {
			cout << " case gauche" << endl;
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
		// case droite
		else if (((idcase + 1) % colonne) == 0) {
			cout << "case droite" << endl;
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
		// case bas
		else if (idcase >= (colonne*ligne-colonne) && idcase<grille.capacite) {
			cout << "// case bas" << endl;
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
		else {
			cout << "bien rentré mon gars";
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
	}
	else {
		cout << "nobug else" << endl;
		if (grille.tab[idcase] == '.' && idcase < grille.capacite) {
			ecrireGrille(grille, idcase, mineAutourCase + 48);
		}
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