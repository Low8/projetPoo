#pragma once

#include "Cellule.h"
#include "ReglesClassiques.h"


class IGrille{
protected:
    virtual void iniGrille() = 0;
public:
    virtual ~IGrille() {};
    virtual void affiche() = 0;
    virtual int adjacent(int, int) = 0;
    virtual void remplirAleatoire() = 0;
    virtual void remplirVide() = 0;
    virtual int getNbLigne() = 0;
    virtual int getNbColonne() = 0;
    virtual vector<vector<ICellule*>> getGrille() = 0;
    virtual void SetNbColonne(int) = 0;
    virtual void SetNbLigne(int) = 0;
    virtual ICellule* getCellule(int,int) = 0;
    virtual void generationSuiv() = 0;
    virtual void setCelluleO(int, int) = 0;
};