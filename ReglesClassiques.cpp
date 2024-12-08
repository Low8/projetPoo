#include "ReglesClassiques.h"

// Constructeur de la classe, initialise le nombre d'adjacents à 1 (c'est une valeur par défaut)
ReglesClassiques::ReglesClassiques() : nbAdjacent(1) {

}

// Destructeur de la classe (vide dans ce cas, car il n'y a pas de ressource dynamique à libérer)
ReglesClassiques::~ReglesClassiques() {

}

// Fonction qui détermine si une cellule survit ou non à la génération suivante
// La cellule survit si elle est actuellement vivante et a 2 ou 3 voisins vivants
bool ReglesClassiques::celluleSurvit(bool celluleActuelle, int nbAdjacent) const {
    return celluleActuelle && (nbAdjacent == 2 || nbAdjacent == 3);
}

// Fonction qui détermine si une cellule naît dans la génération suivante
// Une cellule naît si elle est actuellement morte et a exactement 3 voisins vivants
bool ReglesClassiques::celluleNait(bool celluleActuelle, int nbAdjacent) const {
    return !celluleActuelle && nbAdjacent == 3;
}

// Getter pour récupérer le nombre d'adjacents utilisé dans les règles (1 par défaut ici)
int ReglesClassiques::getNbAdjacent() {
    return nbAdjacent;
}
