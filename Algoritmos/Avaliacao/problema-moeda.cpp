/*
Um sistema monetário é composto de C moedas, cada uma com um valor Ci. Dado um valor V, determine de quantas formas distintas e ordenadas é possível obter o valor V. Exemplo: Um sistema com 3 moedas C = {2, 3, 5} possui 3 formas diferentes de obter o valor 9.
*/
#include <bits/stdc++.h>
using namespace std;

int moedas_soma(int v, std::vector<int> & moedas, int index){
    if(v == 0) return 1;
    // tem que verificar de alguma forma qunado o numero for maior, pq quando ele fez a chamada o loop começa do ultimo index, e como ta ordenada, ent nao sera uma soma crescente. se começar o loop em ordem decrescente?
    if(v < 0) return 0;
    int m1 = 0;
    for(int i = index; i > 0 ; i--){
        m1 =  m1 + moedas_soma(v - moedas[i], moedas, index);
        cout << m1 << " " << i << endl;
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
    for(int i = moedas.size() - 1; i >= 0 ; i--){
        qtd_somas += moedas_soma(v, moedas, i);
        break;
    }

    cout << qtd_somas << endl;
    return 0;
}
