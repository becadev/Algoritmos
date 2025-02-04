// Desempenho O(n^2)
# include <iostream> 
# include <algorithm>
using namespace std;

// acima, acima para esquerda e acima para direita
// vai ter que somar a qtd de degrau dos caminhos que passou
// possibilidades de caminhos: (n * m) * 3
// como eu faria pra percorrer apenas os elementos da 0 até c (primeira linha da matriz)?
// Antes que ele decida para qual caminho seguir, verificaria qual das possibilidades a é menor
// como que faz para ele retornar o elemento do array ao invés de "1"?
int labirinto_r(int labirinto[16][16], int linha , int coluna, int l, int c, int menor, int atual){
    int caminhos[coluna], c1,c2,c3;
    if(c <= -1 || l <= -1 || c >= coluna || l >= linha) // para não sair dos limites da matriz
        return 0;
    if(l == linha-1) // chegou ao topo
        return labirinto[0][c];
    if (atual <= menor)
        menor = atual;
    
    c1 = labirinto_r(labirinto, linha, coluna, l+1, c, menor, atual);   // para cima
    c2 = labirinto_r(labirinto, linha, coluna, l+1, c+1, menor, atual); // para cima a direita
    c3 = labirinto_r(labirinto, linha, coluna, l+1, c-1,menor, atual);  // para cima a esquerda
    
    

    return menor;
}

int labirinto_(int labirinto[16][16], int linha , int coluna){
    int x = labirinto_r(labirinto, linha , coluna, 0, 0,990, 1000);
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
