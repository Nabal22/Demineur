/**
 * @file main.cpp
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 1 27/11/2021
 * @brief Projet SDA démineur - Exercice 1
 * Structures de donn�es et algorithmes - BUT 1 Paris 16
 * Changement test
 */

#include <iostream>
#include "probleme.h"
#include "ProdGrille.h"
#include "tableau.h"
#include "historique.h"

using namespace std;
 /**
  * @brief
 */
    struct Coup {
    unsigned short type, position;
};


int main (){
    unsigned int commande;

    cin >> commande;
    switch (commande) {
        unsigned int i, lignes, colonnes, nbMines, tempMine, nbCoups, tempCoup;
        char type;

        case 1 :
            cin >> lignes >> colonnes >> nbMines;
            Create(lignes,colonnes,nbMines);
            break;
        case 2 :
            cin >> lignes >> colonnes >> nbMines;
            Historique historique;
            Conteneur Mines;
            Conteneur coupType;
            Conteneur coupEmplacement;
            initialiser(Mines, nbMines);
            for (i = 0; i < nbMines; i++) {
                cin >> tempMine;
                ecrire(Mines, i, tempMine);
            }
            cin >> nbCoups;
            for(i = 0; i < nbCoups; i++) {
                cin >> type >> tempCoup;
                cout << "type :" << type << "coup :" << tempCoup << endl;
                ecrire(coupType, i, type);
                ecrire(coupEmplacement, i, tempCoup);
            }
            historique.type = coupType;
            historique.position = coupEmplacement;
            ProdGrille(lignes, colonnes, nbMines, Mines, nbCoups, historique);
            break;
        //case 3 :
        //case 4 :
        //case 5 :
        default: cout << "erreur";
    }
    return 0;
}
