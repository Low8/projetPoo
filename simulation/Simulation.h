#pragma once

#include "ISimulation.h"
#include "LireFichier.h"
#include "EcrireFichier.h"
#include "GestionNomFichier.h"

class Simulation : public ISimulation
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