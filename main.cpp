#include <SFML/Graphics.hpp>
#include <iostream>
#include "Client.h"
#include "Librairie.h"
#include "Grille.h"
#include "ReglesClassiques.h"


//def dilension de fenêtre + taille cellule (par def)
//const int Largeur = 800;
//const int Hauteur = 600;
const int Taille_cellule = 10;

//je fais une fonction afficher console ?? 


void afficherGraphique(IGrille* grille, string path) {
    IGestionFichier* fichier = new GestionFichier(path);
    grille = fichier->lire();

    sf::RenderWindow window(sf::VideoMode(grille->getNbLigne() * Taille_cellule, grille->getNbColonne() * Taille_cellule), "Jeu de la Vida loca"); //création fenetre avec les dilensions et le titre
    sf::RectangleShape cell(sf::Vector2f(Taille_cellule - 1.0f, Taille_cellule - 1.0f));

    while (window.isOpen()) { //boucle prinn fenetre
        sf::Event event;
        while (window.pollEvent(event)) { // geère ouverture ou fermeture
            if (event.type == sf::Event::Closed)
                window.close(); //ferme fenetre su on appuie sur ferme fenetre
        }

        //grille.generationSuiv(); //maj grille


        window.clear(); //efface fenetre pour afficher la prochaine gen
        for (int i = 0; i < grille->getNbLigne(); ++i) { // parcours touuute els cellules
            for (int j = 0; j < grille->getNbColonne(); ++j) {
                cell.setPosition(j * Taille_cellule, i * Taille_cellule); // position ccellule dans fenetre
                cell.setFillColor(grille->getCellule(i, j)->estVivant() ? sf::Color::White : sf::Color::Black); //def color cellule
                window.draw(cell);
            }
        }
        window.display();

    }
}

int main() {
    IGrille* grille = new Grille(100, 100, new ReglesClassiques()); //grille adaptée a l affichage console

    //bref la tu fais ton choix ma belle
    int choix;
    std::cout << "Choisissez le mode d'affichage: 1 / Console ou 2 / Interface graphique / 3 Console et Interface graphique";
    std::cin >> choix;


    switch(choix){
        case 1:
        {
            
            Client client;
            client.lancerSimulation();
        }

        case 2:
        {
            afficherGraphique(grille, "generation/generation_out.txt");  
        }

        case 3:
        {
            Client client;
            client.lancerSimulation();
            afficherGraphique(grille, "generation/generation_out.txt");
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