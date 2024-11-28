#pragma once;

#include "Librairie.h"

class Regles
{
public:
    ~Regles() = default;
    virtual bool celluleSurvit(bool, int) const = 0;
    virtual bool celluleNait(bool, int) const = 0;
};


Regles::~Regles()
{
}