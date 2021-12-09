#pragma once
#ifndef _TABLEAU_
#define _TABLEAU_


/** @brief Type du conteneur d'items
 *  alloue en memoire dynamique et de capacite fixee
 */
struct Conteneur {
	unsigned int capacite; 	// capacite du conteneur (>0)
	unsigned int* tab;	// support du conteneur, un tableau alloue en memoire dynamique de taille fixee (capacite) 
};

/**
 * @brief Initialise un conteneur d'items vide
 * Allocation en memoire dynamique du conteneur d'items de capacite capa
 * @see detruire, pour sa desallocation en fin d'utilisation
 * @param[out] c : le conteneur d'items
 * @param [in] capa : la capacite du conteneur
 * @pre capa>0
 */
void initialiser(Conteneur& c, unsigned int capa);

/**
 * @brief Desalloue un conteneur d'items en memoire dynamique
 * @see initialiser, le conteneur d'items a deje ete alloue
 * @param[out] c : le conteneur d'items
 */
void detruire(Conteneur& c);

/**
 * @brief Lecture d'un item d'un conteneur d'items
 * @param[in] c : le conteneur d'items
 * @param[in] i : la position de l'item dans le conteneur
 * @return l'item e la position i
 * @pre i < c.capacite
 */
unsigned int lire(const Conteneur& c, unsigned int i);

/**
 * @brief Ecrire un item dans un conteneur d'items
 * @param[out] c : le conteneur d'items
 * @param[in] i : la position oe ajouter/modifier l'item
 * @param[in] item : l'item e ecrire
 * @pre i < c.capacite
 */
void ecrire(Conteneur& c, unsigned int i, const unsigned int& it);

#endif