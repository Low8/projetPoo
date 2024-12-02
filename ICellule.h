#pragma once

#include "Librairie.h"

class ICellule{
public:
    virtual ~ICellule() {};
    virtual bool estVivant() const = 0;
    virtual void setEtat(bool) = 0;
};