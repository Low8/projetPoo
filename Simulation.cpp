#include "Simulation.h"

Simulation::Simulation(Regles* regle, string pathBase, int nbGeneration) : gestionFichier(pathBase), nbGeneration(nbGeneration)
{
    IGrille* grille = new Grille(0, 0, regle);
}

Simulation::~Simulation()
{
}

void Simulation::execute() {
    string nomFichier = gestionFichier.genererNomFichier();

    for (int i = 0; i < nbGeneration; i++) {
        IGestionFichier* fichier = new GestionFichier(nomFichier);

        grille = fichier->lire();
        grille->generationSuiv();
        nomFichier = gestionFichier.genererNomFichier();
        
        fichier->setPath(nomFichier);

        
        fichier->ecrire(grille);

        grille->affiche();

        cout << "=======================================" << endl;
    }
}