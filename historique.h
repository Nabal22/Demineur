/**
 * @file historique.h
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 4 01/02/2022
 * @brief Projet SDA demineur - Header de Conteneur historique (historique.cpp)
 * Structures de donnees et algorithmes - BUT 1 Paris 16
 */
#pragma once
#ifndef _HISTORIQUE_
#define _HISOTIRQUE_
#include "tableau.h"
#include "Grille.h"

/** @brief Type Historique contenant un pointeur grille liés aux informations de type
 *  et un pointeur de grille liés aux informations de positions
 */
struct Historique {
	Grille* type; // Pointeur vers une grille contenant les types des coups
	Grille* position; // Pointeur vers une grille contenant la position des coups
};
#endif