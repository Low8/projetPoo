#pragma once

#include "Grille.h"

class ILireFichier
{
public:
    virtual ~ILireFichier() {};
    virtual IGrille* lire() = 0;
};