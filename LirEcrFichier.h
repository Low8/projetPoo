#include "Librairie.h"
#include "Grille.h"

 
class LirEcrFichier 
{ 
private: 
    string message; 
    ifstream f_in; 
    ofstream f_out;
public: 
    void ecrire(Grille, string); 
    string lire(string);
    vector<vector<Cellule>> convertion();
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

Grille LirEcrFichier::lire(string path) 
{
    string line;
    this->message.clear();
  
    f_in.open(path);
    if (!f_in.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier en lecture : " << path << endl;
        return "";
    }
    while (getline(f_in, line)) { 
        this->message.append(line);
    }


    f_in.close();
 
    return 
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
 