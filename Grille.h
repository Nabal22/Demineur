#pragma once
#ifndef _GRILLE_
#define _GRILLE_

/**
 * @file probleme.cpp
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 1 27/11/2021
 * @brief Projet SDA démineur - Exercice 1
 * Structures de donn�es et algorithmes - BUT 1 Paris 16
*/
#pragma once
struct Grille {
	unsigned int capacite; 	// capacite du Grille (>0)
	unsigned char* tab;	// support du Grille, un tableau alloue en memoire dynamique de taille fixee (capacite) 
};

void initGrille(Grille& c, unsigned int capa);

void detruireGrille(Grille& c);

unsigned char lireGrille(const Grille& c, unsigned int i);

void ecrireGrille(Grille& c, unsigned int i, const unsigned char& it);

#endif