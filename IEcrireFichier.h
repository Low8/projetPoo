#pragma once

#include "Grille.h"

class IEcrireFichier
{
public:
    virtual ~IEcrireFichier() {};
    virtual void ecrire(IGrille*) = 0; 
};