#pragma once

#include "GestionFichier.h"
#include "Grille.h"

void testUnitaire() {
    // Charger les grilles depuis des fichiers
    IGestionFichier* f_ini = new GestionFichier("generation/Grille_test_ini.txt");
    IGestionFichier* f_final = new GestionFichier("generation/Grille_test_final.txt");

    Regles* regles = new ReglesClassiques();

    IGrille* grilleIni = new Grille(0,0,regles);    // Grille initiale
    grilleIni = f_ini->lire(); 
    IGrille* grilleFinal = new Grille(0,0,regles);  // Grille finale 5 iteration
    grilleFinal = f_final->lire();


    // Test 1 : Vérification de la taille de la grille
    if (grilleIni->getNbLigne() == 5 && grilleIni->getNbColonne() == 5) {
        cout << "[OK] Lecture taille Grille" << endl;
    } else {
        cout << "[FAILURE] Lecture taille Grille" << endl;
    }

    // Test 2 : Vérification des états des cellules aux coins
    if (grilleIni->getCellule(0, 0)->estVivant() == true && grilleIni->getCellule(0, 4)->estVivant() == false && grilleIni->getCellule(4, 0)->estVivant() == true &&grilleIni->getCellule(4, 4)->estVivant() == true) {
        cout << "[OK] Lecture cellule grille" << endl;
    } else {
        cout << "[FAILURE] Lecture cellule grille" << endl;
    }

    f_ini->setPath("generation/Grille_test_ecrire.txt"); 
    f_ini->ecrire(grilleIni);       // ecriture dans fichier

    grilleIni = f_ini->lire(); // lire ce qui veint d'être écrit
    
    // Test 3 : Vérification de la taille après ecriture
    if (grilleIni->getNbLigne() == 5 && grilleIni->getNbColonne() == 5) {
        cout << "[OK] Taille après ecriture" << endl;
    } else {
        cout << "[FAILURE] Taille après ecriture" << endl;
    }

    // Test 4 : Vérification des états des cellules aux coins après écriture
    if (grilleIni->getCellule(0, 0)->estVivant() == true && grilleIni->getCellule(0, 4)->estVivant() == false && grilleIni->getCellule(4, 0)->estVivant() == true &&grilleIni->getCellule(4, 4)->estVivant() == true) {
        cout << "[OK] Lecture cellule grille apres ecriture" << endl;
    } else {
        cout << "[FAILURE] Lecture cellule grille apres ecriture" << endl;
    }

    // Test 5 : verif adjacent

    int adjacent = grilleIni->adjacent(2, 2);
    if (adjacent == 4)
    {
        cout << "[OK] calcul adjacent" << endl;
    } else
    {
        cout << "[FAILURE] calcul adjacent" << endl;
    }
    
    

    for (int i = 0; i < 5; i++)
    {
        grilleIni->generationSuiv();
    }

    

    // Test 6 : Comparer grille après 5 générations
    bool valide= true;
    for (int i = 0; i < grilleIni->getNbLigne(); i++)
    {
        for (int j = 0; j < grilleIni->getNbColonne(); j++)
        {
            if(grilleIni->getCellule(i,j)->estVivant() != grilleFinal->getCellule(i,j)->estVivant()){
                valide = false;
                break;
            }
        }
    }

    if (valide)
    {
        cout << "[OK] Grille apres 5 generations" << endl;
    } else
    {
        cout << "[FAILURE] Grille apres 5 generations" << endl;
    }
   
    delete grilleIni;
    delete grilleFinal;
}