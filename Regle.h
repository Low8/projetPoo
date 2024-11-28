

int adjacent(int i, int j,const vector<vector<int>>&vecteurs) {
    int compt = 0;
    for (int k = i - 1; k<=i+1; k++){
        for(int q = j-1; q <= j+1; q++){
            if(k>=0 && k< 10 && q>= 0 && q<10 && !(k==i && q == j)){
                if(vecteurs[k][q] == 1){
                    compt++;
                }
            }
        }
    }
    return compt;
}


void genarationSuiv(vector<vector<int>>&vecteurs) {
    vector<vector<int>>temp(10, vector<int>(10,0));
    for (int i = 0; i < 10; i++)
    {
            for (int j = 0; j < 10; j++)
        {
            if (vecteurs[i][j] == 1)
            {
                if (adjacent(i, j, vecteurs) == 2 || adjacent(i, j, vecteurs) == 3)
                {
                    temp[i][j] = 1;
                } else {
                    temp[i][j] = 0;
                }
            } else
            {
                if (adjacent(i, j, vecteurs) == 3)
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
            vecteurs[i][j] = temp[i][j];
        }
    }
}