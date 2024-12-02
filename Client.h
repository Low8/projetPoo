#pragma once

#include "Simulation.h"

class Client {
private:
    Simulation* simulation;
    Regles* regle;
    string cheminDossier;
    int nombreGenerations;

public:
    Client();
    void configurerSimulation();
    void lancerSimulation();
    ~Client();
};