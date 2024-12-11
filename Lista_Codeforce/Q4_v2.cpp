// Complexidade : O(n²)

# include <iostream>
# include <algorithm>
using namespace std;
 
// versão mais proxima do codigo certo.

int main(){
    int n, cont = 0, cont2 = 0;
    cin >> n;
    int fita[n];
    int fitas_coloridas[n];
    int i = 0;
    int n2 = n;

    // adicionar os valores a fita
    for (i = 0 ; i < n ; i++){
        cin >> fita[i];
    }
    // colocar um valor alto como "comparador"
    for (i = 0 ; i < n ; i++){
        fitas_coloridas[i] = 100;
    }
    // Se a fita não tiver um quadrado zero então o contador será igual ao tamanho da fita
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
                    if (fita[k-1] != 0){ // verificar se o valor anterior não é igual a 0
                        cont += 1;
                        if (fitas_coloridas[k-1] == 100){ // verifica 
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
                        if (fitas_coloridas[k+1] == 100){
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