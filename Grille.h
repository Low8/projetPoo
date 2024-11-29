#pragma once

#include "IGrille.h"

class Grille : public IGrille
{
private:
    vector<vector<Cellule>> table;
    int nbLigne;
    int nbColonne;
    ReglesClassiques regle;
public:
    Grille(int , int, ReglesClassiques);
    ~Grille() override;
    void iniGrille() override;
    void affiche() override;
    int getNbLigne() override;
    int getNbColonne() override;
    void SetNbColonne(int) override;
    void SetNbLigne(int) override;
    Cellule getCellule(int,int) override;
    int adjacent(int, int) override;
    void genarationSuiv() override;
};