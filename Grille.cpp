#include "Grille.h"

// Constructeur de la grille : initialise le nombre de lignes, de colonnes, et les règles
// Puis appelle la fonction d'initialisation de la grille.
Grille::Grille(int nbligne, int nbcolonne, Regles* regle) : nbLigne(nbligne), nbColonne(nbcolonne), regle(regle)
{  
    iniGrille();
}

// Destructeur de la grille : libère la mémoire allouée pour chaque cellule
Grille::~Grille() {
    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            delete table[i][j];
        }
    }
}

// Initialisation de la grille : alloue un tableau de cellules (ICellule) pour chaque position
void Grille::iniGrille() {
    table = vector<vector<ICellule*>>(nbLigne, vector<ICellule*>(nbColonne));
    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            table[i][j] = new Cellule();  // Crée une cellule vide par défaut
        }
    }
}

// Remplissage de la grille de manière aléatoire
// L'état de chaque cellule est soit 'vivant' (O) soit 'mort' (.)
void Grille::remplirAleatoire() {
    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            // Si la somme des indices i+j est paire et un nombre aléatoire entre 0 et 1 est 0
            bool etat = ((i + j) % 2 == 0) && (std::rand() % 2 == 0);
            table[i][j]->setEtat(etat);  // Définir l'état de la cellule
        }
    }
}

// Remplissage de la grille avec des cellules mortes (toutes les cellules sont 'mortes')
void Grille::remplirVide() {
    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            table[i][j]->setEtat(false);  // Toutes les cellules sont mortes
        }
    }
}

// Affichage de la grille à la console
// Les cellules vivantes sont affichées par 'O' et les cellules mortes par '.'
void Grille::affiche() {
    for (int i = 0; i < nbLigne; i++) {
        for (int j = 0; j < nbColonne; j++) {
            cout << (table[i][j]->estVivant() ? 'O' : '.') << ' ';
        }
        cout << endl;
    }
}

// Retourne le nombre de lignes de la grille
int Grille::getNbLigne() {
    return nbLigne;
}

// Retourne le nombre de colonnes de la grille
int Grille::getNbColonne() {
    return nbColonne;
}

// Retourne la grille sous forme de tableau 2D de cellules
vector<vector<ICellule*>> Grille::getGrille() {
    return table;
}

// Définir le nombre de colonnes (sans rapport direct avec le nombre de lignes)
void Grille::SetNbColonne(int nbLigne) {
    this->nbLigne = nbLigne;
}

// Définir le nombre de lignes (sans rapport direct avec le nombre de colonnes)
void Grille::SetNbLigne(int nbColonne) {
    this->nbColonne = nbColonne;
}

// Retourne la cellule à la position (x, y)
ICellule* Grille::getCellule(int x, int y) {
    return table[x][y];
}

// Modifie une cellule pour en faire un obstacle ou une cellule normale
void Grille::setCelluleO(int x, int y) {
    // Si la cellule est déjà un obstacle, on la remplace par une cellule normale
    if (table[x][y]->estObstacle()) {
        delete table[x][y];
        table[x][y] = new Cellule();
    } else {  // Sinon, on la remplace par un obstacle
        delete table[x][y];
        table[x][y] = new CelluleObstacle();
    }
}

// Calcul du nombre de cellules vivantes adjacentes à la cellule (i, j)
int Grille::adjacent(int i, int j) {
    int n = regle->getNbAdjacent();  // Récupère le nombre de cellules adjacentes à vérifier
    int compt = 0;
    for (int k = i - n; k <= i + n; k++) {  // Vérifie les cellules autour de (i, j)
        for (int q = j - n; q <= j + n; q++) {
            if (k >= 0 && k < nbLigne && q >= 0 && q < nbColonne && !(k == i && q == j)) {
                if (table[k][q]->estVivant()) {  // Si la cellule voisine est vivante
                    compt++;
                }
            }
        }
    }
    return compt;
}

// Génère la grille de la génération suivante en fonction des règles
void Grille::generationSuiv() {
    // Crée une nouvelle grille temporaire pour la génération suivante
    vector<vector<ICellule*>> temp(nbLigne, vector<ICellule*>(nbColonne));
    
    // Remplir la nouvelle grille avec des cellules normales ou obstacles
    for (int i = 0; i < nbLigne; i++) {
        for (int j = 0; j < nbColonne; j++) {
            if (!table[i][j]->estObstacle()) {
                temp[i][j] = new Cellule();  // Cellule normale
            } else {
                temp[i][j] = new CelluleObstacle();  // Cellule obstacle
            }
        }
    }

    // Applique les règles sur chaque cellule pour déterminer son état dans la génération suivante
    for (int i = 0; i < nbLigne; i++) {
        for (int j = 0; j < nbColonne; j++) {
            int nbAdjacent = adjacent(i, j);  // Nombre de cellules vivantes adjacentes
            if (!table[i][j]->estObstacle()) {  // Si ce n'est pas un obstacle
                if (table[i][j]->estVivant()) {  // Si la cellule est vivante
                    temp[i][j]->setEtat(regle->celluleSurvit(true, nbAdjacent));  // Applique la règle de survie
                } else {  // Si la cellule est morte
                    temp[i][j]->setEtat(regle->celluleNait(false, nbAdjacent));  // Applique la règle de naissance
                }
            } else {
                temp[i][j]->setEtat(false);  // Les obstacles restent morts
            }
        }
    }

    // Libère l'ancienne grille
    for (int i = 0; i < nbLigne; i++) {
        for (int j = 0; j < nbColonne; j++) {
            delete table[i][j];
        }
    }

    // La grille actuelle devient la grille temporaire
    table = temp;
}
