#pragma once
#ifndef _ETATPARTIE_
#define  _ETATPARTIE_


#include <iostream>
#include "probleme.h"
#include "ProdGrille.h"

/**
 * @brief Renvoie si une partie est gagné ou non
 * @param[in] grille : la grille
 * @param[in] mines : le conteneur de mines
 * @return partie gagné ou non
 */
bool estGagne(Grille grille, Conteneur mines);

/**
 * @brief Renvoie si une partie est perdu ou non
 * @param[in] grille : la grille
 * @param[in] mines : le conteneur de mines
 * @return partie gagné ou non
 */
bool estPerdu(Grille grille, Conteneur mines);

#endif