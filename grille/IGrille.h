#pragma once

#include "Cellule.h"
#include "ReglesClassiques.h"


class IGrille{
public:
    virtual ~IGrille();
    virtual void iniGrille() = 0;
    virtual void affiche() = 0;
    virtual int getNbLigne() = 0;
    virtual int getNbColonne() = 0;
    virtual void SetNbColonne(int) = 0;
    virtual void SetNbLigne(int) = 0;
    virtual Cellule getCellule(int,int) = 0;
    virtual int adjacent(int, int) = 0;
    virtual void genarationSuiv() = 0;
};