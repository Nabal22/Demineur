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
#include "Grille.h"
#include "ProdGrille.h"
using namespace std;

void ProdCoup() {
	Grille partie;
	unsigned int lignes, colonnes,i=0;
	unsigned char tmp, tmp2;

	cin >> lignes >> colonnes;
	initGrille(partie, (lignes * colonnes));

	while (i < partie.capacite)
	{
		tmp = 0;
		tmp2 = 0;
		cin >> tmp;
		if (tmp != '_') {
			cin >> tmp2;
			if (tmp2 == '|' && tmp=='|') {
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
		else if ((((i + 1) % colonnes) == 0) && (tmp=='_') ){
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
	AfficherGrille(partie, lignes, colonnes);
}