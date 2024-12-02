#pragma once

#include "ICellule.h"

class Cellule : public ICellule
{
private:
    bool etat;
public:
    Cellule();
    ~Cellule() override;
    bool estVivant() const override;
    void setEtat(bool etat) override;
};