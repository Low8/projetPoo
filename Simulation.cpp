#include "Simulation.h"

// Constructeur de la classe Simulation
// Il initialise la gestion des fichiers (avec le chemin de base), et définit le nombre de générations à simuler
// Une grille vide est également initialisée, mais pas encore utilisée dans ce constructeur
Simulation::Simulation(Regles* regle, string pathBase, int nbGeneration) : gestionFichier(pathBase), nbGeneration(nbGeneration)
{
    IGrille* grille = new Grille(0, 0, regle);  // Initialisation de la grille avec 0 lignes et 0 colonnes
}

// Destructeur de la classe Simulation (vide ici, car il n'y a pas de ressource à libérer explicitement)
Simulation::~Simulation()
{
}

// Méthode qui exécute la simulation
void Simulation::execute() {
    // Génération du nom de fichier pour la première sortie
    string nomFichier = gestionFichier.genererNomFichier();

    // Boucle pour exécuter la simulation pour un nombre de générations donné
    for (int i = 0; i < nbGeneration; i++) {
        // Création d'un objet de gestion de fichier, en spécifiant le nom de fichier
        IGestionFichier* fichier = new GestionFichier(nomFichier);

        // Lecture de la grille à partir du fichier (chargement de l'état initial)
        grille = fichier->lire();

        // Calcul de la génération suivante
        grille->generationSuiv();

        // Génération du prochain nom de fichier pour la sortie de la génération suivante
        nomFichier = gestionFichier.genererNomFichier();
        
        // Mise à jour du chemin du fichier de sortie dans l'objet fichier
        fichier->setPath(nomFichier);

        // Écriture de la grille dans le fichier
        fichier->ecrire(grille);

        // Affichage de la grille dans la console
        grille->affiche();

        // Affichage d'une ligne séparatrice pour plus de lisibilité
        cout << "=======================================" << endl;
    }
}
