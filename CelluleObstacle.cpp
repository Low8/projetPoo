#include "CelluleObstacle.h"

CelluleObstacle::CelluleObstacle() : etat(false)
{
    
}

bool CelluleObstacle::estVivant()const{
    return false;
}

void CelluleObstacle::setEtat(bool etat) { 
    this->etat=etat;
}