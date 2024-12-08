#include "Cellule.h"

// Constructeur : initialise l'état de la cellule à "vivant" (true)
Cellule::Cellule() : etat(true)
{

}

// Destructeur : pas d'allocation à libérer
Cellule::~Cellule()
{

}

// Retourne l'état de la cellule (vivant ou mort)
bool Cellule::estVivant() const {
    return etat;
}

// Modifie l'état de la cellule
void Cellule::setEtat(bool etat) {
    this->etat = etat;
}
