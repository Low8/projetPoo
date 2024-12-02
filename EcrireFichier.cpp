#include "EcrireFichier.h"

EcrireFichier::EcrireFichier(string path) : path(path)
{
}

EcrireFichier::~EcrireFichier()
{
}

void EcrireFichier::ecrire(IGrille* grille) {
    ofstream f_out;
    f_out.open(path, ofstream::out);
    if (!f_out.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier en écriture : " << path << endl;
        exit(EXIT_FAILURE);
    }
    f_out << grille->getNbLigne() << " " << grille->getNbColonne() << endl;
    for (int i = 0; i < grille->getNbLigne(); i++) {
        for (int j = 0; j < grille->getNbColonne(); j++) {
            f_out << (grille->getCellule(i, j)->estVivant() ? 1 : 0) << ' ';
        }
        f_out << endl;
    }
    f_out.close(); 
}