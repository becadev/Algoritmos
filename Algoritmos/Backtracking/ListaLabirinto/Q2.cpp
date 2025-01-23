# include <iostream> 
using namespace std;

int labirinto_bt(int labirinto[7][7], int linha , int coluna, int l, int c){
    if(c == -1 || l == -1 || c == coluna || l == linha || labirinto[l][c] != 0)
        return 0;
    if(l == linha-1 && c== coluna-1) // posições válidas
        return 1;
    labirinto[l][c] = 9;
    int ans = labirinto_bt(labirinto, linha, coluna, l, c+1) + labirinto_bt(labirinto, linha, coluna, l, c-1) + 
    labirinto_bt(labirinto, linha, coluna, l+1, c) + labirinto_bt(labirinto, linha, coluna, l-1, c);
    labirinto[l][c] = 0;
    return ans;
}
int main(){
    int linha, coluna, labirinto[7][7];
    cin >> linha >> coluna;
    for(int i = 0 ; i < linha ; i++)
        for(int j = 0 ; j < coluna ; j++)
            cin >> labirinto[i][j];
    cout << labirinto_bt(labirinto, linha, coluna, 0, 0) << endl;
    return 0;
}