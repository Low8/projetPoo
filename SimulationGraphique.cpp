// #include <SFML/Graphics.hpp> 
// #include "Grille.h" 

// const int Largeur = 800;
// const int Hauteur = 600;
// const int Taille_cellule = 10;

// int SFML(){
//     // Crée fenetre avec dimensuos
//     sf::RenderWindow window(sf::VideoMode(Largeur, Hauteur), "Jeu de la Vida loca");

//     Grille grille(Hauteur/Taille_cellule, Largeur) / Taille_cellule, new Regles());

    
//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed)
//                 window.close(); // Ferme la fenêtre si l'événement de fermeture est détecté
//         }

//        grille.generationSuiv();
        
        
//         window.clear(); 
//         for (int i = 0; i < Hauteur / Taille_cellule; ++i) {
//             for (int j = 0; j < Largeur / Taille_cellule; ++j) {
//                 // Crée un rectangle représentant une cellule
//                 sf::RectangleShape cell(sf::Vector2f(Taille_cellule - 1, Taille_cellule - 1));
//                 // Positionne la cellule dans la fenêtre
//                 cell.setPosition(j * Taille_cellule, i * Taille_cellule);
//                 // Définit la couleur de la cellule (blanche si vivante, noire sinon)
//                 cell.setFillColor(grid[i][j] ? sf::Color::White : sf::Color::Black);
//                 window.draw(cell); // Dessine la cellule dans la fenêtre
//             }
//         }
//         window.display(); // Affiche le contenu de la fenêtre
//     }

//     return 0; // Termine le programme
// }