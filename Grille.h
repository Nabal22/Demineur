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
