#include "Librairie.h"
#include "Cellule.h"

class ICellule{
public:
    virtual bool estVivant() const = 0;
    virtual void setEtat(bool etat) const = 0;

    virtual ~ICellule() = default;
};