#include "Grille.h"

class ILirefichier
{
private:
    ifstream f_in;

public:
    Virtual Grille lire(const string) = 0;
};

