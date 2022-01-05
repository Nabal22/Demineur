/**
 * @file probleme.h
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 6 27/12/2021
 * @brief Projet SDA demineur - Header de probleme.cpp - Produire un probleme
 * Structures de donnees et algorithmes - BUT 1 Paris 16
 */
#pragma once
#include "tableau.h"

 /** @brief Produit un probl�me
  *  @param[in] ligne le nombre de lignes
  *  @param[in] colonne le nombre de colonnes
  *	@param[in] nbMine le nombre de mines
  *  @pre nbMine < (ligne*colonne)
  */
void Create(const unsigned int ligne, const unsigned int colonne, const unsigned int nbMine);