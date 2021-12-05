/**
 * @file ConteneurTD.cpp
 * Projet sem03-tp-Cpp1
 * @author l'�quipe p�dagogique
 * @version 2 18/11/11
 * @brief corrige du TD n�3 sur machine - Exercice 1
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */

#include <iostream>
#include <cassert>
using namespace std;



/**
 * @brief Type date
 * invariant : la date doit �tre valide
*/
struct Date {
	unsigned short jour, mois, annee;
};

/**
 * @brief Saisie d'une date valide
 * @return la date saisie
 */
Date saisir() {
	Date d;
	cout << "Date (jour? mois? annee?) ? ";
	cin >> d.jour >> d.mois >> d.annee;
	return d;
}

/**
 * @brief Affiche une date */
void afficher(const Date& d) {
	cout << d.jour << '/' << d.mois << '/' << d.annee << "  ";
}

// Sp�cialisation du type Item (l'item est sp�cialis� ici en date)
typedef Date Item;

/** @brief Type du conteneur d'items
 *  allou� en m�moire dynamique et de capacit� fix�e
 */
struct ConteneurTD {
	unsigned int capacite; 	// capacit� du conteneur (>0)
	Item* tab;	// support du conteneur, un tableau allou� en m�moire dynamique de taille fix�e (capacite) 
};

void initialiser(ConteneurTD& c, unsigned int capa);
void detruire(ConteneurTD& c);
Item lire(const ConteneurTD& c, unsigned int i);
void ecrire(ConteneurTD& c, unsigned int i, const Item& it);

/**
 * @brief Initialise un conteneur d'items vide
 * Allocation en m�moire dynamique du conteneur d'items de capacit� capa
 * @see detruire, pour sa d�sallocation en fin d'utilisation
 * @param[out] c : le conteneur d'items
 * @param [in] capa : la capacit� du conteneur
 * @pre capa>0
 */
void initialiser(ConteneurTD& c, unsigned int capa) {
	/* V�rifiez la pr�condition*/
	assert(capa > 0);
		/* L'objectif est d'initialiser tous les attributs du conteneur c
		 * de telle sorte que le conteneur soit vide
		 * Dans notre cas, le support est un tableau de taille (c.capacite), qui est � initialiser */
		c.capacite = capa;
		/* De plus, le tableau (c.tab) est allou� en m�moire dynamique.
		 * Pr�parez le conteneur � stocker des items : allouez le tableau en m�moire dynamique */
		c.tab = new Item[capa];
		/* Pour tracer l'allocation en m�moire,
		 * affichez l'allocation faite en nombre d'octets.
		 * Attention : Ne jamais faire d'affichage dans une fonction
		 * dont ce n'est pas le r�le explicite.
		 * Cet affichage sera supprim� lorsque le conteneur sera test�*/
		cout << sizeof(c.tab);
}

/**
 * @brief D�salloue un conteneur d'items en m�moire dynamique
 * @see initialiser, le conteneur d'items a d�j� �t� allou�
 * @param[out] c : le conteneur d'items
 */
void detruire(ConteneurTD& c) {
	delete [] c.tab;
	c.tab = NULL;
	c.capacite = 0;
}

/**
 * @brief Lecture d'un item d'un conteneur d'items
 * @param[in] c : le conteneur d'items
 * @param[in] i : la position de l'item dans le conteneur
 * @return l'item � la position i
 * @pre i < c.capacite
 */
Item lire(const ConteneurTD& c, unsigned int i) {
	/* V�rifiez la pr�condition
	 * et retournez l'item � la position i dans le conteneur c */
	assert(i < c.capacite);
	return c.tab[i];
}

/**
 * @brief Ecrire un item dans un conteneur d'items
 * @param[out] c : le conteneur d'items
 * @param[in] i : la position o� ajouter/modifier l'item
 * @param[in] item : l'item � �crire
 * @pre i < c.capacite
 */
void ecrire(ConteneurTD& c, unsigned int i, const Item& it) {
	assert(i < c.capacite);
	c.tab[i] = it;
}

/* Test d'un conteneur de dates */
int main(int argc, char* argv[]) {

	ConteneurTD cDates; // D�claration du conteneur de dates test�
	unsigned int nbDates; // Nombre de dates � enregistrer dans le conteneur
	Date d;

	/* Lire le nombre de dates (nbDates) � enregistrer dans le conteneur */
	cout << "Entrez le nombre de nombre de dates que vous souhaitez" << endl;
	cin >> nbDates;

		/* Initialiser un conteneur (vide) de dates de capacit� nbDates */
	initialiser(cDates, nbDates);

		/* Remplir le conteneur de nbDates dates */
	cout << "Saisie de " << nbDates << " dates � enregistrer dans le conteneur :"
	<< endl;
	for (int i = 0; i < nbDates; i++) {
		cout << "Rentrez la " << i+1 << "eme date :" << endl;
		cDates.tab[i] = saisir();
	}
	

		/* Afficher le conteneur de dates */
	cout << "Conteneur des dates, de capacit� " << cDates.capacite
	<< ", allou� en m�moire dynamique :" << endl;
	for (int i = 0; i < nbDates; i++) {
		afficher(cDates.tab[i]);
	}
		/* D�sallouer le conteneur de dates */
	detruire(cDates);

	return 0;
}

