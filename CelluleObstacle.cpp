#include "CelluleObstacle.h"

// Constructeur : initialise l'état à "mort" (false)
CelluleObstacle::CelluleObstacle() : etat(false)
{
    
}

// Destructeur : pas d'allocation à libérer
CelluleObstacle::~CelluleObstacle()
{
    
}

// Retourne toujours false (l'obstacle est toujours mort)
bool CelluleObstacle::estVivant() const {
    return false;
}

// L'état de l'obstacle ne peut pas être modifié, il reste toujours false
void CelluleObstacle::setEtat(bool etat) { 
    this->etat = false;
}
