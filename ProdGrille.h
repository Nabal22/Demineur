#ifndef _PRODGRILLE_
#define _PRODGRILLE_

/**
 * @file probleme.cpp
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 1 27/11/2021
 * @brief Projet SDA démineur - Exercice 1
 * Structures de donn�es et algorithmes - BUT 1 Paris 16
*/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "ProdGrille.h"
#include "Grille.h"
#include "tableau.h"
#include "historique.h"
#include "probleme.h"

/** @brief Affiche la grille du demineur (Commande 2)
 * @param [in] le nombre de ligne
 * @param [in] le nombre de colonne
 * @param [in] le nombre de mines
 * @param [in] la position des mines
 * @param [in] le nombre de coups
 * @param [in] l'historique de coups
 * @pre*/
void ProdGrille(unsigned int ligne, unsigned int colonne, unsigned int nbMines, Conteneur Mines, unsigned int nbCoups, Historique historique);

#endif