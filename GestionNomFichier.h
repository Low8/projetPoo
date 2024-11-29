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