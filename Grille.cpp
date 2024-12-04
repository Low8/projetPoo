#include "Grille.h"

Grille::Grille(int nbligne, int nbcolonne, Regles* regle) : nbLigne(nbligne), nbColonne(nbcolonne), regle(regle)
{  
    iniGrille();
    //table[5][5]->setEtat(true);
}


Grille::~Grille() {
    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            delete table[i][j];
        }
    }
}

void Grille::iniGrille() {
    table = vector<vector<ICellule*>>(nbLigne, vector<ICellule*>(nbColonne));
    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            table[i][j] = new Cellule();
        }
    }
}


void Grille::affiche() {
    for (int i = 0; i<nbLigne; i++){
        for(int j = 0; j<nbColonne; j++){
            cout << (table[i][j]->estVivant() ? 'O' : '.') << ' ';
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

ICellule* Grille::getCellule(int x,int y) {
    return table[x][y];
}

void Grille::setCelluleO(int x, int y) {
    
    if (table[x][y]->estObstacle())
    {
        delete table[x][y];
        table[x][y] = new Cellule;
    } else
    {
        delete table[x][y];
        table[x][y] = new CelluleObstacle;
    }
}

int Grille :: adjacent(int i, int j) {
    int n = regle->getNbAdjacent();
    int compt = 0;
    for (int k = i - n; k <= i + n; k++) {
        for (int q = j - n; q <= j + n; q++) {
            if (k >= 0 && k < nbLigne && q >= 0 && q < nbColonne && !(k == i && q == j)) {
                if (table[k][q]->estVivant()) {
                    compt++;
                }
            }
        }
    }
    return compt;
}

void Grille :: generationSuiv() {
    vector<vector<ICellule*>> temp(nbLigne, vector<ICellule*>(nbColonne));
    for (int i = 0; i < nbLigne; i++) {
        for (int j = 0; j < nbColonne; j++) {
            temp[i][j] = new Cellule();
        }
    }
    for (int i = 0; i < nbLigne; i++) {
        for (int j = 0; j < nbColonne; j++) {
            int nbAdjacent = adjacent(i, j);
            if (!table[i][j]->estObstacle())
            {
                if (table[i][j]->estVivant()) {
                    temp[i][j]->setEtat(regle->celluleSurvit(true, nbAdjacent));
                } else {
                    temp[i][j]->setEtat(regle->celluleNait(false, nbAdjacent));
                }
            } else
            {
                delete table[i][j];
                table[i][j] = new CelluleObstacle;
            }
            
        }
    }

    table = temp;
}