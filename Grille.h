#pragma once

#include "IGrille.h"

class Grille : public IGrille
{
private:
    int nbLigne;
    int nbColonne;
    Regles* regle;
    vector<vector<ICellule*>> table;
public:
    Grille(int , int, Regles*);
    ~Grille();
    void iniGrille() override;
    void affiche() override;
    int getNbLigne() override;
    int getNbColonne() override;
    void SetNbColonne(int) override;
    void SetNbLigne(int) override;
    ICellule* getCellule(int,int) override;
    int adjacent(int, int) override;
    void generationSuiv() override;
};