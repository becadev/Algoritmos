// Fita Colorida - F1PJ - OBI 2015
// Complexidade: O(n²)
# include <iostream>
# include <algorithm>
using namespace std;
 
int main(){
    int n, cont = 0, cont2 = 0;
    cin >> n;
    int fita[n];
    int fitas_coloridas[n];
    int i = 0;
 
    for (i = 0 ; i < n ; i++){
        cin >> fita[i];
    }
    for (i = 0 ; i < n ; i++){
        fitas_coloridas[i] = 100;
    }
    for (i = 0 ; i < n ; i++){
        if(fita[i] < 0){
            cont2++;
        }
    }
 
 
    if (cont2 < n){
        for (i = 0 ; i < n ; i++){
            if (fita[i] == 0){
                // Percorrer por decremento 
                for(int k = i; k > 0; k--){
                    if (fita[k-1] != 0){ // k-1 --> pq o fita[k] é zero já que k==i e fita[i]==0
                        cont += 1;
                        if (fitas_coloridas[k-1] == 100 || fitas_coloridas[k-1] > cont){ // verifica se essa posição já foi alterada e tambem se o valor da alteração é maior do que o cont atual´já que a lista é percorrida pelos dois loops(incremento e decremento) , se caso o cont for menor significa que é mais proximo do zero do que a alteração anterior
                            if(cont <= 9){
                                fitas_coloridas[k-1] = cont;
                            }else{
                                fitas_coloridas[k-1] = 9;
                            }
                        }
                    }
                    if (fita[k-1] == 0){
                        break;
                    }
                }
                cont = 0;
                // Percorrer por incremento
                for(int k = i; k < n; k++){
                    if (fita[k+1]!=0){
                        cont+=1;
                        // fitas_coloridas[k+1] = cont;
                        if (fitas_coloridas[k+1] == 100 || fitas_coloridas[k+1] > cont){ // verifica se essa posição já foi alterada e tambem se o valor da alteração é maior do que o cont atual´já que a lista é percorrida pelos dois loops(incremento e decremento) , se caso o cont for menor significa que é mais proximo do zero do que a alteração anterior
                            if (cont <= 9){
                                fitas_coloridas[k+1] = cont;
                            }else{
                                fitas_coloridas[k+1] = 9;
                            }
                            
                        }
                    }
                    if (fita[k+1] == 0){
                        break;
                    }
                }
            fitas_coloridas[i] = 0;
            cont = 0;
            }
        }
    }else{
        for (i = 0 ; i  < n ; i++){
            fitas_coloridas[i] = 9;
        }
    }
    for (int i = 0 ; i < n ; i++){
        cout << fitas_coloridas[i];
            if (i < n-1){
                cout << " ";
            }
    }
    cout << endl;
    return 0;
}