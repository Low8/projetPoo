#include "ReglesClassiques.h"

bool ReglesClassiques::celluleSurvit(bool celluleActuelle, int nbAdjacent) const {
    return celluleActuelle && (nbAdjacent == 2 || nbAdjacent == 3);
}

bool ReglesClassiques::celluleNait(bool celluleActuelle, int nbAdjacent) const {
    return !celluleActuelle && nbAdjacent == 3;
}