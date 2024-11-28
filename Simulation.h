#pragma once

#include "Lirefichier.h"
#include "Ecrirefichier.h"

class Simulation
{
private:
    Grille grille;
    Lirefichier lecture;
    Ecrirefichier ecriture;
public:
    Simulation(const ReglesClassiques, string, string);
    ~Simulation();
    void execute(int);
};

Simulation::Simulation(const ReglesClassiques regle, string pathL, string pathE) : grille(0, 0, regle), lecture(pathL), ecriture(pathE)
{
}

Simulation::~Simulation()
{
}

void Simulation::execute(int nbTour) {

}