#include "Cellule.h"

Cellule::Cellule() : etat(true)
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