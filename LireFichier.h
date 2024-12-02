#pragma once

#include "ILireFichier.h"

class LireFichier : public ILireFichier
{
private:
    string path;
public:
    LireFichier(string);
    ~LireFichier();
    IGrille* lire() override;
};