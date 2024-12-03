#include "Client.h"
#include <iostream>

Client::Client() {
    configurerSimulation();
}

void Client::configurerSimulation() {

    cout << "Entrez le nombre de générations à simuler : ";
    cin >> nombreGenerations;

    cout << "Entrez le chemin du dossier pour les générations : ";
    cin >> cheminDossier;
    
    Regles* regle = new ReglesClassiques;
    simulation = new Simulation(regle, cheminDossier, nombreGenerations);
}

void Client::lancerSimulation() {
    simulation->execute();
}

Client::~Client() {
    delete simulation;
}