#pragma once

#include "ISimulation.h"
#include "GestionFichier.h"
#include "GestionNomFichier.h"

class SimulationGraphique : public ISimulation{
private:
    const int Taille_cellule = 10;
    sf::RenderWindow window;
    sf::RectangleShape cell;
    IGrille* grille;
    IGestionFichier* fichier;
    bool inPause;
    bool oPress;
    int currentIndex;
    std::vector<int> timeIntervals;
public:
    SimulationGraphique(const string& path);
    ~SimulationGraphique();
    void gererEvenements();
    void actualiserGrille();
    void execute() override;
};

