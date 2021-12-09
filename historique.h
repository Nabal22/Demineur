#pragma once
#ifndef _HISTORIQUE_
#define _HISOTIRQUE_
#include "tableau.h"
#include "Grille.h"
/** @brief Contient l'historique des coups
 *
 */
struct Historique {
	Grille* type; // de type conteneur ( Pas de type char car erreur lors de la conversion dans le main )
	Grille* position;
};

/*
Si on veut mettre "type" de type char* il faut que l'on modifie le type conteneur car "type" qui est un tableau de char* ne peut pas se convertir en "couptype"*/

#endif