#pragma once

#include "Grille.h"

class ILireFichier
{
public:
    virtual ~ILireFichier();
    virtual Grille lire() = 0;
};