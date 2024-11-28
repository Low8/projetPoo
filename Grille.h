#pragma once;

#include "IGrille.h"

class Grille : public IGrille
{
public:
    Grille(int , int, ReglesClassiques);
    ~Grille() override;
    void iniGrille() override;
    void affiche() override;
    int getNbLigne() override;
    int getNbColonne() override;
    void SetNbColonne(int) override;
    void SetNbLigne(int) override;
    Cellule getCellule(int,int) override;
    int adjacent(int, int) override;
    void genarationSuiv() override;
};

Grille::Grille(int ligne, int colonne, ReglesClassiques regle) : IGrille(ligne, colonne, regle)
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

int Grille::getNbLigne() {
    return nbLigne;
}

int Grille::getNbColonne() {
    return nbColonne;
}
void Grille::SetNbColonne(int nbLigne) {
    this->nbLigne = nbLigne;
}
void Grille::SetNbLigne(int nbColonne) {
    this->nbColonne = nbColonne;
}

Cellule Grille::getCellule(int x,int y) {
    return table[x][y];
}

int Grille :: adjacent(int i, int j) {
    int compt = 0;
    for (int k = i - 1; k <= i + 1; k++) {
        for (int q = j - 1; q <= j + 1; q++) {
            if (k >= 0 && k < nbLigne && q >= 0 && q < nbColonne && !(k == i && q == j)) {
                if (table[k][q].estVivant()) {
                    compt++;
                }
            }
        }
    }
    return compt;
}

void Grille :: genarationSuiv() {
    vector<vector<Cellule>> temp(nbLigne, vector<Cellule>(nbColonne));
    for (int i = 0; i < nbLigne; i++) {
        for (int j = 0; j < nbColonne; j++) {
            int nbAdjacent = adjacent(i, j);
            if (table[i][j].estVivant()) {
                temp[i][j].setEtat(regle.celluleSurvit(true, nbAdjacent));
            } else {
                temp[i][j].setEtat(regle.celluleNait(false, nbAdjacent));
            }
        }
    }
    table = temp;
}