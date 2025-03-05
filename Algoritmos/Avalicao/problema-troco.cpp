/*
*/
# include <bits/stdc++.h>
using namespace std;
std::vector<int> dp;
int INF = 1000000;

// int troco_pd(std::vector<int> &moedas, int troco){ // Recursão memorization (Top-donw)
//     if(troco == 0) return 0;
//     if(troco < 0) return INF;
//     if(dp[troco] != -1) return dp[troco]; // já foi calculado
//     int ans = INF;
//     for(int i = moedas.size()-1 ; i >= 0 ; i--){ // vai começar do maior, pois o vector está ordenado
//         ans = min(ans,1+troco_pd(moedas, troco-moedas[i]));
//     }
//     return dp[troco] = ans;
// }

int minimo_moedas_troco(std::vector<int> &moedas, int troco){ // Recursão sem memorization
    if(troco == 0) return 0;
    if(troco < 0) return INF;
    int ans = INF;
    for(int i = moedas.size()-1 ; i >= 0 ; i--){ 
        ans = min(ans, 1+troco_pd(moedas, troco - moedas[i]));
    }
    return ans;
}

    // 0 1 2 3 4 5 6 7
//  1  0   
//  3  
//  4
//  5
// int troco_pd(std::vector<int> &moedas, int troco){ // Programação dinâmica (Bottom-up)
//     dp[0] = 0; 
//     for(int i = 1 ; i <= troco ; i++){ // colunas da tabela (valores)
//         for(int k = 0; k < moedas.size() ; k++){// linhas da tabela (moedas)
//             if(i - moedas[k] >= 0){ // valor-moeda
//                 dp[i] = min(dp[i], 1 + dp[i-moedas[k]]); // min(INF, qtd moeda)
//             }
//         }
//     }
//     return dp[troco];
// }


// int troco_gulo(std::vector<int> &moedas,int troco){ // Método guloso
//     int qtd = 0;
//     for(int i = moedas.size()-1 ; i >= 0 ; i--){ // começa da maior moeda
//         while(troco >= moedas[i]){
//             troco -= moedas[i];
//             qtd++; 
//         }
//     }
//     if(troco == 0) return qtd;
//     else return -1;
// }

int main(){
    int troco, qtd;
    cin >> troco>> qtd;
    vector<int> moedas(qtd);
    dp.resize(qtd+10, INF);
    for(int i = 0; i < qtd; i++){
        cin >> moedas[i];
    }
    sort(moedas.begin(), moedas.end());
    // int resposta = troco_gulo(moedas, troco);
    cout << troco_pd(moedas, troco) << endl;
    return 0;
}

/* Exemplo troco = 7 | moedas = [1,2,3,4,5]
   0  1  2  3  4  5  6  7 // TROCO
0  0     a
1        b
3        
4
5                    x    
*/