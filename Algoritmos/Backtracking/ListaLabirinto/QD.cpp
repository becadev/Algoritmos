# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int piramide_bt(int pir[20][20],  int l, int c) {
    int caixa = 0;
    if (l == 0)
        return pir[l][c];
    
    for(int i = 0 ; i <= l ; i ++){
        caixa += pir[l][c+i];
    }
    int c1 = piramide_bt(pir, l-1, c);
    int c2 = piramide_bt(pir, l-1, c+1);
    return caixa + min({c1,c2});
}

int piramide(int pir[20][20], int n) {
    return piramide_bt(pir, n-1, 0);
}

int main() {
    int n;
    cin >> n;
    int pir[20][20];
    for(int l = 0 ; l < n ; l++)
        for(int c = 0 ; c < n ; c++)
            cin >>pir[l][c];
    cout << piramide(pir,n) << endl;
    return 0;
}