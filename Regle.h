#include "Librairie.h"
#include "Cellule.h"
#include "IRegle.h"

class Regle : public IRegle {
public:
    int adjacent(int i, int j, vector<vector<Cellule>>& vecteurs) const override{
        int compt = 0;
        for (int k = i - 1; k <= i + 1; k++) {
            for (int q = j - 1; q <= j + 1; q++) {
                if (k >= 0 && k < 10 && q >= 0 && q < 10 && !(k == i && q == j)) {
                    if (vecteurs[k][q].estVivant()) {
                        compt++;
                    }
                }
            }
        }
        return compt;
    }
    
    void genarationSuiv(vector<vector<Cellule>>& vecteurs) override{
        vector<vector<Cellule>> temp(10, vector<Cellule>(10));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (vecteurs[i][j].estVivant()) {
                    if (adjacent(i, j, vecteurs) == 2 || adjacent(i, j, vecteurs) == 3) {
                        temp[i][j].setEtat(true);
                    } else {
                        temp[i][j].setEtat(false);
                    }
                } else {
                    if (adjacent(i, j, vecteurs) == 3) {
                        temp[i][j].setEtat(true);
                    } else {
                        temp[i][j].setEtat(false);
                    }
                }
            }
        }
        vecteurs = temp;
    }

    void affiche(vector<vector<Cellule>>& vecteurs)  override {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cout << (vecteurs[i][j].estVivant() ? 1 : 0) << "\t";
            }
            cout << endl;
        }
    }
};

//note : dans le main:
// IRegle* regle = new Regle(dehzhdeu)