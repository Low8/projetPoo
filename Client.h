#pragma once

#include "Simulation.h"
#include "SimulationGraphique.h"

class Client {
private:
    ISimulation* simulation;
    Regles* regle;
    string cheminDossier;
    int nombreGenerations;

public:
    Client();
    void configurerSimulation();
    void lancerSimulation();
    ~Client();
};