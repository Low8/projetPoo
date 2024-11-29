#include "Simulation.h"

Simulation::Simulation(const ReglesClassiques regle, string pathBase, int nbGeneration) : grille(0, 0, regle), gestionFichier(pathBase), nbGeneration(nbGeneration)
{
}

Simulation::~Simulation()
{
}

void Simulation::execute() {
    string fichierLecture = gestionFichier.genererNomFichier();

    for (int i = 0; i < nbGeneration; i++) {
        LireFichier lecture(fichierLecture);
        grille = lecture.lire();

        string fichierEcriture = gestionFichier.genererNomFichier();
        
        EcrireFichier ecriture(fichierEcriture);
        ecriture.ecrire(grille);

        fichierLecture = fichierEcriture;
        grille.affiche();
        cout << "====================================" << endl;
    }
}