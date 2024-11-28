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