#pragma once
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
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "tableau.h"
#include "historique.h"
#include "Grille.h"

/**
 * @brief Vérifie si une case est une mine
 * @param [in] coup : la case
 * @param [in] mines : le conteneur de mines
 * @return renvoie si la case est une mine ou pas
 */
bool verifCase(unsigned char coup, Conteneur mines);

/**
 * @brief Renvoie le nombre de mines entourant une case
 * @param [in] grille : la grille de la partie
 * @param [in] i : l'indice de la case
 * @param [in] mines : le conteneur de mines
 * @param [in] ligne : le nombre de lignes
 * @param [in] colonne : le nombre de colonne
 * @pre i < grille.capacite
 */
unsigned int ProdCase(Grille grille, unsigned int i, Conteneur mines, unsigned int ligne, unsigned int colonne);

/**
 * @brief Produit une ligne de "___"
 * @param [in] colonne le nombre de colonne de la grille
 */
void ProdLigne(unsigned int colonne);

/**
 * @brief Modifie le contenue d'une case de la grille
 * @param [in] idcase : l'indice de la case à modifier
 * @param [in] ligne : le nombre de ligne de la grille
 * @param [in] colonne : le nombre de colonne de la grille
 * @param [in] mineAutourCase : le nombre de mines entourant la case
 * @param [in] Mines : le conteneur de mines
 * @param [in-out] Grille : la grille de la partie
 * @param [in] historique : l'historique de coup
 * @pre idcase < grille.capacite
 */
void DemasqueCase(unsigned int idcase, unsigned int ligne, unsigned int colonne, unsigned int mineAutourCase, Conteneur Mines, Grille Grille, Historique historique);

void AfficherGrille(Grille grille, unsigned int ligne, unsigned int colonne);

/** 
 * @brief Produit une grille de demineur à partir de paramètres
 * @param [in] le nombre de ligne
 * @param [in] le nombre de colonne
 * @param [in] le nombre de mines
 * @param [in] la position des mines
 * @param [in] le nombre de coups
 * @param [in] l'historique de coups
 */
void ProdGrilleCommande(Grille grille,unsigned int ligne, unsigned int colonne, unsigned int nbMines, Conteneur Mines, unsigned int nbCoups, Historique historique, bool affichage);


/**
 * @brief Produit une grille de demineur à partir de la lecture d'une grille
 * @param [in-out] la grille 
 * @param [in-out] le nombre de lignes
 * @param [in-out] le nombre de colonnes
 */
void ProdGrilleEntre(Grille& partie, unsigned int& lignes, unsigned int& colonnes);

#endif