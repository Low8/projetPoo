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
    int getNbLigne();
    int getNbColonne();
    void SetNbColonne(int);
    void SetNbLigne(int);
    Cellule getCellule(int x,int y);
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