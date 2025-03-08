/*
Um sistema monetário é composto de C moedas, cada uma com um valor Ci. Dado um valor V, determine de quantas formas distintas e ordenadas é possível obter o valor V. Exemplo: Um sistema com 3 moedas C = {2, 3, 5} possui 3 formas diferentes de obter o valor 9.

Teste 01:
3 9
2 3 5
output: 3

4 6
1 2 3 4
output: 9

3 7
2 4 6
outuput: 0

1 4
2
output: 1
*/
#include <bits/stdc++.h>
using namespace std;

std::vector<std::vector<int>> dp;

int moedas_soma(int v, std::vector<int> & moedas, int index){ // prog dinamica 
    if(v == 0) return 1; 
    if(v < 0) return 0; // inválido
    if(dp[index][v] != -1) return dp[index][v];

    int m1 = 0;
    for(int i = moedas.size()-1; i >= index ; i--){ // v-2, v-3, v-5
        m1 =  m1 + moedas_soma(v - moedas[i], moedas, i);
    }
    return dp[index][v] = m1;
}

int moedas_soma_bt(int v, std::vector<int> & moedas, int index){ // Recursivo
    if(v == 0) return 1;
    if(v < 0) return 0; // inválido
    int m1 = 0;
    for(int i = moedas.size()-1; i >= index ; i--){ // v-2, v-3, v-5
        m1 =  m1 + moedas_soma(v - moedas[i], moedas, i);
    }
    return m1;
}


int main(){
    int qtd, v;
    cin >> qtd >> v;
    std::vector<int> moedas(qtd);
    dp.resize(qtd, std::vector<int>(v+10, -1));
    for(int i = 0 ; i < qtd ; i++)
        cin >> moedas[i];

    int qtd_somas = 0;
    std::sort(moedas.begin(), moedas.end(), std::greater<int>());
    cout << moedas_soma(v, moedas, 0) << endl;
    return 0;
}
