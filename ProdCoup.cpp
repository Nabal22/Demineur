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

// Réussir à faire en sorte que l'on rentre bien chaque 

void ProdCoup() {
	Grille partie;
	unsigned int lignes, colonnes;
	cin >> lignes >> colonnes;
	initGrille(partie, (lignes * colonnes));

	AfficherGrille(partie, lignes, colonnes);
}