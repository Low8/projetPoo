#include <SFML/Graphics.hpp>
#include <iostream>
#include "Client.h"
#include "Librairie.h"
#include "Grille.h"
#include "ReglesClassiques.h"



const int Taille_cellule = 10;

//je fais une fonction afficher console ?? 


void afficherGraphique(IGrille* grille, const string path) {
    vector<int> timeIntervals = {125, 250, 500, 1000, 2000, 4000};
    int currentIndex = 3;
    bool inPause = false;
    IGestionFichier* fichier = new GestionFichier(path);
    grille = fichier->lire();

    sf::RenderWindow window(sf::VideoMode(grille->getNbLigne() * Taille_cellule, grille->getNbColonne() * Taille_cellule), "Jeu de la Vida loca"); //création fenetre avec les dilensions et le titre
    sf::RectangleShape cell(sf::Vector2f(Taille_cellule - 1.0f, Taille_cellule - 1.0f));

    while (window.isOpen()) { //boucle prinn fenetre
        sf::Event event;
        while (window.pollEvent(event)) { // geère ouverture ou fermeture
            if (event.type == sf::Event::Closed) {
                window.close(); //ferme fenetre su on appuie sur ferme fenetre
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left) {
                    if (currentIndex < timeIntervals.size() - 1) {
                        currentIndex++;
                        cout << currentIndex << endl;
                    }
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    if (currentIndex > 0) {
                        currentIndex--;
                        cout << currentIndex << endl;
                    }
                }
                if (event.key.code == sf::Keyboard::Space)
                {
                    inPause = !inPause;
                }
                while (inPause)
                {
                    while (window.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed) {
                            window.close();
                        }
                        if (event.type == sf::Event::KeyPressed)
                        {
                            if (event.key.code == sf::Keyboard::Space)
                            {
                                inPause = false;
                            }
                            if (event.key.code == sf::Keyboard::Delete) {
                                window.clear();
                                window.display();
                            }
                        }
                        if (event.type == sf::Event::MouseButtonPressed) {
                            int x = event.mouseButton.x / Taille_cellule;
                            int y = event.mouseButton.y / Taille_cellule;

                            if (event.mouseButton.button == sf::Mouse::Left) {
                                grille->getCellule(y, x)->setEtat(true);
                                cell.setPosition(x * Taille_cellule, y * Taille_cellule);
                                cell.setFillColor(sf::Color::White);
                                window.draw(cell);
                                window.display();
                            }
                            if (event.mouseButton.button == sf::Mouse::Right) {
                                grille->getCellule(y, x)->setEtat(false);
                                cell.setPosition(x * Taille_cellule, y * Taille_cellule);
                                cell.setFillColor(sf::Color::Black);
                                window.draw(cell);
                                window.display();
                            }
                        }
                    }   
                }
            }
        }
            



        window.clear(); //efface fenetre pour afficher la prochaine gen
        for (int i = 0; i < grille->getNbLigne(); ++i) { // parcours touuute els cellules
            for (int j = 0; j < grille->getNbColonne(); ++j) {
                cell.setPosition(j * Taille_cellule, i * Taille_cellule); // position ccellule dans fenetre
                cell.setFillColor(grille->getCellule(i, j)->estVivant() ? sf::Color::White : sf::Color::Black); //def color cellule
                window.draw(cell);
            }
        }
        window.display();
        grille->generationSuiv(); //maj grille
        sf::sleep(sf::milliseconds(timeIntervals[currentIndex]));

    }
    delete fichier;
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
            break;
        }

        case 2:
        {
            afficherGraphique(grille, "generation/generation_out.txt");  
            break;
        }

        case 3:
        {
            Client client;
            client.lancerSimulation();
            afficherGraphique(grille, "generation/generation_out.txt");
            break;
        }

        default:
        {
            cout<<"Choix Invalide"<<endl;
            break;
        }

    }

    return 0;
}


//faut configurer vsc
//bisous