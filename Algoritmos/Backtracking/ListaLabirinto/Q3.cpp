// Desempenho O(n^2)
# include <iostream> 
# include <algorithm>
using namespace std;

int labirinto_r(int labirinto[10][10], int linha , int coluna, int l, int c){
    if(c <= -1 || l <= -1 || c >= coluna || l >= linha || labirinto[l][c] != 0)
        return 1000;
    if(l == linha-1 && c== coluna-1) // posições válidas
        return 1;
    labirinto[l][c] = 9;
    int c1 = labirinto_r(labirinto, linha, coluna, l, c+1);
    int c2 = labirinto_r(labirinto, linha, coluna, l, c-1);
    int c3 = labirinto_r(labirinto, linha, coluna, l+1, c);
    int c4 = labirinto_r(labirinto, linha, coluna, l-1, c);
    labirinto[l][c] = 0;
    int menor_caminho = 1 + std::min({c1,c2,c3,c4});
    return menor_caminho;
}
int labirinto_(int labirinto[10][10], int linha , int coluna){
    int x = labirinto_r(labirinto, linha , coluna, 0, 0);
    if(x>=1000) 
        return -1;
    return x;
}


int main(){
    int linha, coluna, labirinto[10][10];
    cin >> linha >> coluna;
    for(int i = 0 ; i < linha ; i++)
        for(int j = 0 ; j < coluna ; j++)
            cin >> labirinto[i][j];
    cout << labirinto_(labirinto, linha, coluna) << endl;
    return 0;
}
