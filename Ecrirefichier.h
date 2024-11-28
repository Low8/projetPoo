#pragma once;

#include "IEcrirefichier.h"

class Ecrirefichier : public IEcrirefichier
{
public:
    Ecrirefichier(string);
    ~Ecrirefichier();
    void ecrire(Grille) override;
};

Ecrirefichier::Ecrirefichier(string path) : IEcrirefichier(path)
{
}

Ecrirefichier::~Ecrirefichier()
{
}

void Ecrirefichier::ecrire(Grille grille) {
    ofstream f_out;
    f_out.open(path, ofstream::out);
    if (!f_out.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier en écriture : " << path << endl;
        return;
    }
    f_out << grille.getNbLigne() << " " << grille.getNbColonne() << endl;
    for (int y = 0; y < grille.getNbLigne(); y++) {
        for (int x = 0; x < grille.getNbColonne(); x++) {
            f_out << (grille.getCellule(x, y).estVivant() ? 1 : 0) << ' ';
        }
        f_out << endl;
    }
    f_out.close(); 
}