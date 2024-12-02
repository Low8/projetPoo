#include "Simulation.h"

Simulation::Simulation(Regles* regle, string pathBase, int nbGeneration) : gestionFichier(pathBase), nbGeneration(nbGeneration)
{
    IGrille* grille = new Grille(0, 0, regle);
}

Simulation::~Simulation()
{
}

void Simulation::execute() {
    string fichierLecture = gestionFichier.genererNomFichier();

    for (int i = 0; i < nbGeneration; i++) {
        LireFichier lecture(fichierLecture);

        grille = lecture.lire();
        grille->generationSuiv();
        string fichierEcriture = gestionFichier.genererNomFichier();
        
        EcrireFichier ecriture(fichierEcriture);

        
        ecriture.ecrire(grille);

        

        fichierLecture = fichierEcriture;
        grille->affiche();

        cout << "=======================================" << endl;
    }
}