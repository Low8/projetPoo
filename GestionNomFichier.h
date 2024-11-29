#pragma once

#include <Librairie.h>

class GestionNomFichier
{
private:
    int compteur;
    std::string pathBase;
    bool premiereGeneration;

public:
    GestionNomFichier(const string& path);
    
    string genererNomFichier();
};

GestionNomFichier::GestionNomFichier(const string& path) : pathBase(path), compteur(1), premiereGeneration(true)
{

}

string GestionNomFichier:: genererNomFichier() {
    stringstream nomFichier;
    
    if (premiereGeneration) {
        nomFichier << pathBase << "_out.txt";
        premiereGeneration = false; 
    } else {
        nomFichier << pathBase << "_out_" << compteur << ".txt";
        compteur++;
    }
    return nomFichier.str();
}
