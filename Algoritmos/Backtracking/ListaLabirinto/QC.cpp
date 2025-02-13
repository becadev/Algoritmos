// Começando do topo
# include <iostream> 
# include <algorithm>
using namespace std;
const int INF = 1000000;

int menor_degrau(int escadaria[20][20], int l, int c, int topo, int laterais){
    if(laterais <= c || topo <= l || 0 > c || 0 > l ) // para não sair dos limites da matriz
        return INF;
    if(l == topo-1) // chegou ao topo
        return escadaria[l][c];

    int c1 = menor_degrau(escadaria, l+1, c, topo, laterais);   // para baixo
    int c2 = menor_degrau(escadaria, l+1, c+1, topo, laterais); // para baixo a direita
    int c3 = menor_degrau(escadaria, l+1, c-1, topo, laterais);  // para baixo a esquerda
    
    return (min({c1,c2,c3})) + escadaria[l][c];
}

int main(){
    int n, m, escadaria[20][20];
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> escadaria[i][j];
    int ans = INF;
    for(int i = 0 ; i <  m ; i++){
        ans = min({ans, menor_degrau(escadaria, 0, i, n, m)});
    }
    cout << ans << endl;
    return 0;
}

