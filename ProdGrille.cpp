/**
 * @file ProdGrille.cpp
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 8 05/01/2022
 * @brief Projet SDA démineur - Produire et manipuler une grille et ses cases
 * Structures de donn�es et algorithmes - BUT 1 Paris 16
*/
#pragma once
#include <iostream>
#include <cassert>
#include "ProdGrille.h"

using namespace std;

bool verifCase(const unsigned char coup, const Conteneur mines) {
	for (unsigned int i = 0; i < mines.capacite; i++) {
		if (coup == mines.tab[i]) {
			return true;
		}
	}
	return false;
}

unsigned int ProdCase(Grille grille, const unsigned int i , Conteneur mines, const unsigned int ligne, const unsigned int colonne) {
	assert(i < grille.capacite);
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

void ProdLigne(const unsigned int colonne) {
	unsigned int k;
	for (k = 0; k < colonne; k++) {
		cout << " ___";
	}
	cout << endl;
}

void DemasqueCase(const unsigned int idcase, const unsigned int ligne, const unsigned int colonne, unsigned int mineAutourCase, Conteneur Mines, Grille grille, Historique historique) {
	assert(idcase < grille.capacite);
	mineAutourCase = ProdCase(grille, idcase, Mines, ligne, colonne);
	if (mineAutourCase == 0 && grille.tab[idcase]=='.' && idcase < grille.capacite) {
		ecrireGrille(grille, idcase, ' ');
		// case coin haut gauche
		if (idcase == 0) {
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
		// case coin bas gauche
		else if (((ligne * colonne - 1) - ligne) == idcase) {
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}

		// case coin haut droit
		else if (colonne - 1 == 0) {
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}

		// case coin bas droit
		else if ((ligne * colonne - 1) == idcase) {
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
		// case haut
		else if (idcase < colonne) {
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + 1 , ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
		// case gauche
		else if (idcase % colonne == 0) {
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
		// case droite
		else if (((idcase + 1) % colonne) == 0) {
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
		// case bas
		else if (idcase >= (colonne*ligne-colonne) && idcase<grille.capacite) {
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
		else {
			DemasqueCase(idcase - colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase - 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + 1, ligne, colonne, mineAutourCase, Mines, grille, historique);
			DemasqueCase(idcase + colonne, ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
	}
	else {
		if (grille.tab[idcase] == '.' && idcase < grille.capacite) {
			ecrireGrille(grille, idcase, mineAutourCase + 48);
		}
	}
}

void AfficherGrille(const Grille grille, const unsigned int ligne, const unsigned int colonne) {
	unsigned int i, j;
	cout << ligne << " " << colonne << endl;
	ProdLigne(colonne);
	for (i = 0, j = 0; i < grille.capacite; i++, j++) {
		if (j == colonne)
		{
			cout << " |" << endl;
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

void ProdGrilleCommande(Grille grille, const unsigned int ligne, const unsigned int colonne, const unsigned int nbMines, Conteneur Mines, const unsigned int nbCoups, const Historique historique, const bool affichage) {
	unsigned int i, j;
	unsigned int mineAutourCase;
	
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
		if ( ( (historique.type->tab[i] == 'D') && verifCase(historique.position->tab[i], Mines) ) || (historique.type->tab[i] == 'M' && !verifCase(historique.position->tab[i], Mines) ) ) {
			for (j = 0; j < Mines.capacite; j++) {
				ecrireGrille(grille, Mines.tab[j], 'm');
			}
			if (historique.type->tab[i] == 'M') {
				ecrireGrille(grille, historique.position->tab[i], 'x');
			}
		}
		if (historique.type->tab[i] == 'D' && !verifCase(historique.position->tab[i], Mines)) {
			mineAutourCase = ProdCase(grille, historique.position->tab[i], Mines, ligne, colonne);
			DemasqueCase(historique.position->tab[i], ligne, colonne, mineAutourCase, Mines, grille, historique);
		}
		/*Cas ou l'on marque une case*/
		if (historique.type->tab[i] == 'M' && verifCase(historique.position->tab[i], Mines)) {
			ecrireGrille(grille, historique.position->tab[i], 'x');
		}
	}
	// Affichage de la grille
	if (affichage) {
		AfficherGrille(grille, ligne, colonne);
	}
}

void ProdGrilleEntre(Grille& partie, const unsigned int& lignes, const unsigned int& colonnes){
	unsigned int  i = 0;
	unsigned char tmp, tmp2;

	while (i < partie.capacite) {
		tmp = 0;
		tmp2 = 0;
		cin >> tmp;
		if (tmp != '_') {
			cin >> tmp2;
			if (tmp2 == '|' && tmp == '|') {
				tmp2 = ' ';
				ecrireGrille(partie, i, tmp2);
				i++;
			}
			else {
				if (tmp2 == '|') {
					ecrireGrille(partie, i, tmp);
				}
				else {
					ecrireGrille(partie, i, tmp2);
				}
				i++;
			}
		}
		else if ((((i + 1) % colonnes) == 0) && (tmp == '_')) {
			tmp2 = ' ';
			ecrireGrille(partie, i, tmp2);
			i++;
		}
		else {
			if (i == partie.capacite - 1) {
				break;
			}
		}
	}
}