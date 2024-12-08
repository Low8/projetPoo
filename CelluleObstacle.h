#include "ICellule.h"

class CelluleObstacle : public ICellule{
private:
    bool etat;
public:
    CelluleObstacle();
    ~CelluleObstacle();
    bool estVivant() const override; // getteur
    void setEtat(bool) override;
    bool estObstacle() const override {return true;} // pour savoir que la cellule est obstacle obstacle
};