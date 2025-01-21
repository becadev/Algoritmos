#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int total;
    cin >> total;
    int indice, dif;
    vector<int> lista(total);
    int maior = 0;

    for (indice = 0; indice < total; indice +=1){
        cin>>lista[0];
    }
    for (indice = 0; indice < total-2; indice += 2){
        dif = abs(lista[indice - 1] - lista[indice]);
        cout << dif << lista[indice] << lista[indice-1] << endl;
        if (maior < dif){
            maior = dif;
        }
    }
    cout << maior << endl;
}
