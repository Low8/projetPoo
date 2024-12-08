#include "GestionNomFichier.h"

// Constructeur qui initialise le chemin de base, le compteur et l'état de la première génération
GestionNomFichier::GestionNomFichier(const string& path) : pathBase(path), compteur(1), premiereGeneration(true)
{
}

// Méthode pour générer un nom de fichier
string GestionNomFichier::genererNomFichier() {
    stringstream nomFichier;  // Utilisation de stringstream pour construire le nom de fichier

    // Si c'est la première génération, on crée un nom de fichier sans compteur
    if (premiereGeneration) {
        nomFichier << "generation/" << pathBase << "_out.txt";  // Construction du chemin du fichier de sortie
        premiereGeneration = false;  // On indique que ce n'est plus la première génération
    } else {
        // Si ce n'est pas la première génération, on ajoute un compteur au nom du fichier
        nomFichier << "generation/" << pathBase << "_out_" << compteur << ".txt";
        compteur++;  // Incrémentation du compteur pour la prochaine génération
    }

    return nomFichier.str();  // Retour du nom de fichier généré sous forme de chaîne de caractères
}
