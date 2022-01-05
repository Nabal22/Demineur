/**
 * @file EtatPartie.h
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 5 05/01/2022
 * @brief Projet SDA demineur - Header de EtatPartie.cpp - Fonction relative au commande 3 (game won/not won) et 4 (game lost/not lost)
 * Structures de donnees et algorithmes - BUT 1 Paris 16
 */
#pragma once
#ifndef _ETATPARTIE_
#define  _ETATPARTIE_

#include <iostream>
#include "probleme.h"
#include "ProdGrille.h"

 /**
  * @brief Renvoie si une partie est gagn� ou non
  * @param[in] grille : la grille
  * @param[in] mines : le conteneur de mines
  * @return partie gagn� ou non
  */
bool estGagne(const Grille grille, const Conteneur mines);

/**
 * @brief Renvoie si une partie est perdu ou non
 * @param[in] grille : la grille
 * @param[in] mines : le conteneur de mines
 * @return partie gagn� ou non
 */
bool estPerdu(const Grille grille, const Conteneur mines);
#endif