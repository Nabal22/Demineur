/**
 * @file ProdGrille.h
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 8 05/01/2022
 * @brief Projet SDA démineur - Header de ProdGrille.cpp - Produire et manipuler une grille et ses cases
 * Structures de donn�es et algorithmes - BUT 1 Paris 16
*/
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

#include "historique.h"

/**
 * @brief Vérifie si une case est une mine
 * @param[in] coup : la case
 * @param[in] mines : le conteneur de mines
 * @return renvoie si la case est une mine ou pas
 */
bool verifCase(const unsigned char coup, const Conteneur mines);

/**
 * @brief Renvoie le nombre de mines entourant une case
 * @param[in] grille : la grille de la partie
 * @param[in] i : l'indice de la case
 * @param[in] mines : le conteneur de mines
 * @param[in] ligne : le nombre de lignes
 * @param[in] colonne : le nombre de colonne
 * @pre i < grille.capacite
 */
unsigned int ProdCase(Grille grille, const unsigned int i, Conteneur mines, const unsigned int ligne, const unsigned int colonne);

/**
 * @brief Produit une ligne de "___"
 * @param[in] colonne le nombre de colonne de la grille
 */
void ProdLigne(const unsigned int colonne);

/**
 * @brief Modifie le contenue d'une case de la grille
 * @param[in] idcase : l'indice de la case à modifier
 * @param[in] ligne : le nombre de ligne de la grille
 * @param[in] colonne : le nombre de colonne de la grille
 * @param[in] mineAutourCase : le nombre de mines entourant la case
 * @param[in] Mines : le conteneur de mines
 * @param[in-out] Grille : la grille de la partie
 * @param[in] historique : l'historique de coup
 * @pre idcase < grille.capacite
 */
void DemasqueCase(const unsigned int idcase, const unsigned int ligne, const unsigned int colonne, unsigned int mineAutourCase, Conteneur Mines, Grille grille, Historique historique);


/**
 * @brief Affiche la grille
 * param[in] grille : grille que l'on souhaite afficher
 * param[in] ligne : ligne de la grille
 * param[in] colonne : colonne de la grille
 */
void AfficherGrille(const Grille grille, const unsigned int ligne, const unsigned int colonne);

/** 
 * @brief Produit une grille de demineur à partir de paramètres
 * @param[in] le nombre de ligne
 * @param[in] le nombre de colonne
 * @param[in] le nombre de mines
 * @param[in] la position des mines
 * @param[in] le nombre de coups
 * @param[in] l'historique de coups
 */
void ProdGrilleCommande(Grille grille, const unsigned int ligne, const unsigned int colonne, const unsigned int nbMines, Conteneur Mines, const unsigned int nbCoups, const Historique historique, const bool affichage);


/**
 * @brief Produit une grille de demineur à partir de la lecture d'une grille
 * @param[in-out] la grille 
 * @param[in-out] le nombre de lignes
 * @param[in-out] le nombre de colonnes
 */
void ProdGrilleEntre(Grille& partie, const unsigned int& lignes, const unsigned int& colonnes);

#endif