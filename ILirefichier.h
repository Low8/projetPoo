#pragma once;

#include "Grille.h"

class ILirefichier
{
protected:
    string path;
public:
    ILirefichier(string);
    ~ILirefichier();
    virtual Grille lire() = 0;
};

ILirefichier::ILirefichier(string path) : path(path)
{
};

ILirefichier::~ILirefichier() {

};