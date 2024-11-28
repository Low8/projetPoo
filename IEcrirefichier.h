#pragma once;

#include "Grille.h"

class IEcrirefichier
{
protected:
    string path;
public:
    IEcrirefichier(string);
    ~IEcrirefichier();
    virtual void ecrire(Grille); 
};

IEcrirefichier::IEcrirefichier(string path) : path(path)
{
}

IEcrirefichier::~IEcrirefichier()
{
}
