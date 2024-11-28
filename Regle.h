#include "Librairie.h"
#include "Cellule.h"

class Regle{
public:
    int adjacent(int i, int j,const vector<vector<Cellule>>&vecteurs) {
        int compt = 0;
        for (int k = i - 1; k<=i+1; k++){
            for(int q = j-1; q <= j+1; q++){
                if(k>=0 && k< 10 && q>= 0 && q<10 && !(k==i && q == j)){
                    if(vecteurs[k][q].estVivant()){
                        compt++;
                    }
                }
            }
        }
        return compt;
    }
    
    
    void genarationSuiv(vector<vector<Cellule>>&vecteurs) {
        vector<vector<Cellule>>temp(10, vector<Cellule>(10));
        for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    if (vecteurs[i][j].estVivant()){
                        if (adjacent(i, j, vecteurs) == 2 || adjacent(i, j, vecteurs) == 3){
                            temp[i][j].SetEtat(true);
                        } else {
                            temp[i][j].SetEtat(false);
                        }
                    }else{
                        if (adjacent(i, j, vecteurs) == 3) {
                            temp[i][j].SetEtat(true);
                        } else{
                            temp[i][j].SetEtat(false);                            
                        }
                    }
                }
        }
            vecteurs = temp;
    }
    
    void affiche(vector<vector<Cellule>>&vecteurs){
        for (int i = 0; i<=10; i++){
            for (int j = 0; j<=10; j++){
                cout<<(vecteurs.estVivant() ? 1 : 0) << "\t" ;
            }
            cout<<endl;
        }
        }
};

