#include <iostream>
using namespace std;

int adjacent(int i, int j, int tab[10][10]) {
    int compt = 0;
    for (int k = i - 1; k<=i+1; k++){
        for(int q = j-1; q <= j+1; q++){
            if(k>=0 && k< 10 && q>= 0 && q<10 && !(k==i && q == j)){
                if(tab[k][q] == 1){
                    compt++;
                }
            }
        }
    }
    return compt;
}

void affiche(int tab[10][10]) {
    for (int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            std::cout<<tab[i][j]<< "\t";
        }
        std::cout << endl;
    }
}

void genarationSuiv(int tab[10][10]) {
    int temp[10][10] = {0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (tab[i][j] == 1)
            {
                if (adjacent(i, j, tab) == 2 || adjacent(i, j, tab) == 3)
                {
                    temp[i][j] = 1;
                } else {
                    temp[i][j] = 0;
                }
            } else
            {
                if (adjacent(i, j, tab) == 3)
                {
                    temp[i][j] = 1;
                } else
                {
                    temp[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tab[i][j] = temp[i][j];
        }
    }
}


int main(){
    int tab[10][10] = {0};
    int temp[10][10] = {0};


    for (int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            tab[i][j] = 0;
        }
    } 
    tab[0][1] = 1;
    tab[1][2] = 1;
    tab[2][0] = 1;
    tab[2][1] = 1;
    tab[2][2] = 1;

    affiche(tab);

    for (int i = 0; i < 20; i++)
    {
        std::cout<< endl;
        std::cout<< endl;

        genarationSuiv(tab);
        affiche(tab);
    }

}