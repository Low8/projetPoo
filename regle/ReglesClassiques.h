#pragma once

#include "Regles.h"

class ReglesClassiques : public Regles
{
public:
    bool celluleSurvit(bool, int) const override;
    bool celluleNait(bool, int) const override;
};