#include "ICellule.h"

class CelluleObstacle : public ICellule{
private:
    bool etat;
public:
    CelluleObstacle();
    ~CelluleObstacle();
    bool estVivant() const override;
    void setEtat(bool) override ;
};