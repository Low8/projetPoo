#include "Cellule.h"

class Grille
{
private:
    vector<vector<Cellule>> table;
    int nbLigne;
    int nbColonne;
public:
    Grille(int ligne, int colonne);
    ~Grille();
    void iniGrille();
    void affiche();
};

Grille::Grille(int ligne, int colonne) : nbLigne(ligne), nbColonne(colonne)
{
    iniGrille();
}

Grille::~Grille()
{
}

void Grille::iniGrille() {
    table = vector<vector<Cellule>>(nbLigne, vector<Cellule>(nbColonne));
}

void Grille::affiche() {
    for (int i = 0; i<nbColonne; i++){
        for(int j = 0; j<nbLigne; j++){
            cout << table[i][j].estVivant() << "\t";
        }
        cout << endl;
    }
}