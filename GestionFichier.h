#pragma once

#include "IGestionFichier.h"

class GestionFichier : public IGestionFichier
{
private:
    string path;
public:
    GestionFichier(string);
    ~GestionFichier();
    IGrille* lire() override;
    void ecrire(IGrille*) override;
    string getPath() override;
    void setPath(string) override;
};