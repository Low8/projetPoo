#include "Librairie.h"
#include "Regle.h"

class IRegle{
public:
    virtual int adjacent(int i, int j, vector<vector<Cellule>>& vecteurs) const = 0;
    virtual void genarationSuiv(vector<vector<Cellule>>& vecteurs) const = 0;
    virtual ~IRegle() = default;
};