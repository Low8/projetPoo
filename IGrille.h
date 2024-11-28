#include "Librairie.h"
#include "Grille.h"

class IGrille{
public:
    virtual void iniGrille() const = 0;
    virtual void affiche() const = 0;
    virtual int getNbLigne() const = 0;
    virtual int getNbColonne() const = 0;
    virtual void SetNbColonne(int) const = 0;
    virtual void SetNbLigne(int) const = 0;
    virtual Cellule getCellule(int x,int y) const = 0;
    virtual int adjacent(int i, int j, vector<vector<Cellule>>& vecteurs) const = 0;
    virtual void genarationSuiv(vector<vector<Cellule>>& vecteurs) const = 0;

    virtual ~ICellule() = default;
};
