#include "Client.h"

Client::Client() {
    configurerSimulation();
}

void Client::configurerSimulation() {

    Regles* regle = new ReglesClassiques;
    int choix;

    /*cout << "Entrez le chemin du dossier pour les générations : ";
    cin >> cheminDossier;*/
    cheminDossier = "generation";

    std::cout << "Choisissez le mode d'affichage: 1 / Console ou 2 / Interface graphique / 3 Console et Interface graphique";
    std::cin >> choix;

    switch(choix){
        case 1:
        { 
            cout << "Entrez le nombre de générations à simuler : ";
            cin >> nombreGenerations;
    
            simulation = new Simulation(regle, cheminDossier, nombreGenerations);
            break;
        }

        case 2:
        {
            simulation = new SimulationGraphique(cheminDossier);
            break;
        }

        default:
        {
            cout<<"Choix Invalide"<<endl;
            break;
        }
    }
}

void Client::lancerSimulation() {
    simulation->execute();
}

Client::~Client() {
    delete simulation;
}