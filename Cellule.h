#pragma once

#include "ICellule.h"

class Cellule : public ICellule
{
private:
    bool etat;
public:
    Cellule();
    ~Cellule() override;
    bool estVivant() const override;    // getteur
    void setEtat(bool etat) override;
    bool estObstacle() const override {return false;} // pour savoir que la cellule est pas obstacle obstacle
};