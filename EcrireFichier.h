#pragma once

#include "IEcrireFichier.h"

class EcrireFichier : public IEcrireFichier
{
private:
    string path;
public:
    EcrireFichier(string);
    ~EcrireFichier();
    void ecrire(Grille) override;
};