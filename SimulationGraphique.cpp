#include "SimulationGraphique.h"

SimulationGraphique::SimulationGraphique(const string& path) : inPause(false), currentIndex(4), oPress(false), gPress(false) {
    gestionNomFichier = new GestionNomFichier(path);
    string nomFichier = gestionNomFichier->genererNomFichier();

    timeIntervals = {50, 125, 250, 500, 1000, 2000, 4000};
    
    // Charger la grille depuis le fichier
    fichier = new GestionFichier(nomFichier);
    this->grille = fichier->lire();  // Assurez-vous que la grille est correctement chargée.
    // Initialisation de la fenêtre
    window.create(sf::VideoMode(grille->getNbLigne() * Taille_cellule, grille->getNbColonne() * Taille_cellule), "Jeu de la Vida loca");
    cell.setSize(sf::Vector2f(Taille_cellule - 1.0f, Taille_cellule - 1.0f));
}

SimulationGraphique::~SimulationGraphique() {

}

void SimulationGraphique::dessinerTraitsGrille() {
    sf::Color couleurTrait(70, 70, 70);
    for (int j = 0; j <= grille->getNbColonne(); ++j) {
        sf::Vertex ligne[] = {
            sf::Vertex(sf::Vector2f(j * Taille_cellule, 0), couleurTrait),
            sf::Vertex(sf::Vector2f(j * Taille_cellule, grille->getNbLigne() * Taille_cellule), couleurTrait)
        };
        window.draw(ligne, 2, sf::Lines);
    }
    for (int i = 0; i <= grille->getNbLigne(); ++i) {
        sf::Vertex ligne[] = {
            sf::Vertex(sf::Vector2f(0, i * Taille_cellule), couleurTrait),
            sf::Vertex(sf::Vector2f(grille->getNbColonne() * Taille_cellule, i * Taille_cellule), couleurTrait)
        };
        window.draw(ligne, 2, sf::Lines);
    }
}


void SimulationGraphique::actualiserGrille() {
    window.clear();
    for (int i = 0; i < grille->getNbLigne(); ++i) {
        for (int j = 0; j < grille->getNbColonne(); ++j) {
            cell.setPosition(j * Taille_cellule, i * Taille_cellule);
            if (!grille->getCellule(j, i)->estObstacle())
            {
                cell.setFillColor(grille->getCellule(i, j)->estVivant() ? sf::Color::White : sf::Color::Black);
                window.draw(cell);
            } else
            {
                cell.setFillColor(sf::Color::Red);
                window.draw(cell);
            } 
        }
    }

    if (gPress)
    {
        dessinerTraitsGrille();
    }
    
    window.display();
}

void SimulationGraphique::gererEvenements() {
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
            if (event.key.code == sf::Keyboard::R)
            {
                this->grille = fichier->lire();
                cout << "reset" << endl;
                actualiserGrille();
                window.display();
            }
            if (event.key.code == sf::Keyboard::A)
            {
                this->grille->remplirAleatoire();
                std::srand(std::time(nullptr));
                actualiserGrille();
                window.display();
            }
            if (event.key.code == sf::Keyboard::Delete) {
                this->grille->remplirVide();
                actualiserGrille();
                window.display();
            }
            if (event.key.code == sf::Keyboard::G)
            {
                gPress = !gPress;
                actualiserGrille();
                window.display();
            }
            if (event.key.code == sf::Keyboard::Space)
            {
                inPause = !inPause;
            }
            while (inPause)
            {
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                    if (event.type == sf::Event::KeyPressed) {
                        if (event.key.code == sf::Keyboard::Space) {
                            inPause = false;
                        }
                        if (event.key.code == sf::Keyboard::Delete) {
                            this->grille->remplirVide();
                            actualiserGrille();
                            window.display();
                        }
                        if (event.key.code == sf::Keyboard::O) {
                             std::cout << "O appuyé" << std::endl;
                            oPress = !oPress; // Inverser état Opress
                        }
                        if (event.key.code == sf::Keyboard::R)
                        {
                            this->grille = fichier->lire();
                            cout << "reset" << endl;
                            actualiserGrille();
                            window.display();
                        }
                        if (event.key.code == sf::Keyboard::A)
                        {
                            this->grille->remplirAleatoire();
                            std::srand(std::time(nullptr));
                            actualiserGrille();
                            window.display();
                        }
                        if (event.key.code == sf::Keyboard::G)
                        {
                            gPress = !gPress;
                            actualiserGrille();
                            window.display();
                        }
                    }
                    if (event.type == sf::Event::MouseButtonPressed) {
                        int x = event.mouseButton.x / Taille_cellule;
                        int y = event.mouseButton.y / Taille_cellule;
                        if (event.mouseButton.button == sf::Mouse::Left && oPress) {
                            if (!grille->getCellule(x, y)->estObstacle())
                            {
                            grille->setCelluleO(x, y) ;
                            cell.setPosition(x * Taille_cellule, y * Taille_cellule);
                            cell.setFillColor(sf::Color::Red);
                            window.draw(cell);
                            window.display();
                            }
                              
                        } else if (event.mouseButton.button == sf::Mouse::Left && !oPress)
                        {
                            if (!grille->getCellule(x, y)->estObstacle())
                            {
                                grille->getCellule(y, x)->setEtat(true);
                                cell.setPosition(x * Taille_cellule, y * Taille_cellule);
                                cell.setFillColor(sf::Color::White);
                                window.draw(cell);
                                window.display(); 
                            } 
                        }
                        if (event.mouseButton.button == sf::Mouse::Right && !oPress) {
                            //grille->setCelluleO(x, y);
                            if (!grille->getCellule(x, y)->estObstacle())
                            {
                                grille->getCellule(y, x)->setEtat(false);
                                cell.setPosition(x * Taille_cellule, y * Taille_cellule);
                                cell.setFillColor(sf::Color::Black);
                                window.draw(cell);
                                window.display();
                            }
                        }
                        if (event.mouseButton.button == sf::Mouse::Right && oPress) {
                            if (grille->getCellule(x, y)->estObstacle())
                            {
                                grille->setCelluleO(x, y);
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
    }
}

void SimulationGraphique::execute() {
    while (window.isOpen()) {
        gererEvenements();  // Gérer les événements
        actualiserGrille();  // Afficher la grille après chaque génération
        grille->generationSuiv();  // Avancer à la génération suivante
        sf::sleep(sf::milliseconds(timeIntervals[currentIndex]));  // Attendre avant la prochaine génération
    }
    string nomFichier = gestionNomFichier->genererNomFichier();
    fichier->setPath(nomFichier);
    fichier->ecrire(grille);
}