# include <iostream>
# include <algorithm>
using namespace std;
const int INF = 1000;


int labirinto_bt(int lab[20][20], int linha_final, int coluna_final, int linha, int coluna, int l, int c){
    int aux;
    if(l < 0 || l >= linha || c < 0 || c >= coluna || lab[l][c] == -1)
        return INF;
    if(l == linha_final && c == coluna_final){
        return lab[l][c];
    }
    aux = lab[l][c];
    lab[l][c] = -1;
    int c1 = labirinto_bt(lab, linha_final, coluna_final, linha, coluna, l+1, c);
    int c2 = labirinto_bt(lab, linha_final, coluna_final, linha, coluna, l, c+1);
    int c3 = labirinto_bt(lab, linha_final, coluna_final, linha, coluna, l-1, c);
    int c4 = labirinto_bt(lab, linha_final, coluna_final, linha, coluna, l, c-1);
    lab[l][c] = aux;
    int ans = (min({c1,c2,c3,c4}));
    return lab[l][c] + ans;
}

int main(){
    int linha, coluna, inicio1, inicio2, fim1, fim2;
    cin >> linha >> coluna;
    int lab[20][20];

    cin >> inicio1  >> inicio2; // recebe as celulas iniciais
    cin >> fim1 >> fim2; // recebe as celulas finais

    for(int l = 0 ; l < linha; l++){
        for(int c = 0 ; c < coluna ; c++)
            cin >> lab[l][c];
    }
    cout  << labirinto_bt(lab, fim1, fim2, linha, coluna, inicio1, inicio2) << endl;
    return 0;
}