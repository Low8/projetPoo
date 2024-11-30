#include "Simulation.h"

int main() {
    string fichierIni = "generation";
    Regles* regle = new ReglesClassiques;
    Simulation jeu(regle, fichierIni, 10);
    jeu.execute();
}