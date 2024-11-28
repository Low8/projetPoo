#pragma once;

#include "Regles.h"

class ReglesClassiques : public Regles
{
public:
    bool celluleSurvit(bool, int) const override;

    bool celluleNait(bool, int) const override;
};

bool ReglesClassiques::celluleSurvit(bool celluleActuelle, int nbAdjacent) const {
    return celluleActuelle && (nbAdjacent == 2 || nbAdjacent == 3);
}

bool ReglesClassiques::celluleNait(bool celluleActuelle, int nbAdjacent) const {
    return !nbAdjacent && nbAdjacent == 3;
}