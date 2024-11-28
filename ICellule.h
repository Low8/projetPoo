#pragma once;

#include "Librairie.h"

class ICellule{
protected:
    bool etat;
public:
    ICellule();
    virtual ~ICellule();
    virtual bool estVivant() const = 0;
    virtual void setEtat(bool etat) = 0;
};

ICellule::ICellule() : etat(false)
{
    
}

ICellule::~ICellule()
{
}