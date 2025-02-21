// Big(O) :
// Quantidade de moedas para troco
// a particularidade dessa comparada a soma de sbublista, é que uma moeda pode ser utilizada mais de uma vez
//  código frankenstein
# include <bits/stdc++.h>
using namespace std;
const int INF = 100000;
std::vector<std::vector<int>> dp;


int qtd_moedas(int a[20], int qtd, int troco){
    int q;
    if(troco == 0)return 1;
    if(qtd == 0) return 0;
    if(dp[qtd-1][troco] != -1) return dp[qtd-1][troco];
    int q1 = qtd_moedas(a, qtd-1, troco-a[qtd-1]);
    int q2 = qtd_moedas(a, qtd-1, troco); 
    int q3 = qtd_moedas(a, qtd-1, troco-1); 
    dp[qtd-1][troco] = q1+q2+q3;
    return q1+q2+q3;
}


int main(){
    // auto_complete();
    int qtd, troco, cont = 0, n;
    cin >> qtd >> troco;
    int a[20];
    dp.resize(qtd+10,std::vector<int>(troco+10,-1));
    for(int i = 0 ; i < qtd ; i ++){
        cin >> a[i];
    }
    qtd_moedas(a, qtd, troco);
    int menor;
    for(int i = troco-1 ; i >= 0 ; i--){
        cout << dp[troco-1][i] << " "; // os valores de dp não estão sendo salvos
        n = dp[troco-1][i];
        for(int k = i-1 ; k >= 0 ; k--){
            if (dp[troco-1][i] > dp[troco-1][k] && dp[troco-1][k] != 0 && dp[troco-1][k] != -1){
                n = dp[troco-1][k];
            }
        }
        if (n != dp[troco-1][i]){
            menor = n;
        }
    }
    cout << menor << endl;

    return 0;
}