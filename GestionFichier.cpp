#include "GestionFichier.h"

// Constructeur : initialise le chemin du fichier
GestionFichier::GestionFichier(string path) : path(path) {

}

// Destructeur : libère les ressources (aucune allocation dynamique dans ce cas)
GestionFichier::~GestionFichier() {

}

// Fonction de lecture du fichier et de création de la grille
IGrille* GestionFichier::lire() {
    ifstream f_in;
    f_in.open(path);  // Ouverture du fichier en mode lecture
    if (!f_in.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier en lecture : " << path << endl;
        exit(EXIT_FAILURE);  // Si l'ouverture échoue, on termine l'exécution
    }

    int nbLigne = 0, nbColonne = 0;
    f_in >> nbLigne >> nbColonne;  // Lecture des dimensions de la grille

    // Vérification de la validité des dimensions
    if (nbLigne <= 0 || nbColonne <= 0) {
        cerr << "Erreur : dimensions invalides dans le fichier." << endl;
        exit(EXIT_FAILURE);
    }

    Regles* regle = new ReglesClassiques;  // Initialisation des règles classiques
    IGrille* grille = new Grille(nbLigne, nbColonne, regle);  // Création de la grille

    int etat;
    // Remplissage des cellules de la grille avec les états lus dans le fichier
    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            if (!(f_in >> etat) || (etat != 0 && etat != 1)) {  // Vérification des données valides
                cerr << "Erreur : données manquantes, en trop ou invalides dans le fichier." << endl;
                exit(EXIT_FAILURE);
            }
            grille->getCellule(i, j)->setEtat(etat);  // Attribution de l'état à la cellule
        }
    }

    // Vérification s'il reste des données après la grille
    if (f_in >> etat) {
        cerr << "Erreur : données manquantes, en trop ou invalides dans le fichier." << endl;
        exit(EXIT_FAILURE);
    }
    
    f_in.close();  // Fermeture du fichier après lecture
    return grille;  // Retour de la grille chargée
}

// Fonction d'écriture de la grille dans un fichier
void GestionFichier::ecrire(IGrille* grille) {
    ofstream f_out;
    f_out.open(path, ofstream::out);  // Ouverture du fichier en mode écriture
    if (!f_out.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier en écriture : " << path << endl;
        exit(EXIT_FAILURE);  // Si l'ouverture échoue, on termine l'exécution
    }

    f_out << grille->getNbLigne() << " " << grille->getNbColonne() << endl;  // Écriture des dimensions

    // Écriture de l'état de chaque cellule de la grille
    for (int i = 0; i < grille->getNbLigne(); i++) {
        for (int j = 0; j < grille->getNbColonne(); j++) {
            f_out << (grille->getCellule(i, j)->estVivant() ? 1 : 0) << ' ';  // 1 si vivante, 0 sinon
        }
        f_out << endl;  // Nouvelle ligne après chaque ligne de la grille
    }

    f_out.close();  // Fermeture du fichier après écriture
}

// Getter pour le chemin du fichier
string GestionFichier::getPath() {
    return path;
}

// Setter pour modifier le chemin du fichier
void GestionFichier::setPath(string path) {
    this->path = path;
}
