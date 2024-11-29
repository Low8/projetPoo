#include "LireFichier.h"

LireFichier::LireFichier(string path) : path(path) 
{
}

LireFichier::~LireFichier()
{
}

Grille LireFichier::lire() // Définition de la méthode
{
    ifstream f_in(path);
    if (!f_in.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier en lecture : " << path << endl;
    }

    int nbLigne = 0, nbColonne = 0;
    f_in >> nbLigne >> nbColonne;

    if (nbLigne <= 0 || nbColonne <= 0) {
        cerr << "Erreur : dimensions invalides dans le fichier." << endl;
    }
    ReglesClassiques regle;
    Grille grille(nbLigne, nbColonne, regle);

    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            int etat;
            if (!(f_in >> etat) || (etat != 0 && etat != 1)) {
                cerr << "Erreur : données manquantes ou invalides dans le fichier." << endl;
            }
            grille.getCellule(i, j).setEtat(etat);
        }
    }

    f_in.close();

    return grille;
}