#include <SFML/Graphics.hpp>
#include <iostream>
#include "Client.h"
#include "Librairie.h"
#include "Grille.h"
#include "ReglesClassiques.h"


//def dilension de fenêtre + taille cellule (par def)
const int Largeur = 800;
const int Hauteur = 600;
const int Taille_cellule = 10;

//je fais une fonction afficher console ?? 


void afficherGraphique(Grille& grille) {
    sf::RenderWindow window(sf::VideoMode(Largeur, Hauteur), "Jeu de la Vida loca"); //création fenetre avec les dilensions et le titre

    while (window.isOpen()) { //boucle prinn fenetre
        sf::Event event;
        while (window.pollEvent(event)) { // geère ouverture ou fermeture
            if (event.type == sf::Event::Closed)
                window.close(); //ferme fenetre su on appuie sur ferme fenetre
        }

        grille.generationSuiv(); //maj grille

        window.clear(); //efface fenetre pour afficher la prochaine gen
        for (int i = 0; i < grille.getNbLigne(); ++i) { // parcours touuute els cellules
            for (int j = 0; j < grille.getNbColonne(); ++j) {
                sf::RectangleShape cell(sf::Vector2f(Taille_cellule - 1, Taille_cellule - 1));
                cell.setPosition(j * Taille_cellule, i * Taille_cellule); // position ccellule dans fenetre
                cell.setFillColor(grille.getCellule(i, j)->estVivant() ? sf::Color::White : sf::Color::Black); //def color cellule
                window.draw(cell);
            }
        }
        window.display();
    }
}

int main() {
    Grille grille(Hauteur / Taille_cellule, Largeur / Taille_cellule, new ReglesClassiques()); //grille adaptée a l affichage console

    //bref la tu fais ton choix ma belle
    int choix;
    std::cout << "Choisissez le mode d'affichage: 1 / Console ou 2 / Interface graphique / 3 Console et Interface graphique";
    std::cin >> choix;

    Client client;

    switch(choix){
        case 1:
        {
            
           client.lancerSimulation();
        }

        case 2:
        {
          afficherGraphique(grille);  
        }

        case 3:
        {
            client.lancerSimulation();
            afficherGraphique(grille);
        }

        default:
        {
            cout<<"Choix Invalide"<<endl;
        }

    }

    return 0;
}


//faut configurer vsc
//bisous