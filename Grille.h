#include "Librairie.h"

class Grille
{
private:
    vector<vector<int>> table;
    int nbLigne;
    int nbColonne;
public:
    Grille(int ligne, int colonne);
    ~Grille();
    void affiche();
};

Grille::Grille(int ligne, int colonne) : nbLigne(ligne), nbColonne(colonne)
{
    table = vector<vector<int>>(nbLigne, vector<int>(nbColonne, 0));
}

Grille::~Grille()
{
}

void Grille::affiche() {
    for (int i = 0; i<nbColonne; i++){
        for(int j = 0; j<nbLigne; j++){
            cout<<table[i][j]<< "\t";
        }
        std::cout << endl;
    }
}