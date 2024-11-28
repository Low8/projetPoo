#include "Librairie.h"
#include "Cellule.h"
#include "IGrille.h"

class Grille : public IGrille
{
private:
    vector<vector<Cellule>> table;
    int nbLigne;
    int nbColonne;
public:
    Grille(int ligne, int colonne);
    ~Grille();
    void iniGrille() override;
    void affiche() override;
    int getNbLigne() const override;
    int getNbColonne() const override;
    void SetNbColonne(int)override;
    void SetNbLigne(int)override;
    Cellule getCellule(int x,int y) const override;
};

Grille::Grille(int ligne, int colonne) : nbLigne(ligne), nbColonne(colonne)
{
    iniGrille();
}

Grille::~Grille()
{
}

void Grille::iniGrille()  {
    table = vector<vector<Cellule>>(nbLigne, vector<Cellule>(nbColonne));
}

void Grille::affiche() {
    for (int i = 0; i<nbColonne; i++){
        for(int j = 0; j<nbLigne; j++){
            cout << (table[i][j].estVivant() ? 'O' : '.') << ' ';
        }
        cout << endl;
    }
}

int Grille::getNbLigne() const {
    return nbLigne;
}

int Grille::getNbColonne() const {
    return nbColonne;
}
void Grille::SetNbColonne(int nbLigne) {
    this->nbLigne = nbLigne;
}
void Grille::SetNbLigne(int nbColonne) {
    this->nbColonne = nbColonne;
}

Cellule Grille::getCellule(int x,int y) const {
    return table[x][y];
}

int Grille :: adjacent(int i, int j, vector<vector<Cellule>>& vecteurs) {
        int compt = 0;
        for (int k = i - 1; k <= i + 1; k++) {
            for (int q = j - 1; q <= j + 1; q++) {
                if (k >= 0 && k < nbLigne && q >= 0 && q < nbColonne && !(k == i && q == j)) {
                    if (vecteurs[k][q].estVivant()) {
                        compt++;
                    }
                }
            }
        }
        return compt;
    }
    
    void Grille :: genarationSuiv(vector<vector<Cellule>>& vecteurs) {
        vector<vector<Cellule>> temp(nbLigne, vector<Cellule>(nbColonne));
        for (int i = 0; i < nbLigne; i++) {
            for (int j = 0; j < nbColonne; j++) {
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