#include "Simulation.h"

int main() {
    string fichierIni = "generation";
    ReglesClassiques regle;
    Simulation jeu(regle, fichierIni, 10);
    jeu.execute();

    /*Grille grille(5, 5, regle);
    grille.table[0][1].setEtat(1);
    grille.table[2][0].setEtat(1);
    grille.table[2][1].setEtat(1);
    grille.table[2][2].setEtat(1);
    grille.table[1][2].setEtat(1);
    grille.affiche();
    grille.generationSuiv();
    grille.affiche();*/
}