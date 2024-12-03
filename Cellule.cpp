#include "Cellule.h"

Cellule::Cellule() : etat(false)
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