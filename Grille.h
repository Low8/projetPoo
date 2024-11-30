#pragma once

#include "IGrille.h"

class Grille : public IGrille
{
private:
    int nbLigne;
    int nbColonne;
    ReglesClassiques regle;
public:
    vector<vector<Cellule>> table;
    Grille(int , int, ReglesClassiques);
    ~Grille();
    void iniGrille() override;
    void affiche() override;
    int getNbLigne() override;
    int getNbColonne() override;
    void SetNbColonne(int) override;
    void SetNbLigne(int) override;
    Cellule &getCellule(int,int) override;
    int adjacent(int, int) override;
    void generationSuiv() override;
};