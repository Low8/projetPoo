#include "LireFichier.h"

LireFichier::LireFichier(string path) : path(path) 
{
}

LireFichier::~LireFichier()
{
}

IGrille* LireFichier::lire() // Définition de la méthode
{
    ifstream f_in;
    f_in.open(path);
    if (!f_in.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier en lecture : " << path << endl;
        exit(EXIT_FAILURE);
    }
    int nbLigne = 0, nbColonne = 0;
    f_in >> nbLigne >> nbColonne;

    if (nbLigne <= 0 || nbColonne <= 0) {
        cerr << "Erreur : dimensions invalides dans le fichier." << endl;
        exit(EXIT_FAILURE);
    }
    Regles* regle = new ReglesClassiques;
    IGrille* grille = new Grille(nbLigne, nbColonne, regle);
    int etat;
    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            if (!(f_in >> etat) || (etat != 0 && etat != 1)) {
                cerr << "Erreur : données manquantes, en trop ou invalides dans le fichier." << endl;
                exit(EXIT_FAILURE);
            }
            grille->getCellule(i, j)->setEtat(etat);
        }
    }
    if (f_in >> etat)
    {
        cerr << "Erreur : données manquantes, en trop ou invalides dans le fichier." << endl;
        exit(EXIT_FAILURE);
    }
    
    f_in.close();
    return grille;
}