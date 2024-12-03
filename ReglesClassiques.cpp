#include "ReglesClassiques.h"

ReglesClassiques::ReglesClassiques() : nbAdjacent(1) {

}

ReglesClassiques::~ReglesClassiques() {

}

bool ReglesClassiques::celluleSurvit(bool celluleActuelle, int nbAdjacent) const {
    return celluleActuelle && (nbAdjacent == 2 || nbAdjacent == 3);
}

bool ReglesClassiques::celluleNait(bool celluleActuelle, int nbAdjacent) const {
    return !celluleActuelle && nbAdjacent == 3;
}

int ReglesClassiques::getNbAdjacent() {
    return nbAdjacent;
}