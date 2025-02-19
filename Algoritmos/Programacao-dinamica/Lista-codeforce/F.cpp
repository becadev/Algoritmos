// Big(O) : 
// Mochila binária
#include <bits/stdc++.h>
using namespace std;
 
double dp[10000][10000];
 
void auto_complete(){
    for(int i = 0; i < 10000 ; i++){
        for (int k = 0 ; k < 10000 ; k++){
            dp[i][k] = -1;
        }
    }
}
 
struct item{
    int peso;
    double valor;
};
 
double mochila_dp(vector<item> & itens, int next, int p){
    if(next == -1) return 0.00;
    if(dp[next][p] != -1) return dp[next][p];
    double v_com = 0.00, v_sem = 0.00;
    if(p - itens[next].peso >= 0)
        v_com = itens[next].valor + mochila_dp(itens, next-1, p-itens[next].peso); // valor com o item
    v_sem = mochila_dp(itens, next-1, p); // valor sem o item
 
    // Salvando alterações
    if(v_com > v_sem) dp[next][p] = v_com; //se o valor com for o melhor caso, então ele é salvo
    else dp[next][p] = v_sem;
    return dp[next][p]; // retorna o melhor caso
 
}
 
int main(){
    auto_complete();
    int n, p;
    cin >> n >> p;
    vector<item>itens(n);
    for(item & i : itens)
        cin >> i.peso >> i.valor;
    double valor =  mochila_dp(itens, n-1, p);
    cout << fixed << setprecision(2) << valor << endl;
    
    return 0;
}