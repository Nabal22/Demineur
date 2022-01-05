/**
 * @file main.cpp
 * Projet SDA
 * @author Regenwetter Simon et Talagrand Alban
 * @version 8 05/01/2021
 * @brief Projet SDA démineur
 * Structures de donn�es et algorithmes - BUT 1 Paris 16
 */

#include <iostream>
#include "EtatPartie.h"
#include "ProdCoup.h"

using namespace std;

int main (){
    unsigned int commande;

    cin >> commande;
    switch (commande) {
        unsigned int i, lignes, colonnes, nbMines, tempMine, nbCoups, tempCoup;
        char type;
        Historique historique;
        Conteneur Mines;
        Grille coupType;
        Grille coupEmplacement;
        Grille partie;
        case 1 :
            cin >> lignes >> colonnes >> nbMines;
            Create(lignes,colonnes,nbMines);
            break;
        case 2 :
            cin >> lignes >> colonnes >> nbMines;
            
            initialiser(Mines, nbMines);
            for (i = 0; i < nbMines; i++) {
                cin >> tempMine;
                ecrire(Mines, i, tempMine);
            }
            cin >> nbCoups;
            initGrille(coupType, nbCoups);
            initGrille(coupEmplacement, nbCoups);
            for(i = 0; i < nbCoups; i++) {
                cin >> type >> tempCoup;
                ecrireGrille(coupType, i, type);
                ecrireGrille(coupEmplacement, i, tempCoup);
            }
            historique.type = &coupType;
            historique.position = &coupEmplacement;
            initGrille(partie, colonnes * lignes);
            ProdGrilleCommande(partie,lignes, colonnes, nbMines, Mines, nbCoups, historique , true);
            break;
        case 3 :
            cin >> lignes >> colonnes >> nbMines;
            initialiser(Mines, nbMines);
            for (i = 0; i < nbMines; i++) {
                cin >> tempMine;
                ecrire(Mines, i, tempMine);
            }
            cin >> nbCoups;
            initGrille(coupType, nbCoups);
            initGrille(coupEmplacement, nbCoups);
            for (i = 0; i < nbCoups; i++) {
                cin >> type >> tempCoup;
                ecrireGrille(coupType, i, type);
                ecrireGrille(coupEmplacement, i, tempCoup);
            }
            historique.type = &coupType;
            historique.position = &coupEmplacement;
            initGrille(partie, colonnes * lignes);
            ProdGrilleCommande(partie, lignes, colonnes, nbMines, Mines, nbCoups, historique, false);
            if (estGagne(partie, Mines)){
                cout << "game won";
            }
            else {
                cout << "game not won";
            }
            break;
        case 4 :
            cin >> lignes >> colonnes >> nbMines;
            initialiser(Mines, nbMines);
            for (i = 0; i < nbMines; i++) {
                cin >> tempMine;
                ecrire(Mines, i, tempMine);
            }
            cin >> nbCoups;
            initGrille(coupType, nbCoups);
            initGrille(coupEmplacement, nbCoups);
            for (i = 0; i < nbCoups; i++) {
                cin >> type >> tempCoup;
                ecrireGrille(coupType, i, type);
                ecrireGrille(coupEmplacement, i, tempCoup);
            }
            historique.type = &coupType;
            historique.position = &coupEmplacement;
            initGrille(partie, colonnes * lignes);
            ProdGrilleCommande(partie, lignes, colonnes, nbMines, Mines, nbCoups, historique, false);
            if (estPerdu(partie,Mines)) {
                cout << "game lost";
            }
            else {
                cout << "game not lost";
            }
            break;
        case 5 :
            cin >> lignes >> colonnes;
            initGrille(partie, (lignes * colonnes));
            ProdGrilleEntre(partie, lignes, colonnes);
            prodCoup(partie, colonnes, lignes);
            break;
        default: cout << "erreur";
    }
    return 0;
}