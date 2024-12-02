#pragma once

#include "ISimulation.h"
#include "LireFichier.h"
#include "EcrireFichier.h"
#include "GestionNomFichier.h"

class Simulation : public ISimulation
{
private:
    IGrille* grille;
    GestionNomFichier gestionFichier;
    int nbGeneration;
public:
    Simulation(Regles*, string, int);
    ~Simulation();
    void execute();
};