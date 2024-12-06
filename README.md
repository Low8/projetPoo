# projet Poo

## Diagramme classe

```mermaid
classDiagram
    ICellule <|-- Cellule
    ICellule <|-- CelluleObstacle
    ISimulation <|-- SimulationTerminale
    ISimulation <|-- SimulationGraphique
    IGestionFichier <|-- GestionFichier
    Regles <|-- ReglesClassiques   
    IGrille *-- Regles : contains
    ISimulation *-- IGrille : contains
    ISimulation *-- GestionNomFichier : contains
    Client ..> ISimulation : uses
    IGestionFichier ..> IGrille : uses
    ICellule ..> IGrille
    IGrille <|-- Grille
    IGestionFichier ..> ISimulation : uses
    
    class ICellule {
    + estVivant() bool
    + setEtat(bool etat) void
    + estObstacle() bool
}

class Cellule {
    + Cellule()
    + ~Cellule()
    + estVivant() bool
    + setEtat(bool etat) void
    + estObstacle() bool
}

class CelluleObstacle {
    + CelluleObstacle()
    + ~CelluleObstacle()
    + estVivant() bool
    + setEtat(bool etat) void
    + estObstacle() bool
}

class IGrille {
    + ~IGrille()
    + iniGrille() void
    + affiche() void
    + getNbLigne() int
    + getNbColonne() int
    + SetNbColonne(int colonne) void
    + SetNbLigne(int ligne) void
    + getCellule(int ligne, int colonne) ICellule*
    + adjacent(int ligne, int colonne) int
    + generationSuiv() void
    + setCelluleO(int ligne, int colonne) void
}

class Grille {
    - nbLigne int
    - nbColonne int
    - regle Regles*
    - table vector<vector<ICellule*>>

    + Grille(int lignes, int colonnes, Regles* regle)
    + ~Grille()
    + iniGrille() void
    + affiche() void
    + getNbLigne() int
    + getNbColonne() int
    + SetNbColonne(int colonne) void
    + SetNbLigne(int ligne) void
    + getCellule(int ligne, int colonne) ICellule*
    + adjacent(int ligne, int colonne) int
    + generationSuiv() void
    + setCelluleO(int ligne, int colonne) void
}

class ISimulation {
    + ~ISimulation()
    + execute() void
}

class SimulationTerminale{
    - grille IGrille*
    - gestionFichier GestionNomFichier
    - nbGeneration int

    + SimulationTerminale(Regles* regle, string chemin, int generations)
    + ~SimulationTerminale()
    + execute() void
}

class SimulationGraphique{
    - Taille_cellule const int
    - window sf::RenderWindow
    - cell sf::RectangleShape
    - grille IGrille*
    - fichier IGestionFichier*
    - inPause bool
    - oPress bool
    - currentIndex int
    - timeIntervals std::vector<int>

    + SimulationGraphique(const string& path)
    + ~SimulationGraphique()
    + gererEvenements() void
    + actualiserGrille() void
    + execute() void
}

class IGestionFichier {
    + ~IGestionFichier()
    + lire() IGrille*
    + ecrire(IGrille*) void
    + getPath() string
    + setPath(string) void
}

class GestionFichier{
    - path string

    + GestionFichier(string chemin)
    + ~GestionFichier()
    + lire() IGrille*
    + ecrire(IGrille*) void
    + getPath() string
    + setPath(string) void
}

class GestionNomFichier {
    - compteur int
    - pathBase std::string
    - premiereGeneration bool

    + GestionNomFichier(const string& basePath)
    + genererNomFichier() string
}

class Regles {
    + ~Regles()
    + celluleSurvit(bool etat, int voisins) bool
    + celluleNait(bool etat, int voisins) bool
    + getNbAdjacent() int
}

class ReglesClassiques{
    - nbAdjacent int

    + ReglesClassiques()
    + ~ReglesClassiques()
    + celluleSurvit(bool etat, int voisins) bool
    + celluleNait(bool etat, int voisins) bool
    + getNbAdjacent() int
}

class Client {
    - simulation ISimulation*
    - regle Regles*
    - cheminDossier string
    - nombreGenerations int

    + Client()
    + configurerSimulation() void
    + lancerSimulation() void
    + ~Client()
}
```

## Diagrammes Sequences

```mermaid
sequenceDiagram
    participant Client
    participant Regle
    participant SimulationTerminale
    participant Grille
    participant Cellule
    participant GestionNomFichier
    participant GestionFichier

    Client ->>+ Regle : Regle()
    Regle -->>- Client : objet crée
    Client ->> Client : choix simulation, nomfichier, nbGeneration
    Client ->>+ SimulationTerminale : Simulation(regle, chemin, nbGeneration)
    SimulationTerminale ->>+ Grille : Grille(nbLigne = 0, nbColonne = 0, Regle)
    Grille ->>+ Cellule : Cellule(), true
    Cellule -->>- Grille : objets crée
    Grille ->>- SimulationTerminale : objets crée
    SimulationTerminale ->>+ GestionNomFichier : GestionNomFichier
    GestionNomFichier -->>- SimulationTerminale : objets crée
    loop nbGeneration
        SimulationTerminale ->>+ GestionFichier : GestionFichier(GestionNomFichier)
        GestionFichier -->>- SimulationTerminale : objets crée
        SimulationTerminale ->>+ GestionFichier : Lire()
        GestionFichier -->>- SimulationTerminale : return grille
        SimulationTerminale ->>+ Grille : generationSuivante()
        Grille ->> Grille : Calcul prochaine grille
        Grille -->>- SimulationTerminale : actualise grille
        SimulationTerminale ->>+ GestionNomFichier : genererNomFichier()
        GestionNomFichier ->> GestionNomFichier : genere le prochain nom
        GestionNomFichier -->>- SimulationTerminale : actualise le nom
        SimulationTerminale ->>+ GestionFichier : setPath(nouveau nom)
        GestionFichier -->>- SimulationTerminale : change le path de l'objet fichier
        SimulationTerminale ->>+ GestionFichier : ecrire()
        GestionFichier ->> GestionFichier : ecrire dans le fichier txt
        GestionFichier -->>- SimulationTerminale : 
        SimulationTerminale ->>+ Grille : affiche()
        Grille -->>- SimulationTerminale : 
    end
    SimulationTerminale -->>- Client : ```


