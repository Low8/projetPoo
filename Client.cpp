#include "Client.h"

Client::Client() {
    configurerSimulation();
}

void Client::configurerSimulation() {

    Regles* regle = new ReglesClassiques;
    int choix;

    cout << "Entrez le nom du fichier pour les générations : ";
    cin >> cheminDossier;

    std::cout << "Choisissez le mode d'affichage: Console(1) ou Interface graphique(2)";
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