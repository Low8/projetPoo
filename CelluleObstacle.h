
#include "Cellule.h"

class CelluleObstacle : public Cellule{
    CelluleObstacle();
    ~CelluleObstacle();
    bool estVivant() const override;
    // void setEtat(bool etat) override ;
};


// dans le cpp

CelluleObstacle::CelluleObstacle() : Cellule(){}

CelluleObstacle::~CelluleObstacle(){}

bool CelluleObstacle::estVivant()const{
    return false;
}

// void CelluleObstacle::setEtat(bool etat){} //deja def dans cellule, pas besoin de récrire la même chose
