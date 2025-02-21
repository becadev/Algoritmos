// Big(O) : 
// Ginástica - Maratona SBC 2017
# include <bits/stdc++.h>
using namespace std;

std::vector<std::vector<int>> dp;
// n = maximo (ex: 5)
// m = minimo (ex: 2)

// int ginastica_bt(int t, int m, int n, int k){
//     if(k < m || k > n) return 0; // estão fora dos critérios
//     if(t == 1 ) return 1;

//     int c1 = ginastica_bt(t-1, m, n, k+1) + ginastica_bt(t-1, m, n, k-1);
//     return c1;
// }

/*
     1   2   3
2
3    b
4       a
5    b     x
_______________
     1   2   3
2
3    1
4        2
5    1       2
_______________
     1   2   3
2    b
3    1   a
4    c   2   x
5    1   b   2

_______________
     1   2   3
2    1
3    1   2    
4    1   2   4
5    1   2   2

_______________
     1   2   3
2    1   b
3    1   2   x
4    1   2   4
5    1   2   2

_______________
     1   2   3  |
2    1   1   2  |
3    1   2   3  |
4    1   2   3  |
5    1   1   2  V
             = 10

*/


int ginastica_pd(int t, int m, int n, int k){
    if(k  < m || k > n ) return 0; // estão fora dos critérios
    if(t == 1 ) return 1; // fim dos minutos
    if(dp[k][t] != -1) return dp[k][t]; // já foi calculado
    int c1 = ginastica_pd(t-1, m, n, k+1) + ginastica_pd(t-1, m, n, k-1);
    return dp[k][t] = c1;
}

int main(){
    int t,m,n,qtd = 0;
    cin >> t >> m >> n;
    dp.resize(n+1,std::vector<int>(t+1, -1));
    for(int i = m ; i <= n ; i++){ // vai do min ao max
        // qtd += ginastica_bt(t, m, n, i);
        qtd += ginastica_pd(t, m, n, i);
    }
    cout << qtd << endl;
    return 0;
}