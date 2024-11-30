#include "GestionNomFichier.h"

GestionNomFichier::GestionNomFichier(const string& path) : pathBase(path), compteur(1), premiereGeneration(true)
{
}

string GestionNomFichier:: genererNomFichier() {
    stringstream nomFichier;
    
    if (premiereGeneration) {
        nomFichier << "generation/" << pathBase << "_out.txt";
        premiereGeneration = false; 
    } else {
        nomFichier << "generation/" << pathBase << "_out_" << compteur << ".txt";
        compteur++;
    }
    return nomFichier.str();
}