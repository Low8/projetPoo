#include "CelluleObstacle.h"

CelluleObstacle::CelluleObstacle() : etat(false)
{
    
}

CelluleObstacle::~CelluleObstacle()
{
    
}

bool CelluleObstacle::estVivant()const{
    return false;
}

void CelluleObstacle::setEtat(bool etat) { 
    this->etat=false;
}