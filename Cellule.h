#pragma once

#include "ICellule.h"

class Cellule : public ICellule
{
public:
    Cellule();
    ~Cellule() override;
    bool estVivant() const override;
    void setEtat(bool etat) override ;
};

Cellule::Cellule() : ICellule()
{

}

Cellule::~Cellule()
{

}

bool Cellule::estVivant() const {
    return etat;
}

void Cellule::setEtat(bool etat) {
    this->etat = etat;
}
