#pragma once

#include "Lirefichier.h"
#include "Ecrirefichier.h"
#include "GestionNomFichier.h"

class Simulation
{
private:
    Grille grille;
    GestionNomFichier gestionFichier;
    int nbGeneration;
public:
    Simulation(const ReglesClassiques, string, int);
    ~Simulation();
    void execute();
};

Simulation::Simulation(const ReglesClassiques regle, string pathBase, int nbGeneration) : grille(0, 0, regle), gestionFichier(pathBase), nbGeneration(nbGeneration)
{
}

Simulation::~Simulation()
{
}

void Simulation::execute() {
    string fichierLecture = gestionFichier.genererNomFichier();

    for (int i = 0; i < nbGeneration; i++) {
        Lirefichier lecture(fichierLecture);
        grille = lecture.lire();

        string fichierEcriture = gestionFichier.genererNomFichier();
        
        Ecrirefichier ecriture(fichierEcriture);
        ecriture.ecrire(grille);

        fichierLecture = fichierEcriture;
        grille.affiche();
        cout << "====================================" << endl;
    }
}
