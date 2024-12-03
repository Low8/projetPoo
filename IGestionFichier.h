#pragma once

#include "Grille.h"

class IGestionFichier
{
public:
    virtual ~IGestionFichier() {};
    virtual IGrille* lire() = 0;
    virtual void ecrire(IGrille*) = 0;
    virtual string getPath() = 0;
    virtual void setPath(string) = 0;
};