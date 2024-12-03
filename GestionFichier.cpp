#include "GestionFichier.h"

GestionFichier::GestionFichier(string path) : path(path) {

}

GestionFichier::~GestionFichier() {

}


IGrille* GestionFichier::lire() {
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

void GestionFichier::ecrire(IGrille* grille) {
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

string GestionFichier::getPath() {
    return path;
}


void GestionFichier::setPath(string path) {
    this->path = path;
}