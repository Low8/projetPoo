#include "Client.h"

// Constructeur : initialise la simulation en appelant la fonction de configuration
Client::Client() {
    configurerSimulation();
}

// Configure la simulation en fonction des choix de l'utilisateur
void Client::configurerSimulation() {

    Regles* regle = new ReglesClassiques;  // Règles classiques par défaut
    int choix;

    // Demande à l'utilisateur le nom du fichier de génération
    cout << "Entrez le nom du fichier pour les générations : ";
    cin >> cheminDossier;

    // Demande le mode d'affichage (console ou graphique)
    std::cout << "Choisissez le mode d'affichage: Console(1) ou Interface graphique(2)";
    std::cin >> choix;

    // Selon le choix, crée la simulation appropriée
    switch(choix){
        case 1:
        {
            cout << "Entrez le nombre de générations à simuler : ";
            cin >> nombreGenerations;
    
            // Simulation en mode console
            simulation = new Simulation(regle, cheminDossier, nombreGenerations);
            break;
        }

        case 2:
        {
            // Simulation en mode graphique
            simulation = new SimulationGraphique(cheminDossier);
            break;
        }

        default:
        {
            // Choix invalide
            cout<<"Choix Invalide"<<endl;
            break;
        }
    }
}

// Lance l'exécution de la simulation
void Client::lancerSimulation() {
    simulation->execute();
}

// Destructeur : libère la mémoire allouée pour la simulation
Client::~Client() {
    delete simulation;
}
