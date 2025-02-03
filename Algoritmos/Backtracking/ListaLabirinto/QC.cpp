// Desempenho O(n^2)
# include <iostream> 
# include <algorithm>
using namespace std;

// acima, acima para esquerda e acima para direita
// vai ter que somar a qtd de degrau dos caminhos que passou
// possibilidades de caminhos: (n * m) * 3

int labirinto_r(int labirinto[16][16], int linha , int coluna, int l, int c){
    if(c <= -1 || l <= -1 || c >= coluna || l >= linha || labirinto[l][c] < 0)
        return 0;
    if(l == linha-1) // chegou ao topo
        return labirinto[l][c];
    int degraus_antes = labirinto[l][c]; 
    labirinto[l][c] = -1;
    int c1 = labirinto_r(labirinto, linha, coluna, l+1, c);   // para cima
    int c2 = labirinto_r(labirinto, linha, coluna, l+1, c+1); // para cima a direita
    int c3 = labirinto_r(labirinto, linha, coluna, l+1, c-1); // para cima a esquerda
    labirinto[l][c] = degraus_antes;
    
    int menor_caminho = std::min({c1,c2,c3});
    return menor_caminho;
}
int labirinto_(int labirinto[16][16], int linha , int coluna){
    int x = labirinto_r(labirinto, linha , coluna, 0, 0);
    return x;
}


int main(){
    int n, m, labirinto[16][16];
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> labirinto[i][j];
    cout << labirinto_(labirinto, n, m) << endl;
    return 0;
}
