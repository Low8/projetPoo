#pragma once

#include "Regles.h"

class ReglesClassiques : public Regles
{
private:
    int nbAdjacent;
public:
    ReglesClassiques();
    ~ReglesClassiques();
    bool celluleSurvit(bool, int) const override;
    bool celluleNait(bool, int) const override;
    int getNbAdjacent() override;
};