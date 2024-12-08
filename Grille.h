#pragma once

#include "IGrille.h"
#include "CelluleObstacle.h"

class Grille : public IGrille
{
private:
    int nbLigne;
    int nbColonne;
    Regles* regle;
    vector<vector<ICellule*>> table;
    void iniGrille() override;
public:
    Grille(int , int, Regles*);
    ~Grille();
    void affiche() override;
    int adjacent(int, int) override;
    void remplirAleatoire() override;
    void remplirVide() override;
    int getNbLigne() override;
    int getNbColonne() override;
    vector<vector<ICellule*>> getGrille() override;
    void SetNbColonne(int) override;
    void SetNbLigne(int) override;
    ICellule* getCellule(int,int) override;
    void generationSuiv() override;
    void setCelluleO(int, int) override;
};