# include <iostream>
using namespace std;

bool labirinto_bt(int labirinto[20][20], int linha , int coluna, int l, int c){
    if(c == -1 || l == -1 || c == coluna || l == linha || labirinto[l][c] != 0)
        return false;
    if(l == linha-1 && c== coluna-1) // posições válidas
        return true;
    labirinto[l][c] = 9;
    bool ans = labirinto_bt(labirinto, linha, coluna, l, c+1) || labirinto_bt(labirinto, linha, coluna, l, c-1) || 
    labirinto_bt(labirinto, linha, coluna, l+1, c) || labirinto_bt(labirinto, linha, coluna, l-1, c);
    labirinto[l][c] = 0;
    return ans;
}
int main(){
    int linha, coluna;
    cin >> linha >> coluna;
    int labirinto[20][20];
    for(int i = 0 ; i < linha ; i++)
        for(int j = 0 ; j < coluna ; j++)
            cin >> labirinto[i][j];
    if(labirinto_bt(labirinto, linha, coluna, 0, 0))
        cout << 1 << endl;
    else    
        cout << 0 << endl;
    return 0;
}