#include "Librairie.h"
#include "ICellule.h"

class Cellule : public ICellule
{
private:
    bool etat;
public:
    Cellule();
    ~Cellule();
    bool estVivant() const override;
    void setEtat(bool etat) override ;
};

Cellule::Cellule()
{
    etat = false;
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
