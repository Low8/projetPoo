#include "Librairie.h"
#include "Grille.h"

 
class LirEcrFichier 
{ 
private: 
    ifstream f_in; 
    ofstream f_out;
public: 
    void ecrire(Grille, string); 
    Grille lire(string);
    int retourneLigne();
    int retourneColonne();
};

 
void LirEcrFichier::ecrire(Grille tabl, string path) 
{ 
    f_out.open(path, ofstream::out);
    if (!f_out.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier en écriture : " << path << endl;
        return;
    }
    f_out << tabl.getNbLigne() << " " << tabl.getNbColonne() << endl;

    for (int y = 0; y < tabl.getNbLigne(); y++) {
        for (int x = 0; x < tabl.getNbColonne(); x++) {
            f_out << (tabl.getCellule(x, y).estVivant() ? 1 : 0) << ' ';
        }
        f_out << endl;
    }

    f_out.close(); 
}

Grille LirEcrFichier::lire(const std::string& path) 
{
    std::ifstream f_in(path);
    if (!f_in.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier en lecture : " << path << std::endl;
    }

    int nbLigne = 0, nbColonne = 0;
    f_in >> nbLigne >> nbColonne;

    if (nbLigne <= 0 || nbColonne <= 0) {
        cerr << "Erreur : dimensions invalides dans le fichier." << std::endl;
    }

    Grille grille(nbLigne, nbColonne);

    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            int etat;
            if (!(f_in >> etat) || (etat != 0 && etat != 1)) {
                cerr << "Erreur : données manquantes ou invalides dans le fichier." << std::endl;
            }
            grille.getCellule(i, j).setEtat(etat);
        }
    }

    f_in.close();

    return grille;
}


int main(void) 
{ 
 LirEcrFichier* fichier; 
 string path; 
 string message;
 string path2; 
 string message2;
 
 
 fichier = new LirEcrFichier(); 
 path = "/wsl.localhost/Ubuntu-22.04\\home\\game\\prosit2\\corbeille\\fichier_lire.txt";
 message = "bonjour"; 
 fichier->ecrire(message, path2); 
 message2 = fichier->lire(path); 
 
 cout << message2 << endl; 
 
 delete fichier; 
 
    return 0; 
}