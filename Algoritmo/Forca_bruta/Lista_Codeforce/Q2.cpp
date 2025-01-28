// Calçada imperial - Olimpíada Brasileira de Informática 2019
// Complexidade : 
# include <iostream> 
using namespace std;



int main (){
    int n;
    int cont = 0;
    cin >> n;
    int seguencia[n];
    int posicao[n];
    int escolhidos[n];

    for (int i = 0 ; i < n ; i++){
        cin >> seguencia[i];
    }

    for (int i = 0 ; i < n ; i++){
        posicao[i] = 0;
    }

    if (n == 1) posicao[0] = 1;
    else{
        for (int i = 0 ; i < n ; i++){
            for (int k = i+1 ; k < n ; k++){
                if (seguencia[i] == seguencia[k]){
                    if (k == i+1){
                        break;
                    }else{
                        for (int l = 0 ; l< n ; l++){
                            if (seguencia[i] == escolhidos[l]){
                                cont = 1;
                            }
                        }
                        if (cont == 0){
                            posicao[i] = i;
                            posicao[i+1] = k;
                            escolhidos[i] = seguencia[i];
                            cont = 0;
                            cout << i << " " << k << endl;
                        }
                    }
                }
            }
        }
    }
    for(int i = 1 ; i < n ; i++){
        cout << posicao[i]<< " ";
    }
     cout << endl;
}