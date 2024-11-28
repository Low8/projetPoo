#include "Librairie.h"

class Cellule
{
private:
    bool etat;
public:
    Cellule();
    ~Cellule();
    bool estVivant();
    void setEtat(bool etat);
};

Cellule::Cellule()
{
    etat = false;
}

Cellule::~Cellule()
{
}

bool Cellule::estVivant() {
    return etat;
}

void Cellule::setEtat(bool etat) {
    this->etat = etat;
}
