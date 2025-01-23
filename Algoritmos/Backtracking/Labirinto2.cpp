# include <iostream>
using namespace std;

bool labitinto_bt(int labirinto[20][20], int linha, int coluna, int l, int c){
    if(l==-1 or c==-1 or l==linha or c == coluna or labirinto[l][c] != 0) return false;
    if (l == linha -1 and c == coluna-1) return true;

    labirinto[l][c] = 9;

   // bool ans = labiritno_bt(labirinto)

}

int main(){

}