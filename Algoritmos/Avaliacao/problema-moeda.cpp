/*
Um sistema monetário é composto de C moedas, cada uma com um valor Ci. Dado um valor V, determine de quantas formas distintas e ordenadas é possível obter o valor V. Exemplo: Um sistema com 3 moedas C = {2, 3, 5} possui 3 formas diferentes de obter o valor 9.
*/
#include <bits/stdc++.h>
using namespace std;

int moedas_soma(int v, std::vector<int> & moedas, int index){
    if(v == 0) return 1;
    if(v < 0) return 0;
    int m1 = 0;
    for(int i = moedas.size()-1; i >= index ; i--){
        m1 =  m1 + moedas_soma(v - moedas[i], moedas, i);
        
    }
    return m1;
}

int main(){
    int qtd, v;
    cin >> qtd >> v;
    std::vector<int> moedas(qtd);

    for(int i = 0 ; i < qtd ; i++)
        cin >> moedas[i];

    int qtd_somas = 0;
    std::sort(moedas.begin(), moedas.end(), std::greater<int>());
    // for(int i = moedas.size() - 1; i >= 0 ; i--){
    //     qtd_somas += moedas_soma(v, moedas, i);
    //     break;
    // }


    cout << moedas_soma(v, moedas, 0) << endl;
    return 0;
}
